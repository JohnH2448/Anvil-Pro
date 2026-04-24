import Configuration::*;
import Payloads::*;
import Enumerations::*;

module Execute (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    output logic redirect,
    output logic [31:0] redirectVector,

    // Mispredict Metadata for ROB
    output logic mispredict1,
    output logic mispredict2,

    // Branch Predictor Update Metadata
    output logic bpUpdateValid1,
    output logic [31:0] bpUpdatePC1,
    output logic bpUpdateTaken1,
    output logic bpUpdateValid2,
    output logic [31:0] bpUpdatePC2,
    output logic bpUpdateTaken2,

    // Payloads to Execute
    input UpperOperandExecutePayload_ exPayload1,
    input LowerOperandExecutePayload_ exPayload2,

    // To Memory Queue
    output ExecuteMemoryPayload_ memPayload,
    output logic exMemory,

    // To ROB
    output InputInstruction_ resultPayload1,
    output InputInstruction_ resultPayload2,

    // Store Buffer Coms
    input logic [31:0] finalOutputData,
    input logic outputValid,
    output logic [31:0] inputAddress,
    output logic [1:0] loadWidth,
    output logic loadSigned,

    // MRET Special Case
    output logic isMRET,

    // Frontend Stall Indicator
    output logic exceptionForFrontend

);

    logic [31:0] result1;
    logic [31:0] result2;
    logic [31:0] writebackResult1;
    logic [31:0] redirectVector1;
    logic [31:0] redirectVector2;
    logic redirect1;
    logic redirect2;
    integer debugCycle;
    logic [31:0] PC1P4;
    logic [31:0] PC2P4;
    assign PC1P4 = exPayload1.programCounter + 32'd4;
    assign PC2P4 = exPayload2.programCounter + 32'd4;

    // Address Validity Check
    logic [2:0] accessBytes;
    logic accessFault;
    logic misAddress;
    logic misTarget1;
    logic misTarget2;
    logic memTrap;

    always_comb begin
        unique case (exPayload1.memoryWidth)
            2'b00: accessBytes = 3'd1; // byte
            2'b01: accessBytes = 3'd2; // halfword
            default: accessBytes = 3'd4; // word
        endcase

        accessFault = 1'b0;
        if (result1 < dLowerBound) begin
            accessFault = 1'b1;
        end else if ((result1 + {29'd0, accessBytes}) > dUpperBound) begin
            accessFault = 1'b1;
        end

        unique case (exPayload1.memoryWidth)
            2'b00: misAddress = 1'b0;
            2'b01: misAddress = result1[0];
            default: misAddress = |result1[1:0];
        endcase
    end

    // Legality
    logic upperIllegal;
    logic lowerIllegal;
    assign upperIllegal = exPayload1.valid && ((exPayload1.trapType != NONE) || misTarget1 || memTrap);
    assign lowerIllegal = exPayload2.valid && ((exPayload2.trapType != NONE) || misTarget2);
    assign exceptionForFrontend = upperIllegal || lowerIllegal;

    // Redirect Priority Logic
    assign mispredict1 = upperIllegal || ((exPayload1.system.mret ? 1'b1 : (redirect1 != exPayload1.predicted)) && !upperIllegal && exPayload1.valid);
    assign mispredict2 = !mispredict1 && (lowerIllegal || ((exPayload2.system.mret ? 1'b1 : (redirect2 != exPayload2.predicted)) && !lowerIllegal && !upperIllegal && exPayload2.valid));
    assign isMRET = (mispredict1 && exPayload1.system.mret) || ((mispredict2 && exPayload2.system.mret) && !(mispredict1 && !exPayload1.system.mret));
    assign redirect = mispredict1 || mispredict2;
    assign redirectVector = mispredict1 ? (exPayload1.predicted ? PC1P4 : redirectVector1) : 
    (mispredict2 ? (exPayload2.predicted ? PC2P4 : redirectVector2) : 32'd0);
    assign bpUpdateValid1 = exPayload1.valid && !upperIllegal &&
        (exPayload1.branchType != BR_NONE);
    assign bpUpdatePC1 = exPayload1.programCounter;
    assign bpUpdateTaken1 = redirect1;
    assign bpUpdateValid2 = exPayload2.valid && !lowerIllegal && !mispredict1 &&
        (exPayload2.branchType != BR_NONE);
    assign bpUpdatePC2 = exPayload2.programCounter;
    assign bpUpdateTaken2 = redirect2;

    // Extra Signals
    logic [31:0] upperOperand1;
    logic [31:0] upperOperand2;
    logic [31:0] lowerOperand1;
    logic [31:0] lowerOperand2;

    // Ex/Ex Bypass Gen Logic
    assign writebackResult1 = (exPayload1.jumpType != JUMP_NONE || exPayload1.system.CSROp != CSR_NONE)
        ? exPayload1.extraField : result1;
    assign lowerOperand1 = !crossLaneExBypass ? exPayload2.operand1 : (exPayload2.bypassEnable[0] && exPayload2.system.CSROp == CSR_NONE) ? writebackResult1 : exPayload2.operand1;
    assign lowerOperand2 = !crossLaneExBypass ? exPayload2.operand2 : exPayload2.bypassEnable[1] ? writebackResult1 : exPayload2.operand2;

    // Memory Operation Signal for Capacity
    assign exMemory = (exPayload1.memoryOperation != MEM_NONE) && exPayload1.valid && !upperIllegal;

    // Signal Drivers to Store Buffer
    assign inputAddress = result1;
    assign loadWidth = exPayload1.memoryWidth;
    assign loadSigned = exPayload1.memorySigned;

    // Result Calculations
    always_comb begin
        // Base Assignments
        upperOperand1 = exPayload1.operand1;
        upperOperand2 = exPayload1.operand2;
        result1 = '0;
        result2 = '0;
        // Instruction 1 Result
        unique case (exPayload1.aluOperation)
            ALU_ADD: result1 = upperOperand1 + upperOperand2; 
            ALU_SUB: result1 = upperOperand1 - upperOperand2;
            ALU_AND: result1 = upperOperand1 & upperOperand2;
            ALU_OR: result1 = upperOperand1 | upperOperand2;
            ALU_XOR: result1 = upperOperand1 ^ upperOperand2;
            ALU_SLL: result1 = upperOperand1 << upperOperand2[4:0];
            ALU_SRL: result1 = upperOperand1 >> upperOperand2[4:0];
            ALU_SRA: result1 = $signed(upperOperand1) >>> upperOperand2[4:0];
            ALU_SLT: result1 = ($signed(upperOperand1) < $signed(upperOperand2)) ? 32'd1 : 32'd0;
            ALU_SLTU: result1 = (upperOperand1 < upperOperand2) ? 32'd1 : 32'd0;
        endcase
        // Instruction 2 Result
        unique case (exPayload2.aluOperation)
            ALU_ADD: result2 = lowerOperand1 + lowerOperand2; 
            ALU_SUB: result2 = lowerOperand1 - lowerOperand2;
            ALU_AND: result2 = lowerOperand1 & lowerOperand2;
            ALU_OR: result2 = lowerOperand1 | lowerOperand2;
            ALU_XOR: result2 = lowerOperand1 ^ lowerOperand2;
            ALU_SLL: result2 = lowerOperand1 << lowerOperand2[4:0];
            ALU_SRL: result2 = lowerOperand1 >> lowerOperand2[4:0];
            ALU_SRA: result2 = $signed(lowerOperand1) >>> lowerOperand2[4:0];
            ALU_SLT: result2 = ($signed(lowerOperand1) < $signed(lowerOperand2)) ? 32'd1 : 32'd0;
            ALU_SLTU: result2 = (lowerOperand1 < lowerOperand2) ? 32'd1 : 32'd0;
        endcase
    end

    // Redirect Calculations
    always_comb begin
        misTarget1 = 1'd0;
        misTarget2 = 1'd0;

        // Upper Branch Eval, Illegal Gate, and JALR Mask
        redirect1 = 1'd0;
        redirectVector1 = exPayload1.extraField;
        if (exPayload1.valid) begin
            // Branch Evaluation
            unique case (exPayload1.branchType)
                BR_NONE: ;
                BR_EQ: redirect1 = (upperOperand1 == upperOperand2);
                BR_NE: redirect1 = (upperOperand1 != upperOperand2);
                BR_LT: redirect1 = ($signed(upperOperand1) < $signed(upperOperand2));
                BR_GE: redirect1 = ($signed(upperOperand1) >= $signed(upperOperand2));
                BR_LTU: redirect1 = (upperOperand1 < upperOperand2);
                BR_GEU: redirect1 = (upperOperand1 >= upperOperand2);
            endcase
            // Jump Evaluation
            unique case (exPayload1.jumpType)
                JUMP_NONE: ;
                JUMP_JAL: redirect1 = 1'd1;
                JUMP_JALR: redirect1 = 1'd1;
            endcase
        end else begin
            redirect1 = 1'd0;
        end
        // JALR Mask and Misalignment Detection
        if ((exPayload1.jumpType != JUMP_NONE || exPayload1.branchType != BR_NONE) && exPayload1.valid) begin
            if (exPayload1.jumpType == JUMP_JALR) begin
                redirectVector1 = {result1[31:1], 1'b0};
            end else if (exPayload1.jumpType == JUMP_JAL) begin
                redirectVector1 = result1;
            end
            if (redirectVector1[1:0] != 2'b00) begin 
                misTarget1 = 1'b1;
            end
        end

        // Lower Branch Eval, Illegal Gate, and JALR Mask
        redirect2 = 1'd0;
        redirectVector2 = exPayload2.extraField;
        if (exPayload2.valid) begin
            // Branch Evaluation
            unique case (exPayload2.branchType)
                BR_NONE: ;
                BR_EQ: redirect2 = (lowerOperand1 == lowerOperand2);
                BR_NE: redirect2 = (lowerOperand1 != lowerOperand2);
                BR_LT: redirect2 = ($signed(lowerOperand1) < $signed(lowerOperand2));
                BR_GE: redirect2 = ($signed(lowerOperand1) >= $signed(lowerOperand2));
                BR_LTU: redirect2 = (lowerOperand1 < lowerOperand2);
                BR_GEU: redirect2 = (lowerOperand1 >= lowerOperand2);
            endcase
            // Jump Evaluation
            unique case (exPayload2.jumpType)
                JUMP_NONE: ;
                JUMP_JAL: redirect2 = 1'd1;
                JUMP_JALR: redirect2 = 1'd1;
            endcase
        end else begin
            redirect2 = 1'd0;
        end
        // JALR Mask and Misalignment Detection
        if ((exPayload2.jumpType != JUMP_NONE || exPayload2.branchType != BR_NONE) && exPayload2.valid) begin
            if (exPayload2.jumpType == JUMP_JALR) begin
                redirectVector2 = {result2[31:1], 1'b0};
            end else if (exPayload2.jumpType == JUMP_JAL) begin
                redirectVector2 = result2;
            end
            if (redirectVector2[1:0] != 2'b00) begin 
                misTarget2 = 1'b1;
            end
        end
    end

    // Memory Packet Construction
    always_comb begin
        memTrap = 1'b0;
        if (exPayload1.valid && (exPayload1.trapType == NONE) && !(outputValid && exPayload1.memoryOperation == MEM_LOAD)) begin
                unique case (exPayload1.memoryOperation)
                    MEM_NONE: memPayload = '0;
                    MEM_LOAD, MEM_STORE: begin
                        // Address Validity Check
                        if (!accessFault && !misAddress) begin
                            // Payload
                            memPayload.address = result1;
                            memPayload.storeData = exPayload1.extraField;
                            memPayload.memoryOperation = exPayload1.memoryOperation;
                            memPayload.memoryWidth = exPayload1.memoryWidth;
                            memPayload.memorySigned = exPayload1.memorySigned;
                            memPayload.destinationRegister = exPayload1.destinationRegister;
                            memPayload.ageTag = exPayload1.ageTag;
                        end else begin
                            memTrap = 1'b1;
                        end
                    end
                endcase
        end else begin
            memPayload = '0;
        end
    end

    // Final Trap Decision
    TrapType_ finalTrap1;
    TrapType_ finalTrap2;
    always_comb begin
        finalTrap1 = NONE;
        finalTrap2 = NONE;
        // Final Trap 1
        if (exPayload1.trapType != NONE) begin
            finalTrap1 = exPayload1.trapType;
        end else if (misTarget1) begin
            finalTrap1 = MIS_INST;
        end else if (accessFault) begin
            if (exPayload1.memoryOperation == MEM_LOAD) begin
                finalTrap1 = ACCESS_LOAD;
            end else if (exPayload1.memoryOperation == MEM_STORE) begin
                finalTrap1 = ACCESS_STORE;
            end
        end else if (misAddress) begin
            if (exPayload1.memoryOperation == MEM_LOAD) begin
                finalTrap1 = MIS_LOAD;
            end else if (exPayload1.memoryOperation == MEM_STORE) begin
                finalTrap1 = MIS_STORE;
            end
        end
        // Final Trap 2
        if (exPayload2.trapType != NONE) begin
            finalTrap2 = exPayload2.trapType;
        end else if (misTarget2) begin
            finalTrap2 = MIS_INST;
        end
    end

    // Packet Construction
    always_comb begin
        // Packet 1
        resultPayload1 = '0;
        resultPayload1.ageTag = exPayload1.ageTag;
        resultPayload1.csrResult = result1;
        resultPayload1.trapType = finalTrap1;
        if (!(outputValid && exPayload1.memoryOperation == MEM_LOAD)) begin
            if (exPayload1.valid && !reset && (exPayload1.memoryOperation == MEM_NONE || memTrap)) begin
                resultPayload1.accept = 1'd1;
                resultPayload1.destinationRegister = exPayload1.destinationRegister;
                if (exPayload1.jumpType != JUMP_NONE || exPayload1.system.CSROp != CSR_NONE) begin
                    resultPayload1.instructionResult = exPayload1.extraField;
                end else begin
                    resultPayload1.instructionResult = result1;
                end
            end
        end else begin
            if (exPayload1.valid && !reset) begin
                resultPayload1.accept = 1'd1;
                resultPayload1.destinationRegister = exPayload1.destinationRegister;
                resultPayload1.instructionResult = finalOutputData;
            end
        end
        // Packet 2
        resultPayload2 = '0;
        resultPayload2.ageTag = exPayload2.ageTag;
        resultPayload2.csrResult = result2;
        resultPayload2.trapType = finalTrap2;
        if (exPayload2.valid && !(mispredict1) && !reset && !upperIllegal) begin
            resultPayload2.accept = 1'd1;
            resultPayload2.destinationRegister = exPayload2.destinationRegister;
            if (exPayload2.jumpType != JUMP_NONE || exPayload2.system.CSROp != CSR_NONE) begin
                resultPayload2.instructionResult = exPayload2.extraField;
            end else begin
                resultPayload2.instructionResult = result2;
            end
        end
    end

endmodule
