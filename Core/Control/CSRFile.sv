import Configuration::*;
import Payloads::*;
import Enumerations::*;

module CSRFile (

    // Standard
    input logic clock,
    input logic reset,

    // Read Interface
    input DestinationCSR_ readCSR1,
    output logic [31:0] CSRData1,
    input DestinationCSR_ readCSR2,
    output logic [31:0] CSRData2,

    // Write Interface
    input CSRFilePayload_ csrOut1,
    input CSRFilePayload_ csrOut2,

    // Retire Signals for Increments
    input logic retire1Valid,
    input logic retire2Valid

);

    logic [31:0] CSRFile [0:rMCAUSE];

    // Per CSR Formating
    logic [31:0] correctedWriteData1;
    logic [31:0] correctedWriteData2;
    always_comb begin
        case (csrOut1.destinationCSR)
            rMTVEC: correctedWriteData1 = {csrOut1.csrResult[31:2], 2'b00};
            // ...
            default: correctedWriteData1 = csrOut1.csrResult;
        endcase

        case (csrOut2.destinationCSR)
            rMTVEC: correctedWriteData2 = {csrOut2.csrResult[31:2], 2'b00};
            // ...
            default: correctedWriteData2 = csrOut2.csrResult;
        endcase
    end

    // Read Logic
    always_comb begin
        if (readCSR1 == rMISA) begin
            CSRData1 = 32'h40000100;
        end else if (readCSR1 >= rROZ) begin
            CSRData1 = 32'h00000000;
        end else begin
            CSRData1 = CSRFile[readCSR1];
        end
        if (readCSR2 == rMISA) begin
            CSRData2 = 32'h40000100;
        end else if (readCSR2 >= rROZ) begin
            CSRData2 = 32'h00000000;
        end else begin
            CSRData2 = CSRFile[readCSR2];
        end
    end

    // Write Logic
    always_ff @(posedge clock) begin
        if ((csrOut1.destinationCSR != rMINSTRET)) begin
            if (csrOut1.destinationCSR <= rMISA && csrOut1.CSRWriteIntent) begin
                CSRFile[csrOut1.destinationCSR] <= correctedWriteData1;
            end
        end
        if (csrOut2.destinationCSR != rMINSTRET) begin
            if (csrOut2.destinationCSR <= rMISA && csrOut2.CSRWriteIntent) begin
                CSRFile[csrOut2.destinationCSR] <= correctedWriteData2;
            end
        end
    end

    // Hardware Increments
    always_ff @(posedge clock) begin
        if (reset) begin
            CSRFile[rMCYCLE] <= 32'h00000000;
            CSRFile[rMINSTRET] <= 32'h00000000;
        end else begin
            // Cycle Counter
            if (!(csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMCYCLE) && !(csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMCYCLE)) begin
                CSRFile[rMCYCLE] <= CSRFile[rMCYCLE] + 32'd1;
            end
            // Instruction Retirement Counter
            if ((!(csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && !(csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET))) begin
                CSRFile[rMINSTRET] <= CSRFile[rMINSTRET] + {31'd0, retire1Valid} + {31'd0, retire2Valid};
            end else if (!(csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && (csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET)) begin
                CSRFile[rMINSTRET] <= correctedWriteData2;
            end else if ((csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && !(csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET)) begin
                CSRFile[rMINSTRET] <= correctedWriteData1 + {31'd0, retire2Valid};
            end
        end
    end

endmodule
