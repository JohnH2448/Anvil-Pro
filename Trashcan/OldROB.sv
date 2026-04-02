import Configuration::*;
import Payloads::*;
import Enumerations::*;

module OldReorderBuffer (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,

    // Redirect Metadata
    input logic redirect1,
    input logic redirect2,

    // Instruction Inputs
    input InputInstruction_ completedMemory,
    input InputInstruction_ completedInstruction1,
    input InputInstruction_ completedInstruction2,
    input IssuedIntruction_ issuedInstruction1,
    input IssuedIntruction_ issuedInstruction2,

    // Writeback Output
    output RetiredInstruction_ resolvedInstruction1,
    output RetiredInstruction_ resolvedInstruction2,
    output logic triggerStore,

    // Issuer Control Signals For Decisions
    output logic [4:0] nextFreeSlots,

    // Store ACK
    input logic storeACK,

    // Quad Index Forward Requests From OS
    input logic [4:0] upperTagIndex1,
    input logic [4:0] upperTagIndex2,
    input logic [4:0] lowerTagIndex1,
    input logic [4:0] lowerTagIndex2,

    // Forward Outputs
    output logic [31:0] upperForward1,
    output logic [31:0] upperForward2,
    output logic [31:0] lowerForward1,
    output logic [31:0] lowerForward2
);

    // Retired Instructions Per Cycle
    logic [1:0] retireCount;
    integer debugCycle;

    // Full Buffer Declaration
    QueueEntry_ reorderBuffer [0:15];

    // Free Slots
    logic [4:0] freeSlots;
    assign nextFreeSlots = freeSlots + {3'b000, retireCount};

    // Youngest Open Slot
    logic [4:0] nextTailPointer;
    assign nextTailPointer = 5'd16 - nextFreeSlots;

    // Free Slots After Redirect 
    logic [4:0] redirectFreeSlots;
    logic [4:0] redirectNextTailPointer;
    assign redirectFreeSlots = 5'd15 - redirectNextTailPointer;

    // Next Free Slots Signals
    logic [4:0] calculatedNextFreeSlots;
    assign calculatedNextFreeSlots = (redirect ? redirectFreeSlots : freeSlots) + {3'b000, retireCount} - 
        {4'b0000, issuedInstruction1.confirm} - {4'b0000, issuedInstruction2.confirm};

    always_ff @(posedge clock) begin
        // Reset Clear
        if (reset) begin
            debugCycle <= 0;
            for (int i=0; i<16; i++) begin
                reorderBuffer[i] <= '0;
            end
            freeSlots <= 5'd16;
        end else begin
            debugCycle <= debugCycle + 1;
            // Queue Steps
            unique case (retireCount)
                // No Retirement
                2'b00: begin

                end
                // Single Retirement
                2'b01: begin
                    // Shift Buffer
                    for (int i=0; i<15; i++) begin
                        reorderBuffer[i] <= reorderBuffer[i+1];
                    end
                end
                // Dual Retirement
                2'b10: begin
                    // Shift Buffer
                    for (int i=0; i<14; i++) begin
                        reorderBuffer[i] <= reorderBuffer[i+2];
                    end
                end
            endcase
            // Accept Instructions
            if (!redirect) begin
                if (issuedInstruction1.confirm) begin
                    reorderBuffer[nextTailPointer].programCounter <= issuedInstruction1.programCounter;
                    reorderBuffer[nextTailPointer].destinationRegister <= issuedInstruction1.destinationRegister;
                    reorderBuffer[nextTailPointer].ageTag <= issuedInstruction1.ageTag;
                    reorderBuffer[nextTailPointer].isStore <= issuedInstruction1.isStore;
                    reorderBuffer[nextTailPointer].completed <= 1'b0;
                end
                if (issuedInstruction2.confirm) begin
                    reorderBuffer[nextTailPointer + 5'd1].programCounter <= issuedInstruction2.programCounter;
                    reorderBuffer[nextTailPointer + 5'd1].destinationRegister <= issuedInstruction2.destinationRegister;
                    reorderBuffer[nextTailPointer + 5'd1].ageTag <= issuedInstruction2.ageTag;
                    reorderBuffer[nextTailPointer + 5'd1].isStore <= issuedInstruction2.isStore;
                    reorderBuffer[nextTailPointer + 5'd1].completed <= 1'b0;
                end
            end
            // Update Available Free Slots
            freeSlots <= calculatedNextFreeSlots;
        end
    end

    // Instruction Resolution
    logic [4:0] entries;
    assign entries = 5'd16 - freeSlots;
    always_comb begin
        resolvedInstruction1 = '0;
        resolvedInstruction2 = '0;
        retireCount = 2'b00;
        triggerStore = 1'd0;
        if ((entries > 5'd1) && (reorderBuffer[0].completed || reorderBuffer[0].destinationRegister == 5'd0)
        && (reorderBuffer[1].completed || reorderBuffer[1].destinationRegister == 5'd0)) begin
            // Commit Slot 0 and 1
            retireCount = 2'b10;
            if ((reorderBuffer[0].destinationRegister != 5'd0) && (reorderBuffer[0].destinationRegister == reorderBuffer[1].destinationRegister)) begin
                // Packet 1 Gets Packet 2 Data and Drops Packet 2 On Conflict
                resolvedInstruction1.ageTag = reorderBuffer[1].ageTag;
                resolvedInstruction1.instructionResult = reorderBuffer[1].instructionResult;
                resolvedInstruction1.destinationRegister = reorderBuffer[1].destinationRegister;
                resolvedInstruction1.valid = 1'd1; 
            end else begin
                // Slot 0 Packet
                if (reorderBuffer[0].destinationRegister != 5'd0) begin
                    resolvedInstruction1.ageTag = reorderBuffer[0].ageTag;
                    resolvedInstruction1.instructionResult = reorderBuffer[0].instructionResult;
                    resolvedInstruction1.destinationRegister = reorderBuffer[0].destinationRegister;
                    resolvedInstruction1.valid = 1'd1; 
                end
                // Slot 1 Packet
                if (reorderBuffer[1].destinationRegister != 5'd0) begin
                    resolvedInstruction2.ageTag = reorderBuffer[1].ageTag;
                    resolvedInstruction2.instructionResult = reorderBuffer[1].instructionResult;
                    resolvedInstruction2.destinationRegister = reorderBuffer[1].destinationRegister;
                    resolvedInstruction2.valid = 1'd1; 
                end
            end
        end else if ((entries > 5'd0) && (reorderBuffer[0].completed || reorderBuffer[0].destinationRegister == 5'd0)) begin
            // Commit Slot 0
            retireCount = 2'b01;
            // Slot 0 Packet
            if (reorderBuffer[0].destinationRegister != 5'd0) begin
                resolvedInstruction1.ageTag = reorderBuffer[0].ageTag;
                resolvedInstruction1.instructionResult = reorderBuffer[0].instructionResult;
                resolvedInstruction1.destinationRegister = reorderBuffer[0].destinationRegister;
                resolvedInstruction1.valid = 1'd1; 
            end
        end else if ((entries > 5'd0) && reorderBuffer[0].isStore) begin
            // Launch Store
            triggerStore = 1'd1;
        end
    end

    // Store ACK FSM
    logic outgoingStore;
    always_ff @(posedge clock) begin
        if (reset) begin
            outgoingStore <= 1'd0;
        end else begin
            if (triggerStore && !outgoingStore) begin
                outgoingStore <= 1'd1;
            end
            if (outgoingStore && storeACK) begin
                outgoingStore <= 1'd0;
                reorderBuffer[0].completed <= 1'd1;
            end
        end
    end

    // Index Grid Builder for Forwarding
    logic forwardGrid [0:15][0:5];
    logic [4:0] ageVector;
    always_comb begin
        for (int row=0; row<6; row++) begin
            // Select Correct Age Vector
            unique case (row)
                0: ageVector = upperTagIndex1;
                1: ageVector = upperTagIndex2;
                2: ageVector = lowerTagIndex1;
                3: ageVector = lowerTagIndex2;
                4: ageVector = completedInstruction1.ageTag;
                5: ageVector = completedInstruction2.ageTag;
            endcase
            // Loop Over ROB and Build Grid
            for (int index=0; index<16; index++) begin
                forwardGrid[index][row] =
                    (index < int'(entries)) &&
                    (reorderBuffer[index].ageTag == ageVector);
            end
        end
    end

    // Forward Quad Index Unit
    always_comb begin

        upperForward1 = '0;
        upperForward2 = '0;
        lowerForward1 = '0;
        lowerForward2 = '0;

        // Pulls Unique 1 From Each Row and Grabs Value 
        for (int index = 0; index < 16; index++) begin
            if (forwardGrid[index][0]) upperForward1 = reorderBuffer[index].instructionResult;
            if (forwardGrid[index][1]) upperForward2 = reorderBuffer[index].instructionResult;
            if (forwardGrid[index][2]) lowerForward1 = reorderBuffer[index].instructionResult;
            if (forwardGrid[index][3]) lowerForward2 = reorderBuffer[index].instructionResult;
        end

    end

    // Redirect Flush Math
    always_comb begin
        redirectNextTailPointer = '0;
        // Pulls Index at Age Tag of Exception 
        if (redirect) begin
            for (logic [4:0] index = 5'd0; index < 5'd16; index++) begin
                if (redirect1) begin
                    if (forwardGrid[index][4]) redirectNextTailPointer = index;
                end else if (redirect2) begin
                    if (forwardGrid[index][5]) redirectNextTailPointer = index;
                end
            end
        end
    end

    // Write Ready Data to Correct Next Slot 
    logic [4:0] nextOffsetIndex;
    assign nextOffsetIndex = {3'b000, retireCount};
    always_ff @(posedge clock) begin
        for (logic [4:0] index = 5'd0; index < 5'd16; index++) begin
            if (completedInstruction1.accept && forwardGrid[index][4]) begin
                reorderBuffer[index - nextOffsetIndex].instructionResult <= completedInstruction1.instructionResult;
                reorderBuffer[index - nextOffsetIndex].completed <= 1'd1;
            end
            if (completedInstruction2.accept && forwardGrid[index][5]) begin
                reorderBuffer[index - nextOffsetIndex].instructionResult <= completedInstruction2.instructionResult;
                reorderBuffer[index - nextOffsetIndex].completed <= 1'd1;
            end
        end
    end

endmodule

// EX to EX bypass cross stage
// forward else
// mem ops must detect illegal before buffer
// store buffer and forward to in progress loads
// try and be conservative with issue rules
// unified load and store memory queue
// and only then continue to commit more
// store uses completedMemory with rd = 0
// for age tags distance = (B - A) mod ROB_SIZE
// 16 entry rob 4 bit age tag
// all depdendencies can be resolved without stall through forwarding
// except dependency on non ready loads. store "isLoad" in RST and block 
// issue. all other instructions should be able to issue
// ignore all resolved instructions into ROB without a valid bit 
// all backend pipeline instructions should never get invalidated
// from control. Invalidation (ie branch) comes from clearing ROB
// entries corresponding to age tag. Anything "invalid" in pipeline
// should not have a ROB entry allocated. Every entry should have
// a real, permenantly valid corresponding instruction in flight 
// or commited. Goal is no backend stalls ever. stall comes from
// issue refusal. There should be no bubbles corresponding to valid
// entries in ROB. flushing should be rare and specific, no drop-ins.
// On flush, clear ROB entries
// all ROB entries are implicitly valid
// no forwarding from store to loads. not much optimization and complex
// use Dhrystone for IPC estimates
// the only forwarding path should be both EX to both OS assuming no slot0/1 dependenceis
// age tag system so I dont need to actually flush in pipeline
// rst can only clear
