import Configuration::*;
import Payloads::*;
import Enumerations::*;

module BusArbitrator (

    // Master Bus
    input WishboneMaster_ memBusOut,
    input logic dmemSelect,
    input logic clintSelect,

    // Slave Sources
    input WishboneSlave_ dmemBus,
    input WishboneSlave_ clintBus,

    // Final Slave Output
    output WishboneSlave_ memBusIn

);

    // Bus Decision
    always_comb begin
        memBusIn = '0;
        if (dmemSelect) begin
            // Data Memory
            memBusIn = dmemBus;
        end else if (clintSelect) begin
            // CLINT
            memBusIn = clintBus;
        end
    end

endmodule
