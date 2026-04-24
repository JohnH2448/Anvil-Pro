import Configuration::*;
import Payloads::*;
import Enumerations::*;

module InterruptController (

    input logic clock,
    input logic reset,

    input logic interruptTaken,
    output logic interrupt

);

    assign interrupt = 1'b0;
    
endmodule