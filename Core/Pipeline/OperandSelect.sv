import Configuration::*;
import Payloads::*;
import Enumerations::*;


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
    input RegisterStatusOutput_ upperSource1StatusDummy,
    input RegisterStatusOutput_ upperSource2StatusDummy,
    input RegisterStatusOutput_ lowerSource1StatusDummy,
    input RegisterStatusOutput_ lowerSource2StatusDummy,

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

    // To Mem Queue for Capacity
    output logic osMemory,

    // Quad Index Forward Requests To ROB
    output logic [reorderBufferIndexWidth-1:0] upperTagIndex1,
    output logic [reorderBufferIndexWidth-1:0] upperTagIndex2,
    output logic [reorderBufferIndexWidth-1:0] lowerTagIndex1,
    output logic [reorderBufferIndexWidth-1:0] lowerTagIndex2,

    // ROB Forward Data
    input logic [31:0] upperROBData1,
    input logic [31:0] upperROBData2,
    input logic [31:0] lowerROBData1,
    input logic [31:0] lowerROBData2,

    // Forward From Ex
    input logic [31:0] upperExData,
    input logic [31:0] lowerExData,
    input logic [reorderBufferIndexWidth-1:0] upperExTag,
    input logic [reorderBufferIndexWidth-1:0] lowerExTag,
    input logic lowerExValid,

    // Completion Metadata For oldStatus Repair
    input logic [reorderBufferIndexWidth-1:0] retireTag1,
    input logic retireValid1,
    input logic [reorderBufferIndexWidth-1:0] retireTag2,
    input logic retireValid2,
    input logic [reorderBufferIndexWidth-1:0] acceptTag1,
    input logic acceptValid1,
    input logic [reorderBufferIndexWidth-1:0] acceptTag2,
    input logic acceptValid2,
    input logic memReady,
    input logic [reorderBufferIndexWidth-1:0] memAgeTag,

    // Load Bypass Data
    input logic [31:0] loadData,
    input logic [reorderBufferIndexWidth-1:0] loadTag,
    input logic acknowledge,

    // Payloads From Issuer
    input UpperIssuerOperandPayload_ payload1,
    input LowerIssuerOperandPayload_ payload2,

    // Backpropagating Stall Bit
    output logic stall,

    // Payloads to Execute
    output UpperOperandExecutePayload_ exPayload1,
    output LowerOperandExecutePayload_ exPayload2,

    // CSR Interface
    output DestinationCSR_ readCSR1,
    input logic [31:0] CSRData1,
    output DestinationCSR_ readCSR2,
    input logic [31:0] CSRData2

);

    typedef enum logic [2:0] {
        SRC_ZERO,
        SRC_CSR,
        SRC_REGFILE,
        SRC_ROB,
        SRC_EX_LOWER,
        SRC_EX_UPPER,
        SRC_LOAD,
        SRC_STALL
    } OperandSource_;

    // Dummy Candidate Payloads
    UpperOperandExecutePayload_ exPayloadCandidate1;
    LowerOperandExecutePayload_ exPayloadCandidate2;
    integer debugCycle;

    // CSR Register Addresses
    assign readCSR1 = payload1.system.destinationCSR;
    assign readCSR2 = payload2.system.destinationCSR;

    // Register Values
    logic [31:0] upperOperand1;
    logic [31:0] upperOperand2;
    logic [31:0] lowerOperand1;
    logic [31:0] lowerOperand2;
    OperandSource_ upperSource1Select;
    OperandSource_ upperSource2Select;
    OperandSource_ lowerSource1Select;
    OperandSource_ lowerSource2Select;

    // Register Data From RST
    RegisterStatusOutput_ upperSource1Status;
    RegisterStatusOutput_ upperSource2Status;
    RegisterStatusOutput_ lowerSource1Status;
    RegisterStatusOutput_ lowerSource2Status;

    assign upperSource1Status = (payload1.staleVector[0] ? payload1.oldStatus : (payload1.staleVector2[0] ? payload2.oldStatus : upperSource1StatusDummy));
    assign upperSource2Status = (payload1.staleVector[1] ? payload1.oldStatus : (payload1.staleVector2[1] ? payload2.oldStatus : upperSource2StatusDummy));
    assign lowerSource1Status = (payload2.staleVector[0] ? payload2.oldStatus : lowerSource1StatusDummy);
    assign lowerSource2Status = (payload2.staleVector[1] ? payload2.oldStatus : lowerSource2StatusDummy);

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

    function automatic string operandSourceName(input OperandSource_ source);
        case (source)
            SRC_ZERO: return "ZERO";
            SRC_CSR: return "CSR";
            SRC_REGFILE: return "REG";
            SRC_ROB: return "ROB";
            SRC_EX_LOWER: return "EX1";
            SRC_EX_UPPER: return "EX0";
            SRC_LOAD: return "LOAD";
            SRC_STALL: return "STALL";
            default: return "UNK";
        endcase
    endfunction

    assign branchTarget1 = payload1.programCounter + payload1.immediate;
    assign branchTarget2 = payload2.programCounter + payload2.immediate;

    // Memory Op Signal for Capacity
    assign osMemory = (payload1.memoryOperation != MEM_NONE) && payload1.valid;

    // Register Portion of Operand Mux
    always_comb begin

        // Candidate Payloads
        exPayloadCandidate1 = '0;
        exPayloadCandidate2 = '0;
        upperOperand1 = '0;
        upperOperand2 = '0;
        lowerOperand1 = '0;
        lowerOperand2 = '0;
        upperSource1Select = SRC_ZERO;
        upperSource2Select = SRC_ZERO;
        lowerSource1Select = SRC_ZERO;
        lowerSource2Select = SRC_ZERO;
        stall = '0;

        // Upper Source Register 1
        if (payload1.system.CSROp != CSR_NONE) begin
            // CSR Read
            if (payload1.system.CSROp == CSR_RW) begin
                upperOperand1 = 32'd0;
                upperSource1Select = SRC_ZERO;
            end else begin
                upperOperand1 = CSRData1;
                upperSource1Select = SRC_CSR;
            end
        end else if (payload1.sourceRegister1 == 5'd0) begin
            // Hardwire x0 to Zero
            upperOperand1 = 32'd0;
            upperSource1Select = SRC_ZERO;
        end else if (upperSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            upperOperand1 = upperData1;
            upperSource1Select = SRC_REGFILE;
        end else if (upperSource1Status.resultReady) begin
            // Use ROB Forward Data
            upperOperand1 = upperROBData1;
            upperSource1Select = SRC_ROB;
        end else if (!upperSource1Status.isLoad) begin
            if (lowerExTag == upperSource1Status.ageTag && lowerExValid) begin
                // Use Slot 1 Execute Bypass Data
                upperOperand1 = lowerExData;
                upperSource1Select = SRC_EX_LOWER;
            end else if (upperExTag == upperSource1Status.ageTag) begin
                // Use Slot 0 Execute Bypass Data
                upperOperand1 = upperExData;
                upperSource1Select = SRC_EX_UPPER;
            end
        end else if (acknowledge && (loadTag == upperSource1Status.ageTag)) begin
            upperOperand1 = loadData;
            upperSource1Select = SRC_LOAD;
        end else begin
            upperSource1Select = SRC_STALL;
            stall = 1;
        end

        // Upper Source Register 2
        if (payload1.sourceRegister2 == 5'd0) begin
            // Hardwire x0 to Zero
            upperOperand2 = 32'd0;
            upperSource2Select = SRC_ZERO;
        end else if (upperSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            upperOperand2 = upperData2;
            upperSource2Select = SRC_REGFILE;
        end else if (upperSource2Status.resultReady) begin
            // Use ROB Forward Data
            upperOperand2 = upperROBData2;
            upperSource2Select = SRC_ROB;
        end else if (!upperSource2Status.isLoad) begin
            if (lowerExTag == upperSource2Status.ageTag && lowerExValid) begin
                // Use Slot 1 Execute Bypass Data
                upperOperand2 = lowerExData;
                upperSource2Select = SRC_EX_LOWER;
            end else if (upperExTag == upperSource2Status.ageTag) begin
                // Use Slot 0 Execute Bypass Data
                upperOperand2 = upperExData;
                upperSource2Select = SRC_EX_UPPER;
            end
        end else if (acknowledge && (loadTag == upperSource2Status.ageTag)) begin
            upperOperand2 = loadData;
            upperSource2Select = SRC_LOAD;
        end else begin
            upperSource2Select = SRC_STALL;
            stall = 1;
        end

        // Lower Source Register 1
        if (payload2.system.CSROp != CSR_NONE) begin
            // CSR Read
            if (payload2.system.CSROp == CSR_RW) begin
                lowerOperand1 = 32'd0;
                lowerSource1Select = SRC_ZERO;
            end else begin
                lowerOperand1 = CSRData2;
                lowerSource1Select = SRC_CSR;
            end
        end else if (payload2.sourceRegister1 == 5'd0) begin
            // Hardwire x0 to Zero
            lowerOperand1 = 32'd0;
            lowerSource1Select = SRC_ZERO;
        end else if (lowerSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            lowerOperand1 = lowerData1;
            lowerSource1Select = SRC_REGFILE;
        end else if (lowerSource1Status.resultReady) begin
            // Use ROB Forward Data
            lowerOperand1 = lowerROBData1;
            lowerSource1Select = SRC_ROB;
        end else if (!lowerSource1Status.isLoad) begin
            if (lowerExTag == lowerSource1Status.ageTag && lowerExValid) begin
                // Use Slot 1 Execute Bypass Data
                lowerOperand1 = lowerExData;
                lowerSource1Select = SRC_EX_LOWER;
            end else if (upperExTag == lowerSource1Status.ageTag) begin
                // Use Slot 0 Execute Bypass Data
                lowerOperand1 = upperExData;
                lowerSource1Select = SRC_EX_UPPER;
            end
        end else if (acknowledge && (loadTag == lowerSource1Status.ageTag)) begin
            lowerOperand1 = loadData;
            lowerSource1Select = SRC_LOAD;
        end else begin
            lowerSource1Select = SRC_STALL;
            stall = 1;
        end

        // Lower Source Register 2
        if (payload2.sourceRegister2 == 5'd0) begin
            // Hardwire x0 to Zero
            lowerOperand2 = 32'd0;
            lowerSource2Select = SRC_ZERO;
        end else if (lowerSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            lowerOperand2 = lowerData2;
            lowerSource2Select = SRC_REGFILE;
        end else if (lowerSource2Status.resultReady) begin
            // Use ROB Forward Data
            lowerOperand2 = lowerROBData2;
            lowerSource2Select = SRC_ROB;
        end else if (!lowerSource2Status.isLoad) begin
            if (lowerExTag == lowerSource2Status.ageTag && lowerExValid) begin
                // Use Slot 1 Execute Bypass Data
                lowerOperand2 = lowerExData;
                lowerSource2Select = SRC_EX_LOWER;
            end else if (upperExTag == lowerSource2Status.ageTag) begin
                // Use Slot 0 Execute Bypass Data
                lowerOperand2 = upperExData;
                lowerSource2Select = SRC_EX_UPPER;
            end
        end else if (acknowledge && (loadTag == lowerSource2Status.ageTag)) begin
            lowerOperand2 = loadData;
            lowerSource2Select = SRC_LOAD;
        end else begin
            lowerSource2Select = SRC_STALL;
            stall = 1;
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
        end else if (payload1.system.CSROp != CSR_NONE) begin
            // CSR Read Data
            exPayloadCandidate1.extraField = CSRData1;
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

        // CSR Inversion Override
        if (payload1.system.CSROp == CSR_RC) begin
            // Inverts Operand 1 for CSR Clear Operations
            exPayloadCandidate1.operand2 = ~exPayloadCandidate1.operand2;
        end
         if (payload2.system.CSROp == CSR_RC) begin
            // Inverts Operand 2 for CSR Clear Operations
            exPayloadCandidate2.operand2 = ~exPayloadCandidate2.operand2;
        end

        // Instruction 2 Extra Source Assignment
        if (payload2.jumpType != JUMP_NONE) begin
            // PC + 4 For Writeback
            exPayloadCandidate2.extraField = payload2.programCounter + 32'd4;
        end else if (payload2.branchType != BR_NONE) begin
            // Branch Target Address Pre-Evaluation
            exPayloadCandidate2.extraField = branchTarget2;
        end else if (payload2.system.CSROp != CSR_NONE) begin
            // CSR Read Data
            exPayloadCandidate2.extraField = CSRData2;
        end

        // Instruction 1 Passthrough Assignments
        exPayloadCandidate1.aluOperation = payload1.aluOperation;
        exPayloadCandidate1.jumpType = payload1.jumpType;
        exPayloadCandidate1.destinationRegister = payload1.destinationRegister;
        exPayloadCandidate1.branchType = payload1.branchType;
        exPayloadCandidate1.system = payload1.system; 
        exPayloadCandidate1.memoryOperation = payload1.memoryOperation;
        exPayloadCandidate1.memoryWidth = payload1.memoryWidth;
        exPayloadCandidate1.memorySigned = payload1.memorySigned;
        exPayloadCandidate1.predicted = payload1.predicted;
        exPayloadCandidate1.ageTag = payload1.ageTag;
        exPayloadCandidate1.programCounter = payload1.programCounter;
        exPayloadCandidate1.trapType = payload1.trapType;
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
        exPayloadCandidate2.system = payload2.system;
        exPayloadCandidate2.ageTag = payload2.ageTag;
        exPayloadCandidate2.predicted = payload2.predicted;
        exPayloadCandidate2.programCounter = payload2.programCounter;
        exPayloadCandidate2.trapType = payload2.trapType;
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
        if (!reset && debugMode) begin
            if (payload1.valid || payload2.valid || exPayload1.valid || exPayload2.valid) begin
                $display("[OS] cycle=%0d stall=%0b redirect=%0b ack=%0b loadTag=%0d loadData=%08h upperExTag=%0d upperExData=%08h lowerExTag=%0d lowerExData=%08h lowerExValid=%0b",
                    debugCycle, stall, redirect, acknowledge, loadTag, loadData,
                    upperExTag, upperExData, lowerExTag, lowerExData, lowerExValid);
                $display("     lane0 pc=%08h tag=%0d rs1=x%0d(%s age=%0d c=%0b r=%0b l=%0b val=%08h) rs2=x%0d(%s age=%0d c=%0b r=%0b l=%0b val=%08h) -> cand(op1=%08h op2=%08h valid=%0b)",
                    payload1.programCounter, payload1.ageTag,
                    payload1.sourceRegister1, operandSourceName(upperSource1Select), upperSource1Status.ageTag,
                    upperSource1Status.resultCommitted, upperSource1Status.resultReady, upperSource1Status.isLoad, upperOperand1,
                    payload1.sourceRegister2, operandSourceName(upperSource2Select), upperSource2Status.ageTag,
                    upperSource2Status.resultCommitted, upperSource2Status.resultReady, upperSource2Status.isLoad, upperOperand2,
                    exPayloadCandidate1.operand1, exPayloadCandidate1.operand2, exPayloadCandidate1.valid);
                $display("           presented: reg1=%08h reg2=%08h rob1=%08h rob2=%08h csr=%08h",
                    upperData1, upperData2, upperROBData1, upperROBData2, CSRData1);
                $display("     lane1 pc=%08h tag=%0d rs1=x%0d(%s age=%0d c=%0b r=%0b l=%0b val=%08h) rs2=x%0d(%s age=%0d c=%0b r=%0b l=%0b val=%08h) -> cand(op1=%08h op2=%08h valid=%0b)",
                    payload2.programCounter, payload2.ageTag,
                    payload2.sourceRegister1, operandSourceName(lowerSource1Select), lowerSource1Status.ageTag,
                    lowerSource1Status.resultCommitted, lowerSource1Status.resultReady, lowerSource1Status.isLoad, lowerOperand1,
                    payload2.sourceRegister2, operandSourceName(lowerSource2Select), lowerSource2Status.ageTag,
                    lowerSource2Status.resultCommitted, lowerSource2Status.resultReady, lowerSource2Status.isLoad, lowerOperand2,
                    exPayloadCandidate2.operand1, exPayloadCandidate2.operand2, exPayloadCandidate2.valid);
                $display("           presented: reg1=%08h reg2=%08h rob1=%08h rob2=%08h csr=%08h",
                    lowerData1, lowerData2, lowerROBData1, lowerROBData2, CSRData2);
            end
        end
        if (stall) begin
            exPayload1 <= '0;
            exPayload2 <= '0;
        end else begin
            exPayload1 <= exPayloadCandidate1;
            exPayload2 <= exPayloadCandidate2;
            if (!reset && debugMode && (exPayloadCandidate1.valid || exPayloadCandidate2.valid)) begin
                $display("[OS->EX] cycle=%0d lane0 pc=%08h tag=%0d op1=%08h op2=%08h valid=%0b lane1 pc=%08h tag=%0d op1=%08h op2=%08h valid=%0b",
                    debugCycle,
                    exPayloadCandidate1.programCounter, exPayloadCandidate1.ageTag,
                    exPayloadCandidate1.operand1, exPayloadCandidate1.operand2, exPayloadCandidate1.valid,
                    exPayloadCandidate2.programCounter, exPayloadCandidate2.ageTag,
                    exPayloadCandidate2.operand1, exPayloadCandidate2.operand2, exPayloadCandidate2.valid);
            end
        end
    end

endmodule

