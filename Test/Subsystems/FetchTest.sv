import Configuration::*;
import Payloads::*;
import Enumerations::*;

// Memory Queue and BRAM Test Module
module Top (
    input logic clock,
    input logic reset,
    input logic redirect,
    input logic instructionConsumed1,
    input logic instructionConsumed2
);

    // Static Redirect Vector for Testing
    logic [31:0] redirectVector;
    assign redirectVector = 32'd40;

    // Queue Driven Signals
    logic [31:0] alignedAddress;
    logic [31:0] instruction1;
    logic [31:0] instruction2;
    logic instructionReady1;
    logic instructionReady2;

    // BRAM Driven Signals
    logic instructionFetchDataValid;
    logic [127:0] instructionFetchData;

    PrefetchQueue prefetchQueue (
        .clock (clock),
        .reset (reset),
        .redirect (redirect),
        .redirectVector (redirectVector),
        .instructionFetchData (instructionFetchData),
        .instructionFetchDataValid (instructionFetchDataValid),
        .alignedAddress (alignedAddress),
        .instruction1 (instruction1),
        .instructionReady1 (instructionReady1),
        .instruction2 (instruction2),
        .instructionReady2 (instructionReady2),
        .instructionConsumed1 (instructionConsumed1),
        .instructionConsumed2 (instructionConsumed2)
    );

    InstructionMemory instructionMemory (
        .clock (clock),
        .reset (reset),
        .redirect (redirect),
        .readData (instructionFetchData),
        .readValid (instructionFetchDataValid),
        .readAddress (alignedAddress)
    );

endmodule 
