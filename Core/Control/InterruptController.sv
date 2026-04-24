import Configuration::*;
import Payloads::*;
import Enumerations::*;

module InterruptController (

    // Standard
    input logic clock,
    input logic reset,

    // Timer Output
    output logic timerFull,

    // Metadata
    input logic mstatusMIE,
    input logic mieMTIE,
    output logic interrupt,

    // Bus Interface for CLINT
    input WishboneMaster_ memBusOut,
    output WishboneSlave_ clintBus

);

    // Output Bus
    WishboneSlave_ clintBusRegister;
    assign clintBus = clintBusRegister;

    // CLINT Registers
    logic [63:0] mtime;
    logic [63:0] mtimecmp;

    assign interrupt = mstatusMIE && mieMTIE && timerFull;

    logic latchedWriteEnable;

    // Bus Behavior
    logic validRequest;
    logic requestPending;
    logic [31:0] latchedAddress;
    logic [31:0] latchedStoreData;
    logic [3:0] latchedByteSelect;
    logic [31:0] nextReadData;

    assign timerFull = (mtime >= mtimecmp);
    assign validRequest = memBusOut.cycle && memBusOut.strobe && !clintBusRegister.acknowledge;

    always_comb begin
        unique case (latchedAddress[3:2])
            2'b00: nextReadData = mtimecmp[31:0];
            2'b01: nextReadData = mtimecmp[63:32];
            2'b10: nextReadData = mtime[31:0];
            2'b11: nextReadData = mtime[63:32];
        endcase
    end

    always_ff @(posedge clock) begin
        if (reset) begin
            clintBusRegister <= '0;
            requestPending <= 1'b0;
            latchedAddress <= '0;
            latchedStoreData <= '0;
            latchedWriteEnable <= 1'b0;
            latchedByteSelect <= '0;
            mtime <= '0;
            mtimecmp <= 64'hFFFF_FFFF_FFFF_FFFF;
        end else begin
            clintBusRegister.acknowledge <= 1'b0;

            if (!(requestPending && latchedWriteEnable &&
                ((latchedAddress[3:2] == 2'b10) || (latchedAddress[3:2] == 2'b11)))) begin
                mtime <= mtime + 64'd1;
            end

            if (!requestPending && validRequest
            && memBusOut.address >= 32'h8000_0000 && memBusOut.address <= 32'h8000_000F) begin
                requestPending <= 1'b1;
                latchedAddress <= memBusOut.address;
                latchedStoreData <= memBusOut.storeData;
                latchedWriteEnable <= memBusOut.writeEnable;
                latchedByteSelect <= memBusOut.byteSelect;
            end else if (requestPending) begin
                logic [31:0] mergedData;

                mergedData = nextReadData;
                if (latchedWriteEnable) begin
                    if (latchedByteSelect[0]) begin
                        mergedData[7:0] = latchedStoreData[7:0];
                    end
                    if (latchedByteSelect[1]) begin
                        mergedData[15:8] = latchedStoreData[15:8];
                    end
                    if (latchedByteSelect[2]) begin
                        mergedData[23:16] = latchedStoreData[23:16];
                    end
                    if (latchedByteSelect[3]) begin
                        mergedData[31:24] = latchedStoreData[31:24];
                    end

                    unique case (latchedAddress[3:2])
                        2'b00: mtimecmp[31:0] <= mergedData;
                        2'b01: mtimecmp[63:32] <= mergedData;
                        2'b10: mtime[31:0] <= mergedData;
                        2'b11: mtime[63:32] <= mergedData;
                    endcase
                end

                clintBusRegister.loadData <= mergedData;
                clintBusRegister.acknowledge <= 1'b1;
                requestPending <= 1'b0;
            end
        end 
    end

    always_ff @(negedge clock) begin
        if (!reset && debugMode) begin
            $display("\nCLINT");
            $display("mtime=%016h mtimecmp=%016h", mtime, mtimecmp);
            $display("Interrupt=%b", interrupt);
            $display("MTIE=%b MIE=%b", mieMTIE, mstatusMIE);
            $display("timerFull=%b", timerFull);
        end
    end

endmodule
