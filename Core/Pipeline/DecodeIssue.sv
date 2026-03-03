import Configuration::*;
import Payloads::*;
import Enumerations::*;

module DecodeIssue (

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
    input logic badData,

    // Issue Outputs
    output UpperIssuerOperandPayload_ payload1,
    output LowerIssuerOperandPayload_ payload2,

    // ROB Communication
    input logic nextFreeSlots

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

    // Decode Producer 1
    logic illegal1;
    UpperIssuerOperandPayload_ tempPayload1;
    logic [4:0] destinationRegister1;

    Decoder decoder1 (
        .instruction(IR1),
        .programCounter(PC1),
        .payload(tempPayload1),
        .destinationRegister(destinationRegister1),
        .illegal(illegal1)
    );

    // Decode Producer 1
    logic illegal2;
    UpperIssuerOperandPayload_ tempPayload2;
    logic [4:0] destinationRegister2;

    Decoder decoder2 (
        .instruction(IR2),
        .programCounter(PC2),
        .payload(tempPayload2),
        .destinationRegister(destinationRegister2),
        .illegal(illegal2)
    );

    // Issuer Helper Signals
    logic block1;
    logic block2;

    // Issuer Contract Logic
    always_comb begin
        // Zero Initialize
        instructionConsumed1 = 1'b0;
        instructionConsumed2 = 1'b0;
        block1 = 1'b0;
        block2 = 1'b0;
        // Both Instructions Valid
        if (instructionsValid) begin
            // Memory Ops Must Always Issue in Slot 0
            if (tempPayload2.memoryOperation != MEM_NONE) begin
                block2 = 1'b1;
            end
            // Block WAW To Simplify Forwarding/RST Logic, Can Be Relaxed Later
            if (destinationRegister1 == destinationRegister2) begin
                block2 = 1'b1;
            end
            // Block Slot 0 + Slot 1 Dependencies, Can Be Relaxed with Bypass Logic Later
            if ((tempPayload1.sourceRegister1 == destinationRegister2 && destinationRegister2 != 5'd0) || 
            (tempPayload1.sourceRegister2 == destinationRegister2 && destinationRegister2 != 5'd0) ||
            (tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) ||
            (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0)) begin
                block2 = 1'b1;
            end
            // Block Dual Redirects
            if ((tempPayload1.branchType != BR_NONE || tempPayload1.jumpType != JUMP_NONE) && 
                (tempPayload2.branchType != BR_NONE || tempPayload2.jumpType != JUMP_NONE)) begin
                block2 = 1'b1;
            end
            // Block Issue on Bad Fetch
            if (internalBadData) begin
                block2 = 1'd1;
            end
            // ROB Capacity Gating
            if (nextFreeSlots == 5'd1) begin
                block2 = 1'b1;
            end else if (nextFreeSlots == 5'd0) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end

        end
    end

endmodule

// ============ ISSUER MUST ============
// Deposit Rd and PC to ROB
// On No WB, hardwire rd=x0

// ============ ISSUE RULES ============
// Memory Queue must have space for new memory ops
// No issues on dependencies on loads that are !ready
// Assess Memory Queue fullness as x-1 to accomindate in flight
// slot 1 can never be to an non-ready rd MAYBE?????
// neither slot can be to an rd that is being loaded.

// must impliment ownerTags in RST to ensure the last two rules hold
// no slot 1 slot 2 dependencies is VERY restrictive and kills IPC
// potential solutions:
// weird data level check on carry chain length and forward if short
// fix this later after timing analysis. more room if execute is short
// gate by op type to determine speed?