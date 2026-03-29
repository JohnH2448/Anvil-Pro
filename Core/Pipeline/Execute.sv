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

    // Redirect Metadata for ROB
    output logic redirect1,
    output logic redirect2,

    // Payloads to Execute
    input UpperOperandExecutePayload_ exPayload1,
    input LowerOperandExecutePayload_ exPayload2,

    // To Memory Queue
    output ExecuteMemoryPayload_ memPayload,

    // To ROB
    output InputInstruction_ resultPayload1,
    output InputInstruction_ resultPayload2

);

    logic [31:0] result1;
    logic [31:0] result2;
    logic [31:0] redirectVector1;
    logic [31:0] redirectVector2;
    logic illegal1;
    logic illegal2;
    integer debugCycle;

    // Redirect Priority Logic
    assign redirect = (redirect1 && !illegal1) || (redirect2 && !illegal2);
    assign redirectVector = (redirect1 && !illegal1) ? redirectVector1 : 
    ((redirect2 && !illegal2) ? redirectVector2 : 32'd0);

    // Extra Signals
    logic [31:0] upperOperand1;
    logic [31:0] upperOperand2;
    logic [31:0] lowerOperand1;
    logic [31:0] lowerOperand2;

    // Ex/Ex Bypass Gen Logic
    assign lowerOperand1 = !crossLaneExBypass ? exPayload2.operand1 : exPayload2.bypassEnable[0] ? result1 : exPayload2.operand1;
    assign lowerOperand2 = !crossLaneExBypass ? exPayload2.operand2 : exPayload2.bypassEnable[1] ? result1 : exPayload2.operand2;

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
        illegal1 = 1'd0;
        illegal2 = 1'd0;

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
                illegal1 = 1'b1;
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
                illegal2 = 1'b1;
            end
        end
    end

    // Packet Construction
    always_comb begin
        // Packet 1
        resultPayload1 = '0;
        resultPayload1.ageTag = exPayload1.ageTag;
        if (exPayload1.valid && !reset) begin
            resultPayload1.accept = 1'd1;
            resultPayload1.destinationRegister = exPayload1.destinationRegister;
            if (exPayload1.jumpType != JUMP_NONE) begin
                resultPayload1.instructionResult = exPayload1.extraField;
            end else begin
                resultPayload1.instructionResult = result1;
            end
        end
        // Packet 2
        resultPayload2 = '0;
        resultPayload2.ageTag = exPayload2.ageTag;
        if (exPayload2.valid && !(redirect1 && !illegal1) && !reset) begin
            resultPayload2.accept = 1'd1;
            resultPayload2.destinationRegister = exPayload2.destinationRegister;
            if (exPayload2.jumpType != JUMP_NONE) begin
                resultPayload2.instructionResult = exPayload2.extraField;
            end else begin
                resultPayload2.instructionResult = result2;
            end
        end
    end

    // Independent Execute Trace
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (exPayload1.valid) begin
                $display("[Execute] slot0 op=%0d a=%08h b=%08h -> %08h",
                    exPayload1.aluOperation, upperOperand1, upperOperand2, result1);
            end
            if (exPayload2.valid) begin
                $display("[Execute] slot1 op=%0d a=%08h b=%08h -> %08h bypass=%02b",
                    exPayload2.aluOperation, lowerOperand1, lowerOperand2, result2, exPayload2.bypassEnable);
            end
        end
    end

endmodule

