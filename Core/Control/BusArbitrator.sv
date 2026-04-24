import Configuration::*;
import Payloads::*;
import Enumerations::*;

module BusArbitrator (

    // Master Bus
    input WishboneMaster_ memBusOut,

    // Slave Sources
    input WishboneSlave_ dmemBus,
    input WishboneSlave_ clintBus,

    // Final Slave Output
    output WishboneSlave_ memBusIn

);

    // Bus Decision
    always_comb begin
        memBusIn = '0;
        if (!memBusOut.address[31]) begin
            // Data Memory
            memBusIn = dmemBus;
        end else if (memBusOut.address >= 32'h8000_0000 && memBusOut.address <= 32'h8000_000F) begin
            // CLINT
            memBusIn = clintBus;
        end
    end

endmodule