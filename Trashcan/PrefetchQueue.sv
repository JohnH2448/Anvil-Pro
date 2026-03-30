import Configuration::*;
import Payloads::*;
import Enumerations::*;

module PrefetchQueue (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,
    input logic [31:0] redirectVector,

    // Instruction Inputs
    input logic [127:0] instructionFetchData,
    input logic instructionFetchDataValid,

    // Read Address Line
    output logic [31:0] alignedAddress,

    // Decode Communication
    output logic [31:0] instruction1,
    output logic instructionReady1,
    output logic [31:0] instruction2,
    output logic instructionReady2,
    input logic instructionConsumed1,
    input logic instructionConsumed2
);

    // Ring Buffer Declaration
    RingBufferEntry_ ringBuffer [0:3];

    // Pointer Declaration
    logic [1:0] headPointer;

    // Cannonical PC
    logic [31:0] programCounter;

    // Internal "Outgoing" Address
    logic [31:0] outgoingAddress;

    // Aligned Address Candidate
    logic [31:0] alignedAddressCandidate;
    logic [31:0] alignedAddressCandidate2;
    assign alignedAddressCandidate = (reset ? {resetVector[31:4], 4'd0} : {redirectVector[31:4], 4'd0});

    // PC Stuff for Comparisons and Assignments
    logic [31:0] basePC;
    assign basePC = reset ? resetVector : redirectVector;
    logic [31:0] entryPC;

    // Instruction Output Assignments
    assign instruction1 = ringBuffer[headPointer].instructionData;
    assign instruction2 = ringBuffer[headPointer + 2'b1].instructionData;
    assign instructionReady1 = ringBuffer[headPointer].ready;
    assign instructionReady2 = ringBuffer[headPointer + 2'b1].ready;

    always_ff @(posedge clock) begin
        // Reset State
        if (reset || redirect) begin
            // Determine PC and Reset Prefetch Window
            programCounter <= basePC;
            alignedAddress <= alignedAddressCandidate;
            // Clear Queue
            headPointer <= '0;
            // Allocate New Entries
            for (int unsigned i = 0; i < 4; i++) begin
                entryPC = basePC + (i << 2);
                ringBuffer[i].ready <= 1'b0;
                ringBuffer[i].instructionData <= '0; // can be removed
                ringBuffer[i].programCounter <= entryPC;
                // Checks if in Window
                ringBuffer[i].requested <= (entryPC[31:4] == alignedAddressCandidate[31:4]);
            end 
        end else begin
            // Latch Outgoing Address
            outgoingAddress <= alignedAddress;
            // Data Fill
            if (instructionFetchDataValid) begin
                for (int j = 0; j < 4; j++) begin
                    if (!ringBuffer[j].ready && (ringBuffer[j].programCounter[31:4] == outgoingAddress[31:4])) begin
                        unique case (ringBuffer[j].programCounter[3:2])
                            2'd0: ringBuffer[j].instructionData <= instructionFetchData[31:0];
                            2'd1: ringBuffer[j].instructionData <= instructionFetchData[63:32];
                            2'd2: ringBuffer[j].instructionData <= instructionFetchData[95:64];
                            2'd3: ringBuffer[j].instructionData <= instructionFetchData[127:96];
                        endcase
                        ringBuffer[j].ready <= 1'b1;
                    end
                end
            end
            // Aligned Address Assignment
            alignedAddress <= alignedAddressCandidate2;
            // Requested Assertions
            for (int unsigned k = 0; k < 4; k++) begin
                // Relative Index of Buffer
                logic [1:0] idx;
                idx = headPointer + k[1:0];
                entryPC = ringBuffer[idx].programCounter;
                // Assigns Requested per Entry
                if (ringBuffer[idx].requested == 1'd0) begin
                    ringBuffer[idx].requested <= (entryPC[31:4] == alignedAddressCandidate2[31:4]);
                end
            end 
            // PC Incriment
            if (instructionConsumed1 && instructionConsumed2) begin
                // Comb PCs for Requested Check
                logic [31:0] pc1;
                logic [31:0] pc2;
                pc1 = programCounter + 32'd20;
                pc2 = programCounter + 32'd16;
                // Both Instructions Accepted
                programCounter <= programCounter + 32'd8;
                headPointer <= headPointer + 2'd2;
                // Allocates New Entries
                ringBuffer[headPointer + 2'd1].ready <= 1'b0;
                ringBuffer[headPointer + 2'd1].instructionData <= 32'b0; // can be removed
                ringBuffer[headPointer + 2'd1].programCounter <= programCounter + 32'd20;
                ringBuffer[headPointer + 2'd1].requested <= (pc1[31:4] == alignedAddressCandidate2[31:4]);
                ringBuffer[headPointer].ready <= 1'b0;
                ringBuffer[headPointer].instructionData <= 32'b0; // can be removed
                ringBuffer[headPointer].programCounter <= programCounter + 32'd16;
                ringBuffer[headPointer].requested <= (pc2[31:4] == alignedAddressCandidate2[31:4]);
            end else if (instructionConsumed1) begin
                // Comb PC for Requested Check
                logic [31:0] pc2;
                pc2 = programCounter + 32'd16;
                // One Instruction Accepted
                programCounter <= programCounter + 32'd4;
                headPointer <= headPointer + 2'd1;
                // Allocates New Entry
                ringBuffer[headPointer].ready <= 1'b0;
                ringBuffer[headPointer].instructionData <= 32'b0;
                ringBuffer[headPointer].programCounter <= programCounter + 32'd16;
                ringBuffer[headPointer].requested <= (pc2[31:4] == alignedAddressCandidate2[31:4]);
            end
        end
    end
    // Next Address Window Calculation
    always_comb begin
        logic [2:0] readyCount;
        readyCount = '0;
        for (int p = 0; p < 4; p++) begin
            if (ringBuffer[headPointer + p[1:0]].requested)
                readyCount++;
            else
                break;
        end
        if (readyCount < 3'b100) begin
            // Fetch Window for Present Entry(s)
            alignedAddressCandidate2 = {ringBuffer[headPointer + readyCount[1:0]].programCounter[31:4], 4'b0000};
        end else begin
            // Fetch Next Window Speculatively
            logic [31:0] pcPlus16;
            pcPlus16 = ringBuffer[headPointer].programCounter + 32'd16;
            alignedAddressCandidate2 = {pcPlus16[31:4], 4'b0000};
        end
    end

    always_ff @(posedge clock) begin
        $strobe("----- PREFETCH QUEUE (logical order) -----");

        $strobe("  [0] PC=%08h INST=%08h REQ=%0d RDY=%0d",
            ringBuffer[headPointer].programCounter,
            ringBuffer[headPointer].instructionData,
            ringBuffer[headPointer].requested,
            ringBuffer[headPointer].ready
        );

        $strobe("  [1] PC=%08h INST=%08h REQ=%0d RDY=%0d",
            ringBuffer[headPointer + 2'd1].programCounter,
            ringBuffer[headPointer + 2'd1].instructionData,
            ringBuffer[headPointer + 2'd1].requested,
            ringBuffer[headPointer + 2'd1].ready
        );

        $strobe("  [2] PC=%08h INST=%08h REQ=%0d RDY=%0d",
            ringBuffer[headPointer + 2'd2].programCounter,
            ringBuffer[headPointer + 2'd2].instructionData,
            ringBuffer[headPointer + 2'd2].requested,
            ringBuffer[headPointer + 2'd2].ready
        );

        $strobe("  [3] PC=%08h INST=%08h REQ=%0d RDY=%0d",
            ringBuffer[headPointer + 2'd3].programCounter,
            ringBuffer[headPointer + 2'd3].instructionData,
            ringBuffer[headPointer + 2'd3].requested,
            ringBuffer[headPointer + 2'd3].ready
        );

        $strobe("  head=%0d  PC=%08h", headPointer, programCounter);
        $strobe("------------------------------------------------\n");
    end



endmodule

// Dual 128-Bit Walking Window is Better and Much Smaller
// decode controls pc, prefetch always feeds pc and pc+4
