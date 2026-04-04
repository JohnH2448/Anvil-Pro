import Configuration::*;
import Payloads::*;
import Enumerations::*;

module ReorderBuffer (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,
    input logic [31:0] redirectVector,

    // Redirect Metadata
    input logic redirect1,
    input logic redirect2,

    // Instruction Inputs
    input InputInstruction_ completedMemory,
    input InputInstruction_ completedInstruction1,
    input InputInstruction_ completedInstruction2,
    input IssuedIntruction_ issuedInstruction1,
    input IssuedIntruction_ issuedInstruction2,

    // Writeback Output
    output RetiredInstruction_ resolvedInstruction1,
    output RetiredInstruction_ resolvedInstruction2,

    // Issuer Control Signals For Decisions
    output logic [1:0] nextFreeSlots,
    output logic [reorderBufferIndexWidth-1:0] freeTag1,
    output logic [reorderBufferIndexWidth-1:0] freeTag2,

    // Store Logic
    input logic storeACK,
    output logic triggerStore,

    // Quad Index Forward Requests From OS
    input logic [reorderBufferIndexWidth-1:0] upperTagIndex1,
    input logic [reorderBufferIndexWidth-1:0] upperTagIndex2,
    input logic [reorderBufferIndexWidth-1:0] lowerTagIndex1,
    input logic [reorderBufferIndexWidth-1:0] lowerTagIndex2,

    // Forward Outputs
    output logic [31:0] upperForward1,
    output logic [31:0] upperForward2,
    output logic [31:0] lowerForward1,
    output logic [31:0] lowerForward2,

    // Restore State Buses to RST
    output RestoreStateBus_ rstBus1,
    output RestoreStateBus_ rstBus2,
    output RestoreStateBus_ rstBus3
    
);

    // Verifies Depth Parameter Value
    initial begin
        if ((reorderBufferEntries & (reorderBufferEntries - 1)) != 0) begin
            $fatal(1, "reorderBufferEntries must be a power of two");
        end
    end


    // Retired Instructions Per Cycle
    logic [1:0] retireCount;
    int debugCycle;

    // Redirect Next Tag
    logic [reorderBufferIndexWidth-1:0] redirectTag;
    assign redirectTag = (redirect1 ? completedInstruction1.ageTag : 
        completedInstruction2.ageTag) + {{reorderBufferIndexWidth-1{1'b0}}, 1'd1};

    // Pointers + Source of Truth + Extra Phase Bit
    logic [reorderBufferIndexWidth:0] headPointer;
    logic [reorderBufferIndexWidth:0] tailPointer;

    // Derived Truncated Pounters for Indexing
    logic [reorderBufferIndexWidth-1:0] headIndexer;
    logic [reorderBufferIndexWidth-1:0] tailIndexer;
    assign headIndexer = headPointer[reorderBufferIndexWidth-1:0];
    assign tailIndexer = tailPointer[reorderBufferIndexWidth-1:0];

    // Phase Bit Recovery Logic for Redirects
    logic wrap;
    logic redirectPhaseBit;
    assign wrap = tailPointer[reorderBufferIndexWidth] != headPointer[reorderBufferIndexWidth];
    always_comb begin
        if (!wrap) begin
            redirectPhaseBit = tailPointer[reorderBufferIndexWidth];
        end else begin
            if (redirectTag <= tailIndexer) begin
                redirectPhaseBit = tailPointer[reorderBufferIndexWidth];
            end else begin
                redirectPhaseBit = headPointer[reorderBufferIndexWidth];
            end
        end
    end

    // Redirect Next Pointer
    logic [reorderBufferIndexWidth:0] redirectPointer;
    assign redirectPointer = {redirectPhaseBit, redirectTag};

    // Next Pointers
    logic [reorderBufferIndexWidth:0] nextHeadPointer;
    logic [reorderBufferIndexWidth:0] nextTailPointer;
    assign nextHeadPointer = headPointer + {{reorderBufferIndexWidth-1{1'b0}}, retireCount};
    assign nextTailPointer = (redirect ? redirectPointer : tailPointer) + 
        {{reorderBufferIndexWidth{1'b0}}, issuedInstruction1.confirm} + 
        {{reorderBufferIndexWidth{1'b0}}, issuedInstruction2.confirm};

    // Derived Truncated Pounters for Indexing
    logic [reorderBufferIndexWidth-1:0] nextHeadIndexer;
    logic [reorderBufferIndexWidth-1:0] nextTailIndexer;
    assign nextHeadIndexer = nextHeadPointer[reorderBufferIndexWidth-1:0];
    assign nextTailIndexer = nextTailPointer[reorderBufferIndexWidth-1:0];

    // Pass Next Age Tags to Issue
    assign freeTag1 = (redirect ? redirectTag : tailIndexer);
    assign freeTag2 = (redirect ? redirectTag : tailIndexer) + 
        {{reorderBufferIndexWidth-1{1'b0}}, 1'd1};

    // Full / Empty Logic
    logic empty; 
    logic full;
    assign empty = headPointer == tailPointer;
    assign full = (headPointer[reorderBufferIndexWidth] != tailPointer[reorderBufferIndexWidth]) &&
       (headPointer[reorderBufferIndexWidth-1:0] == tailPointer[reorderBufferIndexWidth-1:0]);

    // Full Buffer Declaration
    QueueEntry_ reorderBuffer [0:reorderBufferEntries-1];

    // Truncated Next Free Slots Calculation
    logic [reorderBufferIndexWidth:0] usedEntries;
    logic [reorderBufferIndexWidth:0] freeEntries;
    logic moreThanOne;
    always_comb begin
        usedEntries = (redirect ? redirectPointer : tailPointer) - nextHeadPointer;
        freeEntries = (reorderBufferIndexWidth+1)'(reorderBufferEntries) - usedEntries;
        moreThanOne = |freeEntries[reorderBufferIndexWidth:1];
        // 0, 1, or 2+ Slots Available
        nextFreeSlots = {moreThanOne, freeEntries[0]};
    end

    // Reset Logic
    always_ff @(posedge clock) begin
        if (reset) begin
            // For Loop Can Be Deleted
            for (int unsigned i=0; i < reorderBufferEntries; i++) begin
                reorderBuffer[i] <= '0;
            end
            debugCycle <= 0;
            headPointer <= '0;
            tailPointer <= '0;
        end else begin
            debugCycle <= debugCycle + 1;
            headPointer <= nextHeadPointer;
            tailPointer <= nextTailPointer;
        end
    end

    // Accept New Instructions
    logic [reorderBufferIndexWidth-1:0] redirectAdjustedTail;
    assign redirectAdjustedTail = (redirect ? redirectTag : tailIndexer);
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (issuedInstruction1.confirm) begin
                reorderBuffer[redirectAdjustedTail].programCounter <= issuedInstruction1.programCounter;
                reorderBuffer[redirectAdjustedTail].destinationRegister <= issuedInstruction1.destinationRegister;
                reorderBuffer[redirectAdjustedTail].ageTag <= redirectAdjustedTail;
                reorderBuffer[redirectAdjustedTail].isStore <= issuedInstruction1.isStore;
                reorderBuffer[redirectAdjustedTail].completed <= 1'b0;
            end
            if (issuedInstruction2.confirm) begin
                reorderBuffer[redirectAdjustedTail + 'd1].programCounter <= issuedInstruction2.programCounter;
                reorderBuffer[redirectAdjustedTail + 'd1].destinationRegister <= issuedInstruction2.destinationRegister;
                reorderBuffer[redirectAdjustedTail + 'd1].ageTag <= redirectAdjustedTail + 'd1;
                reorderBuffer[redirectAdjustedTail + 'd1].isStore <= issuedInstruction2.isStore;
                reorderBuffer[redirectAdjustedTail + 'd1].completed <= 1'b0;
            end
        end
    end

    // Instruction Resolution
    logic [reorderBufferIndexWidth:0] entries;
    assign entries = tailPointer - headPointer;
    always_comb begin
        resolvedInstruction1 = '0;
        resolvedInstruction2 = '0;
        retireCount = 2'b00;
        triggerStore = 1'd0;
        if ((entries > 'd1) && (reorderBuffer[headIndexer].completed || reorderBuffer[headIndexer].destinationRegister == 5'd0)
        && (reorderBuffer[headIndexer+'d1].completed || reorderBuffer[headIndexer+'d1].destinationRegister == 5'd0)) begin
            // Commit Slot 0 and 1
            retireCount = 2'b10;
            if ((reorderBuffer[headIndexer].destinationRegister != 5'd0) && (reorderBuffer[headIndexer].destinationRegister == reorderBuffer[headIndexer+1].destinationRegister)) begin
                // Packet 1 Gets Packet 2 Data and Drops Packet 2 On Conflict
                resolvedInstruction1.ageTag = reorderBuffer[headIndexer+'d1].ageTag;
                resolvedInstruction1.instructionResult = reorderBuffer[headIndexer+'d1].instructionResult;
                resolvedInstruction1.destinationRegister = reorderBuffer[headIndexer+'d1].destinationRegister;
                resolvedInstruction1.valid = 1'd1; 
            end else begin
                // Slot 0 Packet
                if (reorderBuffer[headIndexer].destinationRegister != 5'd0) begin
                    resolvedInstruction1.ageTag = reorderBuffer[headIndexer].ageTag;
                    resolvedInstruction1.instructionResult = reorderBuffer[headIndexer].instructionResult;
                    resolvedInstruction1.destinationRegister = reorderBuffer[headIndexer].destinationRegister;
                    resolvedInstruction1.valid = 1'd1; 
                end
                // Slot 1 Packet
                if (reorderBuffer[headIndexer+'d1].destinationRegister != 5'd0) begin
                    resolvedInstruction2.ageTag = reorderBuffer[headIndexer+'d1].ageTag;
                    resolvedInstruction2.instructionResult = reorderBuffer[headIndexer+'d1].instructionResult;
                    resolvedInstruction2.destinationRegister = reorderBuffer[headIndexer+'d1].destinationRegister;
                    resolvedInstruction2.valid = 1'd1; 
                end
            end
        end else if ((entries > 5'd0) && (reorderBuffer[headIndexer].completed || reorderBuffer[headIndexer].destinationRegister == 5'd0)) begin
            // Commit Slot 0
            retireCount = 2'b01;
            // Slot 0 Packet
            if (reorderBuffer[headIndexer].destinationRegister != 5'd0) begin
                resolvedInstruction1.ageTag = reorderBuffer[headIndexer].ageTag;
                resolvedInstruction1.instructionResult = reorderBuffer[headIndexer].instructionResult;
                resolvedInstruction1.destinationRegister = reorderBuffer[headIndexer].destinationRegister;
                resolvedInstruction1.valid = 1'd1; 
            end
        end else if ((entries > 5'd0) && reorderBuffer[headIndexer].isStore) begin
            // Launch Store
            triggerStore = 1'd1;
        end
    end

    // Store ACK FSM
    logic outgoingStore;
    always_ff @(posedge clock) begin
        if (reset) begin
            outgoingStore <= 1'd0;
        end else begin
            if (triggerStore && !outgoingStore) begin
                outgoingStore <= 1'd1;
            end
            if (outgoingStore && storeACK) begin
                outgoingStore <= 1'd0;
                reorderBuffer[headIndexer].completed <= 1'd1;
            end
        end
    end
    // also dont need to wait for ack back to retire so long as queue keeps driving it

    // Forward Quad Index Unit
    always_comb begin
        upperForward1 = reorderBuffer[upperTagIndex1].instructionResult;
        upperForward2 = reorderBuffer[upperTagIndex2].instructionResult;
        lowerForward1 = reorderBuffer[lowerTagIndex1].instructionResult;
        lowerForward2 = reorderBuffer[lowerTagIndex2].instructionResult;
    end

    // Write Completed Instructions to ROB
    always_ff @(posedge clock) begin
        if (!reset) begin
            // These Should Never Conflict
            if (completedInstruction1.accept) begin
                reorderBuffer[completedInstruction1.ageTag].instructionResult <= completedInstruction1.instructionResult;
                reorderBuffer[completedInstruction1.ageTag].completed <= 1'b1;
            end
            if (completedInstruction2.accept) begin
                reorderBuffer[completedInstruction2.ageTag].instructionResult <= completedInstruction2.instructionResult;
                reorderBuffer[completedInstruction2.ageTag].completed <= 1'b1;
            end
            if (completedMemory.accept) begin
                reorderBuffer[completedMemory.ageTag].instructionResult <= completedMemory.instructionResult;
                reorderBuffer[completedMemory.ageTag].completed <= 1'b1;
            end
        end
    end


    // Calculate Flush Count 0-3
    logic [1:0] flushCount;
    logic [reorderBufferIndexWidth:0] untruncatedFlushCount;
    assign untruncatedFlushCount = tailPointer - redirectPointer;
    assign flushCount = untruncatedFlushCount[1:0];

    // Truncate Redirect Pointer for Indexing
    logic [reorderBufferIndexWidth-1:0] redirectIndexer;
    assign redirectIndexer = redirectPointer[reorderBufferIndexWidth-1:0];

    // Calculate Flushed Rd Indexes
    logic [4:0] flushDest1;
    logic [4:0] flushDest2;
    logic [4:0] flushDest3;
    assign flushDest1 = reorderBuffer[redirectIndexer].destinationRegister;
    assign flushDest2 = reorderBuffer[redirectIndexer + 'd1].destinationRegister;
    assign flushDest3 = reorderBuffer[redirectIndexer + 'd2].destinationRegister;

    // Positive Distance from New Tail to Every Entry. CAM Select Youngest
    logic [reorderBufferIndexWidth-1:0] sortGrid [0:reorderBufferEntries-1];
    logic maskGrid [0:reorderBufferEntries-1][0:2];
    logic [reorderBufferIndexWidth-1:0] minIndex1;
    logic [reorderBufferIndexWidth-1:0] minIndex2;
    logic [reorderBufferIndexWidth-1:0] minIndex3;
    logic [reorderBufferIndexWidth-1:0] minValue1;
    logic [reorderBufferIndexWidth-1:0] minValue2;
    logic [reorderBufferIndexWidth-1:0] minValue3;
    logic found1;
    logic found2;
    logic found3;
    always_comb begin
        // Distance Grid Builder
        for (int unsigned loop = 0; loop < reorderBufferEntries; loop++) begin
            logic [reorderBufferIndexWidth-1:0] i;
            logic [reorderBufferIndexWidth-1:0] distance;
            i = loop[reorderBufferIndexWidth-1:0];
            distance = redirectIndexer - i;
            sortGrid[i] = distance;
        end
        // Mask Grid Builder
        for (int j = 0; j < 3; j++) begin
            logic [4:0] rd;
            unique case (j)
                0: rd = flushDest1;
                1: rd = flushDest2;
                2: rd = flushDest3;
            endcase
            for (int unsigned loop = 0; loop < reorderBufferEntries; loop++) begin
                logic [reorderBufferIndexWidth-1:0] i;
                i = loop[reorderBufferIndexWidth-1:0];
                maskGrid[i][j] = ((i - nextHeadIndexer) < (redirectIndexer - nextHeadIndexer))
                && (reorderBuffer[i].destinationRegister == (rd));
            end
        end
        // CAM Select Youngest + Pull Index
        minIndex1 = '0;
        minValue1 = '0;
        found1 = 1'b0;
        for (int unsigned i = 0; i < reorderBufferEntries; i++) begin
            if (maskGrid[i][0]) begin
                if (!found1 || (sortGrid[i] < minValue1)) begin
                    minValue1 = sortGrid[i];
                    minIndex1 = i[reorderBufferIndexWidth-1:0];
                    found1 = 1'b1;
                end
            end
        end
        minIndex2 = '0;
        minValue2 = '0;
        found2 = 1'b0;
        for (int unsigned i = 0; i < reorderBufferEntries; i++) begin
            if (maskGrid[i][1]) begin
                if (!found2 || (sortGrid[i] < minValue2)) begin
                    minValue2 = sortGrid[i];
                    minIndex2 = i[reorderBufferIndexWidth-1:0];
                    found2 = 1'b1;
                end
            end
        end
        minIndex3 = '0;
        minValue3 = '0;
        found3 = 1'b0;
        for (int unsigned i = 0; i < reorderBufferEntries; i++) begin
            if (maskGrid[i][2]) begin
                if (!found3 || (sortGrid[i] < minValue3)) begin
                    minValue3 = sortGrid[i];
                    minIndex3 = i[reorderBufferIndexWidth-1:0];
                    found3 = 1'b1;
                end
            end
        end
    end

    // Bus Driver
    always_comb begin
        rstBus1 = '0;
        rstBus2 = '0;
        rstBus3 = '0;
        // Drive Buses When Flush Occurs
        if (redirect) begin
            // Bus 1
            if (flushCount > 2'd0 && (flushDest1 != 5'd0)) begin
                rstBus1.valid = 1'b1;
                rstBus1.destinationRegister = flushDest1;
                rstBus1.ageTag = minIndex1;
                if (found1) begin
                    rstBus1.ready = 1'b1;
                    rstBus1.retired = 1'b0;
                end else begin
                    rstBus1.ready = 1'b1;
                    rstBus1.retired = 1'b1;
                end
            end
            // Bus 2
            if (flushCount > 2'd1 && (flushDest2 != 5'd0) 
                && (flushDest1 != flushDest2)) begin
                rstBus2.valid = 1'b1;
                rstBus2.destinationRegister = flushDest2;
                rstBus2.ageTag = minIndex2;
                if (found2) begin
                    rstBus2.ready = 1'b1;
                    rstBus2.retired = 1'b0;
                end else begin
                    rstBus2.ready = 1'b1;
                    rstBus2.retired = 1'b1;
                end
            end
            // Bus 3
            if (flushCount > 2'd2 && (flushDest3 != 5'd0)
                && (flushDest1 != flushDest3) && (flushDest2 != flushDest3)) begin
                rstBus3.valid = 1'b1;
                rstBus3.destinationRegister = flushDest3;
                rstBus3.ageTag = minIndex3;
                if (found3) begin
                    rstBus3.ready = 1'b1;
                    rstBus3.retired = 1'b0;
                end else begin
                    rstBus3.ready = 1'b1;
                    rstBus3.retired = 1'b1;
                end
            end
        end
    end

    // Can probably reuse this machinary and redirect line for illegal
    // Most stages function the same under illegal vs redirect

    // ROB Debug Print
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (entries == '0) begin
                $display("\n=== ROB Cycle %0d ===\nhead=%0d tail=%0d entries=%0d free=%0d empty\n",
                    debugCycle, headPointer, tailPointer, entries, freeEntries);
            end else begin
                $display("\n=== ROB Cycle %0d ===\nhead=%0d tail=%0d entries=%0d free=%0d\n",
                    debugCycle, headPointer, tailPointer, entries, freeEntries);
                for (int unsigned offset = 0; offset < reorderBufferEntries; offset++) begin
                    logic [reorderBufferIndexWidth-1:0] queueIndex;
                    if (offset < entries) begin
                        queueIndex = headIndexer + reorderBufferIndexWidth'(offset);
                        $display("[%0d] pc=%08h rd=x%0d tag=%0d ready=%0b store=%0b data=%08h",
                            queueIndex,
                            reorderBuffer[queueIndex].programCounter,
                            reorderBuffer[queueIndex].destinationRegister,
                            reorderBuffer[queueIndex].ageTag,
                            reorderBuffer[queueIndex].completed,
                            reorderBuffer[queueIndex].isStore,
                            reorderBuffer[queueIndex].instructionResult);
                    end
                end
            end
        end
    end

endmodule

// STILL NEED: 
// full empty use case missing maybe?
// mem ops must detect illegal before buffer
// robentry[i].ageTag is implicit in index. need to remove that logic



