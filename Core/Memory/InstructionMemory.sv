import Configuration::*;
import Payloads::*;
import Enumerations::*;

module InstructionMemory (

    // Standard
    input logic clock,
    input logic reset,
    input logic redirect,
    input logic [31:0] redirectVector,

    // Read Interface (Port A)
    input logic [31:0] readAddressA,
    output logic [127:0] readDataA,

    // Read Interface (Port B)
    input logic [31:0] readAddressB,
    output logic [127:0] readDataB
);

    // 256 x 128-bit instruction memory
    logic [127:0] memory [0:255];

    // Registered indices
    logic [7:0] readIndexA_q;
    logic [7:0] readIndexB_q;

    // Internal Next Window
    logic [31:0] redirectAddress;
    logic [31:0] nextAddress;
    assign redirectAddress = reset ? resetVector : redirectVector;
    assign nextAddress = reset ? resetVector + 32'd16 : redirectVector + 32'd16;

    // Memory Load for Sim
    initial $readmemh("Core/Memory/Instructions.hex", memory);

    // BRAM Inference
    always_ff @(posedge clock) begin
        if (reset || redirect) begin
            readIndexA_q <= redirectAddress[11:4];
            readIndexB_q <= nextAddress[11:4];
            readDataA <= memory[redirectAddress[11:4]];
            readDataB <= memory[nextAddress[11:4]];
        end else begin
            readIndexA_q <= readAddressA[11:4];
            readIndexB_q <= readAddressB[11:4];
            readDataA <= memory[readAddressA[11:4]];
            readDataB <= memory[readAddressB[11:4]];
        end
    end

endmodule

