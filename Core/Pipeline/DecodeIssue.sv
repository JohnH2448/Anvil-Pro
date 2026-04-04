import Configuration::*;
import Payloads::*;
import Enumerations::*;


module DecodeIssue (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,

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
    input logic [1:0] nextFreeSlots,

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
    output logic [reorderBufferIndexWidth-1:0] ageTag1,
    output logic [reorderBufferIndexWidth-1:0] ageTag2,

    // Instruction Packets to ROB
    output IssuedIntruction_ instructionPacket1,
    output IssuedIntruction_ instructionPacket2,

    // Fresh Tags from ROB
    input logic [reorderBufferIndexWidth-1:0] freeTag1,
    input logic [reorderBufferIndexWidth-1:0] freeTag2

);

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
    assign ageTag1 = freeTag1;
    assign ageTag2 = freeTag2;
    
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
    integer debugCycle;

    // Internal Bad Data
    logic internalBadData;

    always_ff @(posedge clock) begin
        if (reset || redirect) begin
            if (reset) begin
                debugCycle <= 0;
            end
            instructionsValid <= 1'b0;
            postRedirectCounter <= 1'b0;
            // Can Be Removed
            IR1 <= 32'hdead_beef;
            IR2 <= 32'hdead_beef;
        end else begin
            debugCycle <= debugCycle + 1;
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
    logic reasonIllegal1;
    logic reasonIllegal2;
    logic reasonSlot1Memory;
    logic reasonWawConflict;
    logic reasonSlotDependency;
    logic reasonDualRedirect;
    logic reasonBadFetch;
    logic reasonRobOneFree;
    logic reasonRobFull;
    logic reasonUpperLoadHazard;
    logic reasonLowerLoadHazard;
    logic reasonBackwardDependency;

    // Issuer Contract Logic
    always_comb begin
        // Zero Initialize
        block1 = 1'b0;
        block2 = 1'b0;
        bypassEnable = 2'b00;
        reasonIllegal1 = 1'b0;
        reasonIllegal2 = 1'b0;
        reasonSlot1Memory = 1'b0;
        reasonWawConflict = 1'b0;
        reasonSlotDependency = 1'b0;
        reasonDualRedirect = 1'b0;
        reasonBadFetch = 1'b0;
        reasonRobOneFree = 1'b0;
        reasonRobFull = 1'b0;
        reasonUpperLoadHazard = 1'b0;
        reasonLowerLoadHazard = 1'b0;
        reasonBackwardDependency = 1'b0;
        // Both Instructions Valid
        if (instructionsValid) begin
            // FOR TESTING ONLY
            if (illegal2) begin
                block2 = 1'b1;
                reasonIllegal2 = 1'b1;
            end
            // FOR TESTING ONLY
            if (illegal1) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonIllegal1 = 1'b1;
            end
            // Memory Ops Must Always Issue in Slot 0
            if (tempPayload2.memoryOperation != MEM_NONE) begin
                block2 = 1'b1;
                reasonSlot1Memory = 1'b1;
            end
            // Block WAW To Simplify Forwarding/RST Logic
            if (destinationRegister1 == destinationRegister2) begin
                block2 = 1'b1; 
                reasonWawConflict = 1'b1;
            end
            // Slot 0/1 Dependency Param Gated Generator
            if (!crossLaneExBypass) begin : BYPASS_PARAM
                // Block Slot 0 + Slot 1 Dependencies
                if ((tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) ||
                (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0)) begin
                    block2 = 1'b1;
                    reasonSlotDependency = 1'b1;
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
            // Block Issue on Bad Fetch
            if (internalBadData) begin
                block2 = 1'd1;
                reasonBadFetch = 1'b1;
            end
            // ROB Capacity Gating
            if (nextFreeSlots == 'd1) begin
                block2 = 1'b1;
                reasonRobOneFree = 1'b1;
            end else if (nextFreeSlots == 'd0) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonRobFull = 1'b1;
            end
            // No Issue On Redirect
            if (redirect) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end
            // Block Issue On Unready Load rs's or rd's. Calculated in RST
            // VITAL and used in subtle RST/ROB Assumptions
            if (upperInFlightLoad1 || upperInFlightLoad2 || destRegLoad1) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonUpperLoadHazard = 1'b1;
            end
            if (lowerInFlightLoad1 || lowerInFlightLoad2 || destRegLoad2) begin
                block2 = 1'b1;
                reasonLowerLoadHazard = 1'b1;
            end
            // Block Issue On Backwards Slot 0/1 Dependency to Fix RST Ownership Problems
            if ((tempPayload1.sourceRegister1 == destinationRegister2 && destinationRegister2 != 5'd0) ||
                (tempPayload1.sourceRegister2 == destinationRegister2 && destinationRegister2 != 5'd0)) begin
                block2 = 1'b1;
                reasonBackwardDependency = 1'b1;
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
        if (!reset && !redirect) begin
            if (!block1 && !block2) begin
                instructionConsumed1 = 1'd1;
                instructionConsumed2 = 1'd1;
            end else if (!block1) begin
                instructionConsumed1 = 1'd1;
            end
        end
        // Payload Construction
        if (instructionConsumed1 && instructionConsumed2) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.ageTag = freeTag1;
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
            finalLowerPayload.ageTag = freeTag2;
            finalLowerPayload.bypassEnable = bypassEnable;
            finalLowerPayload.valid = 1'd1;
        end else if (instructionConsumed1) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.ageTag = freeTag1;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload
            finalLowerPayload = '0;
        end else begin
            // Invalidate Both
            finalUpperPayload = '0;
            finalLowerPayload = '0;
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
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.isStore = (tempPayload1.memoryOperation == MEM_STORE);
            instructionPacket1.confirm = 1'd1;
            // Instruction 2 to ROB
            instructionPacket2.programCounter = PC2;
            instructionPacket2.destinationRegister = destinationRegister2;
            instructionPacket2.ageTag = freeTag2;
            instructionPacket2.isStore = (tempPayload2.memoryOperation == MEM_STORE);
            instructionPacket2.confirm = 1'd1;
        end else if (instructionConsumed1) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.isStore = (tempPayload1.memoryOperation == MEM_STORE);
            instructionPacket1.confirm = 1'd1;
        end
    end

    // Instruction Payload Assignment
    always_ff @(posedge clock) begin
        payload1 <= finalUpperPayload;
        payload2 <= finalLowerPayload;
    end

    // Independent Issue Trace
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (instructionConsumed1 && instructionConsumed2) begin
                $display("[DecodeIssue][cycle %0d] issued %08h and %08h", debugCycle, PC1, PC2);
            end else if (instructionConsumed1) begin
                $display("[DecodeIssue][cycle %0d] issued %08h", debugCycle, PC1);
            end
        end
    end

    // Issue Packet Trace
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (instructionPacket1.confirm) begin
                $display("[DecodeIssue][cycle %0d][packet] slot0 pc=%08h tag=%0d rd=%0d store=%0b confirm=%0b",
                    debugCycle,
                    instructionPacket1.programCounter,
                    instructionPacket1.ageTag,
                    instructionPacket1.destinationRegister,
                    instructionPacket1.isStore,
                    instructionPacket1.confirm);
            end
            if (instructionPacket2.confirm) begin
                $display("[DecodeIssue][cycle %0d][packet] slot1 pc=%08h tag=%0d rd=%0d store=%0b confirm=%0b",
                    debugCycle,
                    instructionPacket2.programCounter,
                    instructionPacket2.ageTag,
                    instructionPacket2.destinationRegister,
                    instructionPacket2.isStore,
                    instructionPacket2.confirm);
            end
        end
    end

    // Independent Refusal Trace
    always_ff @(posedge clock) begin
        if (!reset && instructionsValid) begin
            if (block1) begin
                if (reasonIllegal1) $display("[DecodeIssue][cycle %0d] refusal slot0 pc=%08h ir=%08h: illegal instruction", debugCycle, PC1, IR1);
                if (reasonRobFull) $display("[DecodeIssue][cycle %0d] refusal slot0 pc=%08h ir=%08h: ROB full", debugCycle, PC1, IR1);
                if (reasonUpperLoadHazard) $display("[DecodeIssue][cycle %0d] refusal slot0 pc=%08h ir=%08h: unready load hazard", debugCycle, PC1, IR1);
            end
            if (block2) begin
                if (reasonIllegal2) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: illegal instruction", debugCycle, PC2, IR2);
                if (reasonIllegal1) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: blocked by slot0 illegal instruction", debugCycle, PC2, IR2);
                if (reasonSlot1Memory) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: memory op must issue in slot0", debugCycle, PC2, IR2);
                if (reasonWawConflict) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: WAW conflict", debugCycle, PC2, IR2);
                if (reasonSlotDependency) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: slot0/slot1 dependency", debugCycle, PC2, IR2);
                if (reasonDualRedirect) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: dual redirect", debugCycle, PC2, IR2);
                if (reasonBadFetch) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: bad fetch window", debugCycle, PC2, IR2);
                if (reasonRobOneFree) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: only one ROB slot free", debugCycle, PC2, IR2);
                if (reasonRobFull) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: ROB full", debugCycle, PC2, IR2);
                if (reasonUpperLoadHazard) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: blocked by slot0 load hazard", debugCycle, PC2, IR2);
                if (reasonLowerLoadHazard) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: unready load hazard", debugCycle, PC2, IR2);
                if (reasonBackwardDependency) $display("[DecodeIssue][cycle %0d] refusal slot1 pc=%08h ir=%08h: backwards dependency", debugCycle, PC2, IR2);
            end
        end
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



