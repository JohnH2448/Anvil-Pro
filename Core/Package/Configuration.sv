package Configuration;

    parameter logic [31:0] resetVector = 32'd0;
    parameter logic crossLaneExBypass = 1'd1;
    parameter int unsigned reorderBufferEntries = 16;
    parameter int unsigned reorderBufferIndexWidth = $clog2(reorderBufferEntries);

endpackage
