import Configuration::*;
import Payloads::*;
import Enumerations::*;

module PlaceholderDMEM #(
    parameter int unsigned memoryWords = 1024,
    parameter int unsigned ackDelay = 5
) (

    // Standard
    input logic clock,
    input logic reset,

    // Wishbone Bus
    input WishboneMaster_ memBusOut,
    output WishboneSlave_ memBusIn

);

    localparam integer delayCounterWidth = (ackDelay > 0) ? $clog2(ackDelay + 1) : 1;
    localparam integer memoryIndexWidth = (memoryWords > 1) ? $clog2(memoryWords) : 1;

    logic [31:0] memory [0:memoryWords-1];
    integer debugCycle;

    WishboneSlave_ memBusInRegister;
    assign memBusIn = memBusInRegister;

    logic requestPending;
    logic [31:0] latchedAddress;
    logic [31:0] latchedStoreData;
    logic latchedWriteEnable;
    logic [3:0] latchedByteSelect;
    logic [delayCounterWidth-1:0] delayCounter;

    logic validRequest;
    assign validRequest = memBusOut.cycle && memBusOut.strobe;

    always_ff @(posedge clock) begin
        if (reset) begin
            debugCycle <= 0;
            memBusInRegister <= '0;
            requestPending <= 1'b0;
            latchedAddress <= '0;
            latchedStoreData <= '0;
            latchedWriteEnable <= 1'b0;
            latchedByteSelect <= '0;
            delayCounter <= '0;
            for (int unsigned i=0; i<memoryWords; i++) begin
                memory[i] = '0;
            end
        end else begin
            debugCycle <= debugCycle + 1;
            memBusInRegister.acknowledge <= 1'b0;

            if (!requestPending && validRequest) begin
                requestPending <= 1'b1;
                latchedAddress <= memBusOut.address;
                latchedStoreData <= memBusOut.storeData;
                latchedWriteEnable <= memBusOut.writeEnable;
                latchedByteSelect <= memBusOut.byteSelect;
                delayCounter <= delayCounterWidth'(ackDelay);
            end else if (requestPending) begin
                logic [memoryIndexWidth-1:0] wordIndex;
                logic [31:0] nextLoadData;

                wordIndex = latchedAddress[memoryIndexWidth+1:2];
                nextLoadData = memory[wordIndex];

                if (delayCounter != '0) begin
                    delayCounter <= delayCounter - 1'b1;
                end else begin
                    if (latchedWriteEnable) begin
                        if (latchedByteSelect[0]) begin
                            memory[wordIndex][7:0] <= latchedStoreData[7:0];
                            nextLoadData[7:0] = latchedStoreData[7:0];
                        end
                        if (latchedByteSelect[1]) begin
                            memory[wordIndex][15:8] <= latchedStoreData[15:8];
                            nextLoadData[15:8] = latchedStoreData[15:8];
                        end
                        if (latchedByteSelect[2]) begin
                            memory[wordIndex][23:16] <= latchedStoreData[23:16];
                            nextLoadData[23:16] = latchedStoreData[23:16];
                        end
                        if (latchedByteSelect[3]) begin
                            memory[wordIndex][31:24] <= latchedStoreData[31:24];
                            nextLoadData[31:24] = latchedStoreData[31:24];
                        end
                    end

                    memBusInRegister.loadData <= nextLoadData;
                    memBusInRegister.acknowledge <= 1'b1;
                    requestPending <= 1'b0;
                end
            end
        end
    end

endmodule
