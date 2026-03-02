import Configuration::*;
import Payloads::*;
import Enumerations::*;

module Decoder (
    input logic [31:0] instruction,
    input logic [31:0] programCounter,
    output UpperIssuerOperandPayload_ payload,
    output logic [4:0] destinationRegister,
    output logic illegal
);

    // Opcode Cast
    Opcode_ opcode;
    assign opcode = Opcode_'(instruction[6:0]);

    // Full Decode
    always_comb begin
        // Zero Payloads
        payload = '0;
        payload.programCounter = programCounter;
        illegal = 1'b0;
        destinationRegister = '0;

        case (opcode)

            OPCODE_ALU_REG: begin
                destinationRegister = instruction[11:7];
                payload.sourceRegister1 = instruction[19:15];
                payload.sourceRegister2 = instruction[24:20];
                // ALU Operation Decoding
                case ({instruction[31:25], instruction[14:12]})
                    10'b0000000000: payload.aluOperation = ALU_ADD;
                    10'b0100000000: payload.aluOperation = ALU_SUB;
                    10'b0000000111: payload.aluOperation = ALU_AND;
                    10'b0000000110: payload.aluOperation = ALU_OR;
                    10'b0000000100: payload.aluOperation = ALU_XOR;
                    10'b0000000001: payload.aluOperation = ALU_SLL;
                    10'b0000000010: payload.aluOperation = ALU_SRL;
                    10'b0100000010: payload.aluOperation = ALU_SRA;
                    10'b0000000011: payload.aluOperation = ALU_SLT;
                    10'b0000001011: payload.aluOperation = ALU_SLTU;
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_MISC_MEM: begin
                // Fence Types
                case (instruction[14:12])
                    3'b000: begin
                        // NOP FENCE
                    end
                    3'b001: begin
                        // NOP FENCE.I
                    end
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_ALU_IMM: begin
                destinationRegister = instruction[11:7];
                payload.sourceRegister1 = instruction[19:15];
                payload.aluSource = ALU_RS1_IMM;
                payload.immediate = {{20{instruction[31]}}, instruction[31:20]};
                // ALU Operation Decoding
                case (instruction[14:12])
                    3'b000: payload.aluOperation = ALU_ADD;
                    3'b010: payload.aluOperation = ALU_SLT;
                    3'b011: payload.aluOperation = ALU_SLTU;
                    3'b100: payload.aluOperation = ALU_XOR;
                    3'b110: payload.aluOperation = ALU_OR;
                    3'b111: payload.aluOperation = ALU_AND;
                    // Special Encoding for Shifts
                    3'b001: begin
                        if (instruction[31:25] == 7'b0000000) begin
                            payload.aluOperation = ALU_SLL;
                        end else begin
                            illegal = 1'b1;
                        end
                    end
                    3'b101: begin
                        if (instruction[31:25] == 7'b0000000) begin
                            payload.aluOperation = ALU_SRL;
                        end else if (instruction[31:25] == 7'b0100000) begin
                            payload.aluOperation = ALU_SRA;
                        end else begin
                            illegal = 1'b1;
                        end
                    end
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_LOAD: begin
                destinationRegister = instruction[11:7];
                payload.sourceRegister1 = instruction[19:15];
                payload.aluSource = ALU_RS1_IMM;
                payload.immediate = {{20{instruction[31]}}, instruction[31:20]};
                payload.memoryOperation = MEM_LOAD;
                // Memory Width and Sign Decoding
                case (instruction[14:12]) 
                    3'b000: begin
                        payload.memoryWidth = 2'b00;
                        payload.memorySigned = 1'b1;
                    end
                    3'b001: begin
                        payload.memoryWidth = 2'b01;
                        payload.memorySigned = 1'b1;
                    end
                    3'b010: begin
                        payload.memoryWidth = 2'b11;
                        payload.memorySigned = 1'b1;
                    end
                    3'b100: begin
                        payload.memoryWidth = 2'b00;
                        payload.memorySigned = 1'b0;
                    end
                    3'b101: begin
                        payload.memoryWidth = 2'b01;
                        payload.memorySigned = 1'b0;
                    end
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_STORE: begin
                payload.sourceRegister1 = instruction[19:15];
                payload.sourceRegister2 = instruction[24:20];
                payload.aluSource = ALU_RS1_IMM;
                payload.immediate = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
                payload.memoryOperation = MEM_STORE;
                // Memory Width Decoding
                case (instruction[14:12])
                    3'b000: payload.memoryWidth = 2'b00;
                    3'b001: payload.memoryWidth = 2'b01;
                    3'b010: payload.memoryWidth = 2'b11;
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_BRANCH: begin
                payload.sourceRegister1 = instruction[19:15];
                payload.sourceRegister2 = instruction[24:20];
                payload.aluSource = ALU_RS1_IMM;
                payload.immediate = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0};
                // Branch Type Decoding
                case (instruction[14:12])
                    3'b000: payload.branchType = BR_EQ;
                    3'b001: payload.branchType = BR_NE;
                    3'b100: payload.branchType = BR_LT;
                    3'b101: payload.branchType = BR_GE;
                    3'b110: payload.branchType = BR_LTU;
                    3'b111: payload.branchType = BR_GEU;
                    default: illegal = 1'b1;
                endcase
            end

            OPCODE_LUI: begin
                destinationRegister = instruction[11:7];
                // ALU Passthrough
                payload.aluSource = ALU_ZERO_IMM;
                payload.immediate = {instruction[31:12], 12'd0};
            end

            OPCODE_AUIPC: begin
                destinationRegister = instruction[11:7];
                payload.aluSource = ALU_PC_IMM;
                payload.immediate = {instruction[31:12], 12'd0};
            end

            OPCODE_JAL: begin
                destinationRegister = instruction[11:7];
                payload.aluSource = ALU_PC_IMM;
                payload.jumpType = JUMP_JAL;
                payload.immediate = {{12{instruction[31]}},instruction[19:12],instruction[20],instruction[30:21],1'b0};
            end

            OPCODE_JALR: begin
                payload.sourceRegister1 = instruction[19:15];
                destinationRegister = instruction[11:7];
                payload.aluSource = ALU_RS1_IMM;
                payload.jumpType = JUMP_JALR;
                payload.immediate = {{20{instruction[31]}},instruction[31:20]};
                if (instruction[14:12] != 2'b000) begin
                    illegal = 1'b1;
                end
            end

            OPCODE_SYSTEM: begin
                // CSR / ecall / ebreak
            end

            default: begin
                illegal = 1'b1;
            end

        endcase
        // Age Tags + Valid Assigned By Issuer
    end

endmodule
