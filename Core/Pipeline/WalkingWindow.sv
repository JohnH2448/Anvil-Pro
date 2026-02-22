import Configuration::*;
import Payloads::*;
import Enumerations::*;

module WalkingWindow (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,
    input logic [31:0] redirectVector,

    // Instruction Inputs
    input logic [127:0] lowFetchData,
    input logic [127:0] highFetchData,

    // Load Address Lines
    output logic [31:0] lowFetchAddress,
    output logic [31:0] highFetchAddress,

    // Decode Communication
    output logic [31:0] instruction1,
    output logic [31:0] instruction2,
    input logic instructionConsumed1,
    input logic instructionConsumed2,

    // Request Addresses
    input logic [31:0] requestPC1,
    input logic [31:0] requestPC2,

    // PC Output for Speculative Requesting in Decode
    output logic [31:0] programCounter,

    // Bad Data Flag
    output logic badData

);

    // Outgoing Addressed Window
    logic [31:0] lastLowWindow;
    logic [31:0] lastHighWindow;

    // Automatic Window Logic
    assign lowFetchAddress = {programCounter[31:4], 4'b0000};
    assign highFetchAddress = lowFetchAddress + {32'd16};

    // PC Control Block
    always_ff @(posedge clock) begin
        if (reset || redirect) begin
            // PC Alteration on External Signal
            programCounter <= reset ? resetVector : redirectVector;
        end else begin
            // Logical PC Incriminting
            if (instructionConsumed1 && instructionConsumed2) begin
                programCounter <= programCounter + 32'd8;
            end else if (instructionConsumed1) begin
                programCounter <= programCounter + 32'd4;
            end
        end
    end

    // Latch Outgoing PC for Correspondance
    always_ff @(posedge clock) begin
        if (reset) begin
            lastLowWindow <= {resetVector[31:4], 4'b0000};
            lastHighWindow <= {resetVector[31:4], 4'b0000} + 32'd16;
        end else if (redirect) begin
            lastLowWindow <= {redirectVector[31:4], 4'b0000};
            lastHighWindow <= {redirectVector[31:4], 4'b0000} + 32'd16;
        end else begin
            lastLowWindow <= lowFetchAddress;
            lastHighWindow <= highFetchAddress;

        end
    end

    // Instruction Assertion
    always_comb begin
        // Can Be Removed
        instruction1 = 32'hdead_beef;
        instruction2 = 32'hdead_beef;
        // Checks if Needed Data is in Lower Window
        if (requestPC1[31:4] == lastLowWindow[31:4]) begin
            unique case (requestPC1[3:2])
                // Presents Instructions to Decode
                2'd0: instruction1 = lowFetchData[31:0];
                2'd1: instruction1 = lowFetchData[63:32];
                2'd2: instruction1 = lowFetchData[95:64];
                2'd3: instruction1 = lowFetchData[127:96];
            endcase
        end
        // Checks if Needed Data is in Lower Window
        if (requestPC2[31:4] == lastLowWindow[31:4]) begin
            // Presents Instructions to Decode
            unique case (requestPC2[3:2])
                2'd0: instruction2 = lowFetchData[31:0];
                2'd1: instruction2 = lowFetchData[63:32];
                2'd2: instruction2 = lowFetchData[95:64];
                2'd3: instruction2 = lowFetchData[127:96];
            endcase
        end
        // Checks if Needed Data is in Upper Window
        if (requestPC1[31:4] == lastHighWindow[31:4]) begin
            // Presents Instructions to Decode
            unique case (requestPC1[3:2])
                2'd0: instruction1 = highFetchData[31:0];
                2'd1: instruction1 = highFetchData[63:32];
                2'd2: instruction1 = highFetchData[95:64];
                2'd3: instruction1 = highFetchData[127:96];
            endcase
        end
        // Checks if Needed Data is in Upper Window
        if (requestPC2[31:4] == lastHighWindow[31:4]) begin
            // Presents Instructions to Decode
            unique case (requestPC2[3:2])
                2'd0: instruction2 = highFetchData[31:0];
                2'd1: instruction2 = highFetchData[63:32];
                2'd2: instruction2 = highFetchData[95:64];
                2'd3: instruction2 = highFetchData[127:96];
            endcase
        end
        // Tells Decode not to Use Instruction2 on Edge Case Bad Data
        if ((requestPC2[31:4] != lastHighWindow[31:4]) && (requestPC2[31:4] != lastLowWindow[31:4])) begin
            badData = 1'd1;
        end else begin
            badData = 1'd0;
        end
    end
endmodule

// Only one case prevents bad data. PC in windows final slot, then two dual consumes
// decode controls pc, prefetch always feeds pc and pc+4
// decode handles consumption. must only consume on valids