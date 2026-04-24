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
    input logic retire2Valid,

    // Window Communication
    output logic [31:0] mepc,
    output logic [31:0] mtvec,

    // Exception Metadata
    input logic exceptionTaken,
    input logic [31:0] exceptionPC,
    input TrapType_ exceptionType

);

    // CSR File
    logic [31:0] CSRFile [0:rMCAUSE];

    // CSR Outputs
    assign mepc = CSRFile[rMEPC];
    assign mtvec = CSRFile[rMTVEC];

    // MCAUSE Enumeration Mapping
    logic [3:0] causeCode;
    always_comb begin
        causeCode = 4'd0;
        unique case (exceptionType)
            NONE: causeCode = 4'd0;
            MIS_INST: causeCode = 4'd0;
            ACCESS_INST: causeCode = 4'd1;
            ILLEGAL: causeCode = 4'd2;
            EBREAK: causeCode = 4'd3;
            MIS_LOAD: causeCode = 4'd4;
            ACCESS_LOAD: causeCode = 4'd5;
            MIS_STORE: causeCode = 4'd6;
            ACCESS_STORE: causeCode = 4'd7;
            ECALL: causeCode = 4'd11;
            INTERRUPT: ; // Handled Seperately
        endcase
    end

    // Trap Entry Values
    logic [31:0] trapMstatus;
    logic [31:0] trapMEPC;
    logic [31:0] trapMCAUSE;
    logic [31:0] mretMstatus1;
    logic [31:0] mretMstatus2;
    logic [31:0] mretBaseMstatus2;
    always_comb begin
        trapMstatus = {19'b0, 2'b11, 3'b0, CSRFile[rMSTATUS][3], 3'b0, 1'b0, 3'b0};
        trapMEPC = {exceptionPC[31:2], 2'b00};
        trapMCAUSE = (exceptionType == INTERRUPT)
            ? 32'h80000007
            : {1'b0, 27'd0, causeCode};
    end

    // Per CSR Formatting
    logic [31:0] correctedWriteData1;
    logic [31:0] correctedWriteData2;
    always_comb begin
        case (csrOut1.destinationCSR)
            rMSTATUS: correctedWriteData1 = {19'b0, 2'b11, 3'b0, csrOut1.csrResult[7], 3'b0, csrOut1.csrResult[3], 3'b0};
            rMEPC: correctedWriteData1 = {csrOut1.csrResult[31:2], 2'b00};
            rMTVEC: correctedWriteData1 = {csrOut1.csrResult[31:2], 2'b00};
            rMIE: correctedWriteData1 = {20'b0, csrOut1.csrResult[11], 3'b0, csrOut1.csrResult[7], 3'b0, csrOut1.csrResult[3], 3'b0};
            rMIP: correctedWriteData1 = CSRFile[rMIP];
            default: correctedWriteData1 = csrOut1.csrResult;
        endcase

        case (csrOut2.destinationCSR)
            rMSTATUS: correctedWriteData2 = {19'b0, 2'b11, 3'b0, csrOut2.csrResult[7], 3'b0, csrOut2.csrResult[3], 3'b0};
            rMEPC: correctedWriteData2 = {csrOut2.csrResult[31:2], 2'b00};
            rMTVEC: correctedWriteData2 = {csrOut2.csrResult[31:2], 2'b00};
            rMIE: correctedWriteData2 = {20'b0, csrOut2.csrResult[11], 3'b0, csrOut2.csrResult[7], 3'b0, csrOut2.csrResult[3], 3'b0};
            rMIP: correctedWriteData2 = CSRFile[rMIP];
            default: correctedWriteData2 = csrOut2.csrResult;
        endcase

        mretMstatus1 = {19'b0, 2'b00, 3'b0, 1'b1, 3'b0, CSRFile[rMSTATUS][7], 3'b0};
        mretBaseMstatus2 = ((csrOut1.CSRWriteIntent && (csrOut1.destinationCSR == rMSTATUS))
            ? correctedWriteData1 : CSRFile[rMSTATUS]);
        mretMstatus2 = {19'b0, 2'b00, 3'b0, 1'b1, 3'b0, mretBaseMstatus2[7], 3'b0};
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
        if (reset) begin
            CSRFile[rMSTATUS] <= 32'h00000000;
            CSRFile[rMTVEC] <= 32'h00000000;
            CSRFile[rMIP] <= 32'h00000000;
            CSRFile[rMIE] <= 32'h00000000;
            CSRFile[rMCYCLEH] <= 32'h00000000;
            CSRFile[rMINSTRETH] <= 32'h00000000;
            CSRFile[rMSCRATCH] <= 32'h00000000;
            CSRFile[rMEPC] <= 32'h00000000;
            CSRFile[rMCAUSE] <= 32'h00000000;
        end else begin
            if ((csrOut1.destinationCSR != rMINSTRET)) begin
                if (csrOut1.destinationCSR <= rMCAUSE && csrOut1.CSRWriteIntent) begin
                    CSRFile[csrOut1.destinationCSR] <= correctedWriteData1;
                end
            end
            if (csrOut2.destinationCSR != rMINSTRET) begin
                if (csrOut2.destinationCSR <= rMCAUSE && csrOut2.CSRWriteIntent) begin
                    CSRFile[csrOut2.destinationCSR] <= correctedWriteData2;
                end
            end
            if (exceptionTaken) begin
                CSRFile[rMSTATUS] <= trapMstatus;
                CSRFile[rMEPC] <= trapMEPC;
                CSRFile[rMCAUSE] <= trapMCAUSE;
            end else if (csrOut1.mret) begin
                CSRFile[rMSTATUS] <= mretMstatus1;
            end else if (csrOut2.mret) begin
                CSRFile[rMSTATUS] <= mretMstatus2;
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
            if (!exceptionTaken) begin
                if ((!(csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && !(csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET))) begin
                    CSRFile[rMINSTRET] <= CSRFile[rMINSTRET] + {31'd0, retire1Valid} + {31'd0, retire2Valid};
                end else if (!(csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && (csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET)) begin
                    CSRFile[rMINSTRET] <= correctedWriteData2;
                end else if ((csrOut1.CSRWriteIntent && csrOut1.destinationCSR == rMINSTRET) && !(csrOut2.CSRWriteIntent && csrOut2.destinationCSR == rMINSTRET)) begin
                    CSRFile[rMINSTRET] <= correctedWriteData1 + {31'd0, retire2Valid};
                end
            end
        end
    end

    // Full CSR Debug Print
    always_ff @(negedge clock) begin
        if (!reset && debugMode) begin
            $display("\nCSR File");
            $display("mstatus=%08h mtvec=%08h mip=%08h mie=%08h",
                CSRFile[rMSTATUS], CSRFile[rMTVEC], CSRFile[rMIP], CSRFile[rMIE]);
            $display("mcycle=%08h mcycleh=%08h minstret=%08h minstreth=%08h",
                CSRFile[rMCYCLE], CSRFile[rMCYCLEH], CSRFile[rMINSTRET], CSRFile[rMINSTRETH]);
            $display("mscratch=%08h mepc=%08h mcause=%08h misa=%08h",
                CSRFile[rMSCRATCH], CSRFile[rMEPC], CSRFile[rMCAUSE], 32'h40000100);
        end
    end

endmodule
