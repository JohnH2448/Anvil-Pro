import Configuration::*;
import Payloads::*;
import Enumerations::*;

module RegisterFile (

    // Standard
    input logic clock,
    input logic reset,

    // Read Addresses
    input logic [4:0] upperSourceRegister1,
    input logic [4:0] upperSourceRegister2,
    input logic [4:0] lowerSourceRegister1,
    input logic [4:0] lowerSourceRegister2,

    // Read Data
    output logic [31:0] upperSourceData1,
    output logic [31:0] upperSourceData2,
    output logic [31:0] lowerSourceData1,
    output logic [31:0] lowerSourceData2,

    // Retire Writes
    input RetiredInstruction_ resolvedInstruction1,
    input RetiredInstruction_ resolvedInstruction2
);

    logic [31:0] registerFile [0:31];

    always_ff @(posedge clock) begin
        if (reset) begin
            for (int i=0; i<32; i++) begin
                registerFile[i] <= '0;
            end
        end else begin
            if (resolvedInstruction1.valid && resolvedInstruction1.destinationRegister != 5'd0) begin
                registerFile[resolvedInstruction1.destinationRegister] <= resolvedInstruction1.instructionResult;
            end
            if (resolvedInstruction2.valid && resolvedInstruction2.destinationRegister != 5'd0) begin
                registerFile[resolvedInstruction2.destinationRegister] <= resolvedInstruction2.instructionResult;
            end
            registerFile[5'd0] <= '0;
        end
    end

    always_comb begin
        if (upperSourceRegister1 != 5'd0) begin
            upperSourceData1 = registerFile[upperSourceRegister1];
        end else begin
            upperSourceData1 = '0;
        end
        if (upperSourceRegister2 != 5'd0) begin
            upperSourceData2 = registerFile[upperSourceRegister2];
        end else begin
            upperSourceData2 = '0;
        end
        if (lowerSourceRegister1 != 5'd0) begin
            lowerSourceData1 = registerFile[lowerSourceRegister1];
        end else begin
            lowerSourceData1 = '0;
        end
        if (lowerSourceRegister2 != 5'd0) begin
            lowerSourceData2 = registerFile[lowerSourceRegister2];
        end else begin
            lowerSourceData2 = '0;
        end
    end

endmodule
