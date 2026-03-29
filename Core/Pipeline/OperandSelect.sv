import Configuration::*;
import Payloads::*;
import Enumerations::*;

localparam int width = $clog2(reorderBufferEntries);

module OperandSelect (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals MUST IMPLIMENT
    input logic redirect,

    // Read From RST
    output logic [4:0] upperSourceRegister1,
    output logic [4:0] upperSourceRegister2,
    output logic [4:0] lowerSourceRegister1,
    output logic [4:0] lowerSourceRegister2,

    // Register Data From RST
    input RegisterStatusOutput_ upperSource1Status,
    input RegisterStatusOutput_ upperSource2Status,
    input RegisterStatusOutput_ lowerSource1Status,
    input RegisterStatusOutput_ lowerSource2Status,

    // Reg File Read Addresses
    output logic [4:0] upperAddress1,
    output logic [4:0] upperAddress2,
    output logic [4:0] lowerAddress1,
    output logic [4:0] lowerAddress2,

    // Reg File Data
    input logic [31:0] upperData1,
    input logic [31:0] upperData2,
    input logic [31:0] lowerData1,
    input logic [31:0] lowerData2,

    // Quad Index Forward Requests To ROB
    output logic [width-1:0] upperTagIndex1,
    output logic [width-1:0] upperTagIndex2,
    output logic [width-1:0] lowerTagIndex1,
    output logic [width-1:0] lowerTagIndex2,

    // ROB Forward Data
    input logic [31:0] upperROBData1,
    input logic [31:0] upperROBData2,
    input logic [31:0] lowerROBData1,
    input logic [31:0] lowerROBData2,

    // Forward From Ex
    input logic [31:0] upperExData,
    input logic [31:0] lowerExData,
    input logic [width-1:0] upperExTag,
    input logic [width-1:0] lowerExTag,

    // Payloads From Issuer
    input UpperIssuerOperandPayload_ payload1,
    input LowerIssuerOperandPayload_ payload2,

    // Payloads to Execute
    output UpperOperandExecutePayload_ exPayload1,
    output LowerOperandExecutePayload_ exPayload2

);
    // Dummy Candidate Payloads
    UpperOperandExecutePayload_ exPayloadCandidate1;
    LowerOperandExecutePayload_ exPayloadCandidate2;
    integer debugCycle;

    // Register Values
    logic [31:0] upperOperand1;
    logic [31:0] upperOperand2;
    logic [31:0] lowerOperand1;
    logic [31:0] lowerOperand2;

    // RST Signal Assignment
    assign upperSourceRegister1 = payload1.sourceRegister1;
    assign upperSourceRegister2 = payload1.sourceRegister2;
    assign lowerSourceRegister1 = payload2.sourceRegister1;
    assign lowerSourceRegister2 = payload2.sourceRegister2;

    // Redundant Reg File Signals (Can Use RST Signals)
    assign upperAddress1 = payload1.sourceRegister1;
    assign upperAddress2 = payload1.sourceRegister2;
    assign lowerAddress1 = payload2.sourceRegister1;
    assign lowerAddress2 = payload2.sourceRegister2;

    // ROB Forwarding Requests
    assign upperTagIndex1 = upperSource1Status.ageTag;
    assign upperTagIndex2 = upperSource2Status.ageTag;
    assign lowerTagIndex1 = lowerSource1Status.ageTag;
    assign lowerTagIndex2 = lowerSource2Status.ageTag;

    // Branch Target Precompute to Free ALU
    logic [31:0] branchTarget1;
    logic [31:0] branchTarget2;

    assign branchTarget1 = payload1.programCounter + payload1.immediate;
    assign branchTarget2 = payload2.programCounter + payload2.immediate;

    // Register Portion of Operand Mux
    always_comb begin

        // Candidate Payloads
        exPayloadCandidate1 = '0;
        exPayloadCandidate2 = '0;
        upperOperand1 = '0;
        upperOperand2 = '0;
        lowerOperand1 = '0;
        lowerOperand2 = '0;

        // Upper Source Register 1
        if (payload1.sourceRegister1 == 5'd0) begin
            // Hardwire x0 to Zero
            upperOperand1 = 32'd0;
        end else if (upperSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            upperOperand1 = upperData1;
        end else if (upperSource1Status.resultReady) begin
            // Use ROB Forward Data
            upperOperand1 = upperROBData1;
        end else if (lowerExTag == upperSource1Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            upperOperand1 = lowerExData;
        end else if (upperExTag == upperSource1Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            upperOperand1 = upperExData;
        end

        // Upper Source Register 2
        if (payload1.sourceRegister2 == 5'd0) begin
            // Hardwire x0 to Zero
            upperOperand2 = 32'd0;
        end else if (upperSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            upperOperand2 = upperData2;
        end else if (upperSource2Status.resultReady) begin
            // Use ROB Forward Data
            upperOperand2 = upperROBData2;
        end else if (lowerExTag == upperSource2Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            upperOperand2 = lowerExData;
        end else if (upperExTag == upperSource2Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            upperOperand2 = upperExData;
        end

        // Lower Source Register 1
        if (payload2.sourceRegister1 == 5'd0) begin
            // Hardwire x0 to Zero
            lowerOperand1 = 32'd0;
        end else if (lowerSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            lowerOperand1 = lowerData1;
        end else if (lowerSource1Status.resultReady) begin
            // Use ROB Forward Data
            lowerOperand1 = lowerROBData1;
        end else if (lowerExTag == lowerSource1Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            lowerOperand1 = lowerExData;
        end else if (upperExTag == lowerSource1Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            lowerOperand1 = upperExData;
        end

        // Lower Source Register 2
        if (payload2.sourceRegister2 == 5'd0) begin
            // Hardwire x0 to Zero
            lowerOperand2 = 32'd0;
        end else if (lowerSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            lowerOperand2 = lowerData2;
        end else if (lowerSource2Status.resultReady) begin
            // Use ROB Forward Data
            lowerOperand2 = lowerROBData2;
        end else if (lowerExTag == lowerSource2Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            lowerOperand2 = lowerExData;
        end else if (upperExTag == lowerSource2Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            lowerOperand2 = upperExData;
        end

        // Instruction 1 Case Operand Assignment
        unique case (payload1.aluSource)
            ALU_RS1_RS2: begin
                exPayloadCandidate1.operand1 = upperOperand1;
                exPayloadCandidate1.operand2 = upperOperand2;
            end
            ALU_RS1_IMM: begin
                exPayloadCandidate1.operand1 = upperOperand1;
                exPayloadCandidate1.operand2 = payload1.immediate;
            end
            ALU_PC_IMM: begin
                exPayloadCandidate1.operand1 = payload1.programCounter;
                exPayloadCandidate1.operand2 = payload1.immediate;
            end
            ALU_ZERO_IMM: begin
                exPayloadCandidate1.operand1 = 32'd0;
                exPayloadCandidate1.operand2 = payload1.immediate;
            end
        endcase

        // Instruction 1 Extra Source Assignment
        if (payload1.jumpType != JUMP_NONE) begin
            // PC + 4 For Writeback
            exPayloadCandidate1.extraField = payload1.programCounter + 32'd4;
        end else if (payload1.branchType != BR_NONE) begin
            // Branch Target Address Pre-Evaluation
            exPayloadCandidate1.extraField = branchTarget1;
        end else if (payload1.memoryOperation == MEM_STORE) begin
            // Store Data
            exPayloadCandidate1.extraField = upperOperand2;
        end

        // Instruction 2 Case Operand Assignment
        unique case (payload2.aluSource)
            ALU_RS1_RS2: begin
                exPayloadCandidate2.operand1 = lowerOperand1;
                exPayloadCandidate2.operand2 = lowerOperand2;
            end
            ALU_RS1_IMM: begin
                exPayloadCandidate2.operand1 = lowerOperand1;
                exPayloadCandidate2.operand2 = payload2.immediate;
            end
            ALU_PC_IMM: begin
                exPayloadCandidate2.operand1 = payload2.programCounter;
                exPayloadCandidate2.operand2 = payload2.immediate;
            end
            ALU_ZERO_IMM: begin
                exPayloadCandidate2.operand1 = 32'd0;
                exPayloadCandidate2.operand2 = payload2.immediate;
            end
        endcase

        // Instruction 2 Extra Source Assignment
        if (payload2.jumpType != JUMP_NONE) begin
            // PC + 4 For Writeback
            exPayloadCandidate2.extraField = payload2.programCounter + 32'd4;
        end else if (payload2.branchType != BR_NONE) begin
            // Branch Target Address Pre-Evaluation
            exPayloadCandidate2.extraField = branchTarget2;
        end

        // Instruction 1 Passthrough Assignments
        exPayloadCandidate1.aluOperation = payload1.aluOperation;
        exPayloadCandidate1.jumpType = payload1.jumpType;
        exPayloadCandidate1.destinationRegister = payload1.destinationRegister;
        exPayloadCandidate1.branchType = payload1.branchType;
        exPayloadCandidate1.memoryOperation = payload1.memoryOperation;
        exPayloadCandidate1.memoryWidth = payload1.memoryWidth;
        exPayloadCandidate1.memorySigned = payload1.memorySigned;
        exPayloadCandidate1.ageTag = payload1.ageTag;
        if (!reset && !redirect) begin
            exPayloadCandidate1.valid = payload1.valid;
        end else begin
            exPayloadCandidate1.valid = 1'd0;
        end

        // Instruction 2 Passthrough Assignments
        exPayloadCandidate2.aluOperation = payload2.aluOperation;
        exPayloadCandidate2.jumpType = payload2.jumpType;
        exPayloadCandidate2.destinationRegister = payload2.destinationRegister;
        exPayloadCandidate2.branchType = payload2.branchType;
        exPayloadCandidate2.ageTag = payload2.ageTag;
        if (!reset && !redirect) begin
            exPayloadCandidate2.valid = payload2.valid;
        end else begin
            exPayloadCandidate2.valid = 1'd0;
        end
        exPayloadCandidate2.bypassEnable = payload2.bypassEnable;

    end

    // Final Assignment
    always_ff @(posedge clock) begin
        if (reset) begin
            debugCycle <= 0;
        end else begin
            debugCycle <= debugCycle + 1;
        end
        exPayload1 <= exPayloadCandidate1;
        exPayload2 <= exPayloadCandidate2;
    end

endmodule

// concern for add x4, x4 x4
// rd overwrites rst and data looks stale
