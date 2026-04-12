package Configuration;

    // Definables
    parameter logic [31:0] resetVector = 32'd0;
    parameter logic debugMode = 1'd0;
    parameter logic autoTest = 1'd1;
    parameter logic crossLaneExBypass = 1'd1;
    parameter int unsigned reorderBufferEntries = 16;
    parameter int unsigned storeBufferEntries = 10;

    // Derivatives
    parameter int unsigned reorderBufferIndexWidth = $clog2(reorderBufferEntries);

endpackage
