import Configuration::*;

(* keep_hierarchy = "yes" *)
module SynthTinyIMEM #(
    parameter int unsigned imemLines = 16
) (
    input logic clock,

    input logic [31:0] readAddressA,
    output logic [127:0] readDataA,
    input logic [31:0] readAddressB,
    output logic [127:0] readDataB
);

    localparam int unsigned imemIndexWidth = (imemLines > 1) ? $clog2(imemLines) : 1;

    (* ram_style = "block", keep = "true" *)
    logic [127:0] memory [0:imemLines-1];

    logic [imemIndexWidth-1:0] readIndexA;
    logic [imemIndexWidth-1:0] readIndexB;

    assign readIndexA = readAddressA[imemIndexWidth+3:4];
    assign readIndexB = readAddressB[imemIndexWidth+3:4];

    initial begin
        for (int unsigned i = 0; i < imemLines; i++) begin
            memory[i] = {32'h0000_0013, 32'h0000_0013, 32'h0000_0013, 32'h0000_0013};
        end
    end

    always_ff @(posedge clock) begin
        readDataA <= memory[readIndexA];
        readDataB <= memory[readIndexB];
    end

endmodule
