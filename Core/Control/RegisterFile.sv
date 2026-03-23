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
    integer debugCycle;

    always_ff @(posedge clock) begin
        if (reset) begin
            debugCycle <= 0;
            for (int i=0; i<32; i++) begin
                registerFile[i] <= '0;
            end
        end else begin
            debugCycle <= debugCycle + 1;
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

    always_ff @(posedge clock) begin
        if (!reset) begin
            $display(
                "\n=== Register File Cycle %0d ===\nx00=%08h  x01=%08h  x02=%08h  x03=%08h\nx04=%08h  x05=%08h  x06=%08h  x07=%08h\nx08=%08h  x09=%08h  x10=%08h  x11=%08h\nx12=%08h  x13=%08h  x14=%08h  x15=%08h\nx16=%08h  x17=%08h  x18=%08h  x19=%08h\nx20=%08h  x21=%08h  x22=%08h  x23=%08h\nx24=%08h  x25=%08h  x26=%08h  x27=%08h\nx28=%08h  x29=%08h  x30=%08h  x31=%08h\n",
                debugCycle,
                registerFile[0], registerFile[1], registerFile[2], registerFile[3],
                registerFile[4], registerFile[5], registerFile[6], registerFile[7],
                registerFile[8], registerFile[9], registerFile[10], registerFile[11],
                registerFile[12], registerFile[13], registerFile[14], registerFile[15],
                registerFile[16], registerFile[17], registerFile[18], registerFile[19],
                registerFile[20], registerFile[21], registerFile[22], registerFile[23],
                registerFile[24], registerFile[25], registerFile[26], registerFile[27],
                registerFile[28], registerFile[29], registerFile[30], registerFile[31]
            );
        end
    end

endmodule
