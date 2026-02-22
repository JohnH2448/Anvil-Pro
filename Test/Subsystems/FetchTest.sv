import Configuration::*;
import Payloads::*;
import Enumerations::*;

// Memory Queue and BRAM Test Module
module Top (
    input logic clock,
    input logic reset,
    input logic redirect,
    input logic assert1,
    input logic assert2,
    output logic [31:0] instruction1,
    output logic [31:0] instruction2
);

    // Static Redirect Vector for Testing
    logic [31:0] redirectVector;
    assign redirectVector = 32'd40;

    // BRAM Driven Signals
    logic [127:0] lowFetchData;
    logic [127:0] highFetchData;

    // Load Address Lines
    logic [31:0] lowFetchAddress;
    logic [31:0] highFetchAddress;

    // Program Counter Outputs
    logic [31:0] programCounter;
    logic [31:0] programCounterP4;

    // Fetch from Walking Window
    logic [31:0] requestPC1;
    logic [31:0] requestPC2;

    // Bad Data
    logic badData;

    WalkingWindow walkingWindow (
        .clock (clock),
        .reset (reset),
        .redirect (redirect),
        .redirectVector (redirectVector),
        .lowFetchData (lowFetchData),
        .highFetchData (highFetchData),
        .lowFetchAddress (lowFetchAddress),
        .highFetchAddress (highFetchAddress),
        .instruction1 (instruction1),
        .instruction2 (instruction2),
        .instructionConsumed1 (instructionConsumed1),
        .instructionConsumed2 (instructionConsumed2),
        .programCounter (programCounter),
        .requestPC1 (requestPC1),
        .requestPC2 (requestPC2),
        .badData (badData)
    );

    InstructionMemory instructionMemory (
        .clock (clock),
        .reset (reset),
        .redirect (redirect),
        .redirectVector (redirectVector),
        .readAddressA (lowFetchAddress),
        .readDataA (lowFetchData),
        .readAddressB (highFetchAddress),
        .readDataB (highFetchData)
    );

    DecodeIssue decodeIssue (
        .clock (clock),
        .reset (reset),
        .redirect (redirect),
        .redirectVector (redirectVector),
        .instruction1 (instruction1),
        .instruction2 (instruction2),
        .assert1 (assert1),
        .assert2 (assert2),
        .programCounter (programCounter),
        .instructionConsumed1 (instructionConsumed1),
        .instructionConsumed2 (instructionConsumed2),
        .requestPC1 (requestPC1),
        .requestPC2 (requestPC2),
        .badData (badData)
    );


endmodule
