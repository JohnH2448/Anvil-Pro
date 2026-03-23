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
    input logic [4:0] nextFreeSlots,

    // Read From RST
    output logic [4:0] upperIssuerRegister1,
    output logic [4:0] upperIssuerRegister2,
    output logic [4:0] lowerIssuerRegister1,
    output logic [4:0] lowerIssuerRegister2,

    // From RST
    input logic upperInFlightLoad1,
    input logic upperInFlightLoad2,
    input logic lowerInFlightLoad1,
    input logic lowerInFlightLoad2,
    input logic destRegLoad1,
    input logic destRegLoad2,

    // Write To RST
    output logic [4:0] rstDestinationRegister1,
    output logic [4:0] rstDestinationRegister2,
    output logic isLoad1,
    output logic isLoad2,
    output logic [4:0] ageTag1,
    output logic [4:0] ageTag2,

    // Instruction Packets to ROB
    output IssuedIntruction_ instructionPacket1,
    output IssuedIntruction_ instructionPacket2

);

    // Generated Age Tags
    logic [4:0] issue1AgeTag;
    logic [4:0] issue2AgeTag;

    // Decode Producer 2
    logic illegal2;
    UpperIssuerOperandPayload_ tempPayload2;
    logic [4:0] destinationRegister2;

    // Decode Producer 1
    logic illegal1;
    UpperIssuerOperandPayload_ tempPayload1;
    logic [4:0] destinationRegister1;

    // To RST
    // Upper Issue Slot Source Registers + rd
    assign upperIssuerRegister1 = tempPayload1.sourceRegister1;
    assign upperIssuerRegister2 = tempPayload1.sourceRegister2;
    assign rstDestinationRegister1 = destinationRegister1;

    // Lower Issue Slot Source Registers + rd
    assign lowerIssuerRegister1 = tempPayload2.sourceRegister1;
    assign lowerIssuerRegister2 = tempPayload2.sourceRegister2;
    assign rstDestinationRegister2 = destinationRegister2;

    // Extra Issuer Data to RST
    assign isLoad1 = tempPayload1.memoryOperation == MEM_LOAD;
    assign isLoad2 = tempPayload2.memoryOperation == MEM_LOAD;
    assign ageTag1 = issue1AgeTag;
    assign ageTag2 = issue2AgeTag;
    
    // Final Payloads Passed to OS
    UpperIssuerOperandPayload_ finalUpperPayload;
    LowerIssuerOperandPayload_ finalLowerPayload;

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

    Decoder decoder1 (
        .instruction(IR1),
        .programCounter(PC1),
        .payload(tempPayload1),
        .destinationRegister(destinationRegister1),
        .illegal(illegal1)
    );

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
    logic [1:0] bypassEnable;

    // Issuer Contract Logic
    always_comb begin
        // Zero Initialize
        block1 = 1'b0;
        block2 = 1'b0;
        bypassEnable = 2'b00;
        // Both Instructions Valid
        if (instructionsValid) begin
            // FOR TESTING ONLY
            if (IR1 == 32'hdead_beef || IR2 == 32'hdead_beef) begin
                block1 = 1'b0;
                block2 = 1'b0;
            end
            // Memory Ops Must Always Issue in Slot 0
            if (tempPayload2.memoryOperation != MEM_NONE) begin
                block2 = 1'b1;
            end
            // Block WAW To Simplify Forwarding/RST Logic, Can Be Relaxed Later
            if (destinationRegister1 == destinationRegister2) begin
                block2 = 1'b1; 
            end
            // Slot 0/1 Dependency Param Gated Generator
            if (!crossLaneExBypass) begin : BYPASS_PARAM
                // Block Slot 0 + Slot 1 Dependencies
                if ((tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) ||
                (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0)) begin
                    block2 = 1'b1;
                end
            end else begin
                // Ex/Ex Bypass Bits
                if (tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) begin
                    bypassEnable[0] = 1'd1;
                end
                if (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0) begin
                    bypassEnable[1] = 1'd1;
                end
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
            // Block Issue On Unready Load rs's or rd's. Calculated in RST
            if (upperInFlightLoad1 || upperInFlightLoad2 || destRegLoad1) begin
                block1 = 1'b1;
            end
            if (lowerInFlightLoad1 || lowerInFlightLoad2 || destRegLoad2) begin
                block2 = 1'b1;
            end
            // Block Issue On Backwards Slot 0/1 Dependency to Fix RST Ownership Problems
            if ((tempPayload1.sourceRegister1 == destinationRegister2 && destinationRegister2 != 5'd0) ||
                (tempPayload1.sourceRegister2 == destinationRegister2 && destinationRegister2 != 5'd0)) begin
                block2 = 1'b1;
                end
        end else begin
            block1 = 1'b1;
            block2 = 1'b1;
        end
    end

    // Final Payload Assignment
    always_comb begin
        // Instruction Consumption Descision
        instructionConsumed1 = 1'd0;
        instructionConsumed2 = 1'd0;
        if (!block1 && !block2) begin
            instructionConsumed1 = 1'd1;
            instructionConsumed2 = 1'd1;
        end else if (!block1) begin
            instructionConsumed1 = 1'd1;
        end
        // Payload Construction
        if (instructionConsumed1 && instructionConsumed2) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.ageTag = issue1AgeTag;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload Splice
            finalLowerPayload.programCounter = tempPayload2.programCounter;
            finalLowerPayload.destinationRegister = destinationRegister2;
            finalLowerPayload.sourceRegister1 = tempPayload2.sourceRegister1;
            finalLowerPayload.sourceRegister2 = tempPayload2.sourceRegister2;
            finalLowerPayload.immediate = tempPayload2.immediate;
            finalLowerPayload.aluSource = tempPayload2.aluSource;
            finalLowerPayload.branchType = tempPayload2.branchType;
            finalLowerPayload.aluOperation = tempPayload2.aluOperation;
            finalLowerPayload.jumpType = tempPayload2.jumpType;
            finalLowerPayload.ageTag = issue2AgeTag;
            finalLowerPayload.bypassEnable = bypassEnable;
            finalLowerPayload.valid = 1'd1;
        end else if (instructionConsumed1) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.ageTag = issue1AgeTag;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload
            finalLowerPayload = '0;
        end else begin
            // Invalidate Both
            finalUpperPayload = '0;
            finalLowerPayload = '0;
        end
    end

    // Age Tag Generation
    always_ff @(posedge clock) begin
        if (reset) begin
            issue1AgeTag <= '0;
            issue2AgeTag <= 5'd1;
        end else begin
            if (instructionConsumed1 && instructionConsumed2) begin
                issue1AgeTag <= issue1AgeTag + 5'd2;
                issue2AgeTag <= issue2AgeTag + 5'd2;
            end else if (instructionConsumed1) begin
                issue1AgeTag <= issue1AgeTag + 5'd1;
                issue2AgeTag <= issue2AgeTag + 5'd1;
            end
        end
    end

    // Instruction Packet Construction
    always_comb begin
        instructionPacket1 = '0;
        instructionPacket2 = '0;
        if (instructionConsumed1 && instructionConsumed2) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = issue1AgeTag;
            instructionPacket1.isStore = (tempPayload1.memoryOperation == MEM_STORE);
            instructionPacket1.confirm = 1'd1;
            // Instruction 2 to ROB
            instructionPacket2.programCounter = PC2;
            instructionPacket2.destinationRegister = destinationRegister2;
            instructionPacket2.ageTag = issue2AgeTag;
            instructionPacket2.isStore = (tempPayload2.memoryOperation == MEM_STORE);
            instructionPacket2.confirm = 1'd1;
        end else if (instructionConsumed1) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = issue1AgeTag;
            instructionPacket1.isStore = (tempPayload1.memoryOperation == MEM_STORE);
            instructionPacket1.confirm = 1'd1;
        end
    end

    // Instruction Payload Assignment
    always_ff @(posedge clock) begin
        payload1 <= finalUpperPayload;
        payload2 <= finalLowerPayload;
    end

endmodule

// ============ ISSUER MUST ============
// Deposit Rd and PC to ROB
// On No WB, hardwire rd=x0

// ============ ISSUE RULES ============
// Memory Queue must have space for new memory ops
// Assess Memory Queue fullness as x-1 to accomindate in flight
// slot 1 can never be to an non-ready rd MAYBE?????
// One CSR in pipe at a time

// no slot 1 slot 2 dependencies is VERY restrictive and kills IPC
// potential solutions:
// weird data level check on carry chain length and forward if short
// fix this later after timing analysis. more room if execute is short
// gate by op type to determine speed?