import Configuration::*;
import Payloads::*;
import Enumerations::*;

module BranchPredictor (

    // Standard
    input logic clock, 
    input logic reset, 

    // Input Prediction Metadata
    input logic [31:0] precalcAddress,
    input logic [31:0] branchProgramCounter,
    input logic validAddress,
    input logic outputJal,

    // Taken / Not Taken Signal
    output logic taken

);

    // Support For More Complex Logic
    assign taken = validAddress ? (outputJal ? 1'd1 : (precalcAddress < branchProgramCounter)) : 1'b0;

endmodule