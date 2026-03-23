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
    logic redirect1;
    logic redirect2;

    // Redirect Priority Logic
    assign redirect = redirect1 || redirect2;
    assign redirectVector = redirect1 ? exPayload1.extraField : 
    (redirect2 ? exPayload2.extraField : 32'd0);

    // Extra Signals
    logic [31:0] upperOperand1;
    logic [31:0] upperOperand2;
    logic [31:0] lowerOperand1;
    logic [31:0] lowerOperand2;

 

    // Result Calculations
    always_comb begin
        // Base Assignments
        upperOperand1 = exPayload1.operand1;
        upperOperand2 = exPayload1.operand2;
        // Ex/Ex Bypass Gen Logic
        if (!crossLaneExBypass) begin
            lowerOperand1 = exPayload2.operand1;
            lowerOperand2 = exPayload2.operand2;
        end else begin
            lowerOperand1 = exPayload2.bypassEnable[0] ? result1 : exPayload2.operand1;
            lowerOperand2 = exPayload2.bypassEnable[1] ? result1 : exPayload2.operand2;
        end
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
        if (decodeExecutePayload.valid && !executeMemoryControl.flush) begin
            unique case (decodeExecutePayload.branchType)
                BR_EQ: redirect = (brOp1 == brOp2);
                BR_NE: redirect = (brOp1 != brOp2);
                BR_LT: redirect = ($signed(brOp1) < $signed(brOp2));
                BR_GE: redirect = ($signed(brOp1) >= $signed(brOp2));
                BR_LTU: redirect = (brOp1 < brOp2);
                BR_GEU: redirect = (brOp1 >= brOp2);
                default: ;
            endcase
            unique case (decodeExecutePayload.jumpType)
                default:;
                JUMP_JAL: redirect = 1'd1;
                JUMP_JALR: begin
                    redirect = 1'd1;
                end
            endcase
        end else begin
            redirect = 1'd0;
        end
        if ((decodeExecutePayload.jumpType != JUMP_NONE || decodeExecutePayload.branchType != BR_NONE) && (decodeExecutePayload.valid == 1'b1) && (redirect == 1'd1) && (decodeExecutePayload.trapPayload.trapType == NONE)) begin
            if (decodeExecutePayload.jumpType == JUMP_JALR) begin
                branchData = {exPayload1.extraField[31:1], 1'b0};
            end else begin
                branchData = exPayload1.extraField;
            end
            if (branchData[1:0] != 2'b00) begin 
                illegal = 1'b1;
            end
        end
    end

endmodule

// Parameterizable Ex/Ex bypass. must change issuer and ex
// Must forward slot 0 to 1 rs rd