package Configuration;

    // Definables
    parameter logic [31:0] resetVector = 32'd0;
    parameter logic debugMode = 1'd0;
    parameter logic autoTest = 1'd1;
    parameter logic crossLaneExBypass = 1'd1;
    parameter int unsigned reorderBufferEntries = 16;
    parameter int unsigned storeBufferEntries = 10;
    parameter logic [31:0] iUpperBound = 32'h0000_1000; // exclusive
    parameter logic [31:0] iLowerBound = 32'h0000_0000; // inclusive
    parameter logic [31:0] dUpperBound = 32'h0000_1000; // exclusive
    parameter logic [31:0] dLowerBound = 32'h0000_0000; // inclusive

    // Derivatives
    parameter int unsigned reorderBufferIndexWidth = $clog2(reorderBufferEntries);

endpackage
