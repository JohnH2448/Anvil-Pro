import Configuration::*;
import Payloads::*;
import Enumerations::*;

module DecodeIssue (

    // Test Inputs
    input logic assert1,
    input logic assert2,

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,
    input logic [31:0] redirectVector,

    // Instruction Inputs
    input logic [31:0] instruction1,
    input logic [31:0] instruction2,

    // Window Communication
    output logic instructionConsumed1,
    output logic instructionConsumed2,
    output logic [31:0] requestPC1,
    output logic [31:0] requestPC2,
    input logic [31:0] programCounter,
    input logic badData

);

    // Registered Instructions and PCs for Decode
    logic [31:0] IR1;
    logic [31:0] IR2;
    logic [31:0] PC1;
    logic [31:0] PC2;

    // Vaidity of Instructions in Decode
    logic instructionsValid;

    // Saturating Counter for Post Redirect Use
    logic postRedirectCounter;

    // Internal Bad Data
    logic internalBadData;

    always_ff @(posedge clock) begin
        if (reset || redirect) begin
            instructionsValid <= 1'b0;
            postRedirectCounter <= 1'b0;
            // Can Be Removed
            IR1 <= 32'hdead_beef;
            IR2 <= 32'hdead_beef;
        end else begin
            if (postRedirectCounter) begin
                // Validate Payload
                instructionsValid <= 1'b1;
                // Relatch Fresh Presents Every Valid Cycle
                IR1 <= instruction1;
                IR2 <= instruction2;
                PC1 <= requestPC1;
                PC2 <= requestPC2;
                internalBadData <= badData;
            end else begin
                // Incriment Post Redirect Counter
                postRedirectCounter <= postRedirectCounter + 1'b1;
            end
        end
    end

    // Request PC Speculation Logic
    always_comb begin
        if (instructionsValid == 1'd1) begin
            if (instructionConsumed1 && instructionConsumed2) begin
                requestPC1 = programCounter + 32'd8;
                requestPC2 = programCounter + 32'd12;
            end else if (instructionConsumed1) begin
                requestPC1 = programCounter + 32'd4;
                requestPC2 = programCounter + 32'd8;
            end else begin
                requestPC1 = programCounter;
                requestPC2 = programCounter + 32'd4;
            end
        end else begin
            requestPC1 = programCounter;
            requestPC2 = programCounter + 32'd4;
        end
    end

    // Test Assertions
    always_comb begin
        if (instructionsValid) begin
            if (assert1 && assert2) begin
                if (internalBadData) begin
                    instructionConsumed1 = 1'b1;
                    instructionConsumed2 = 1'b0;
                end else begin
                    instructionConsumed1 = 1'b1;
                    instructionConsumed2 = 1'b1;
                end
            end else if (assert1) begin
                instructionConsumed1 = 1'b1;
                instructionConsumed2 = 1'b0;
            end else begin
                instructionConsumed1 = 1'b0;
                instructionConsumed2 = 1'b0;
            end
        end
    end

    // Test Prints
    always_ff @(posedge clock) begin
        if (instructionConsumed1 && instructionConsumed2) begin
            $display("Issued %h, PC: %h\nIssued %h, PC: %h", IR1, PC1, IR2, PC2);
        end else if (instructionConsumed1) begin
            $display("Issued %h, PC: %h", IR1, PC1);
        end
    end

endmodule

// ============ ISSUER MUST ============
// Deposit Rd and PC to ROB
// On No WB, hardwire rd=x0

// ============ ISSUE RULES ============
// Slot 0 is always older
// Memory must flow through slot 0
// Memory Queue must have space for new memory ops
// No issues on dependencies on loads that are !ready
// ROB must have space for new instructions
// No slot 0 + slot 1 dependencies
// Respect garbage data flag from fetch and refuse instruction 2 issuance
// No dual redirect issues
// Block WAW to prevent forwarding complications
// Assess Memory Queue fullness as x-1 to accomindate in flight

// no slot 1 slot 2 dependencies is VERY restrictive and kills IPC
// potential solutions:
// rd=0 bypass
// weird data level check on carry chain length and forward if short
// fix this later after timing analysis. more room if execute is short
// gate by op type to determine speed?