import Configuration::*;
import Payloads::*;
import Enumerations::*;

module ReorderBuffer (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,

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
    output logic [width-1:0] freeTag1,
    output logic [width-1:0] freeTag2,

    // Store Logic
    input logic storeACK,
    output logic triggerStore,

    // Quad Index Forward Requests From OS
    input logic [width-1:0] upperTagIndex1,
    input logic [width-1:0] upperTagIndex2,
    input logic [width-1:0] lowerTagIndex1,
    input logic [width-1:0] lowerTagIndex2,

    // Forward Outputs
    output logic [31:0] upperForward1,
    output logic [31:0] upperForward2,
    output logic [31:0] lowerForward1,
    output logic [31:0] lowerForward2
);

    // Verifies Depth Parameter Value
    initial begin
        if ((reorderBufferEntries & (reorderBufferEntries - 1)) != 0) begin
            $fatal(1, "reorderBufferEntries must be a power of two");
        end
    end

    // Helper Constants
    localparam int width = $clog2(reorderBufferEntries);

    // Retired Instructions Per Cycle
    logic [1:0] retireCount;

    // Redirect Next Tag
    logic [width-1:0] redirectTag;
    assign redirectTag = (redirect1 ? completedInstruction1.ageTag : 
        completedInstruction2.ageTag) + {{width-1{1'b0}}, 1'd1};

    // Pointers + Source of Truth + Extra Phase Bit
    logic [width:0] headPointer;
    logic [width:0] tailPointer;

    // Derived Truncated Pounters for Indexing
    logic [width-1:0] headIndexer;
    logic [width-1:0] tailIndexer;
    assign headIndexer = headPointer[width-1:0];
    assign tailIndexer = tailPointer[width-1:0];

    // Phase Bit Recovery Logic for Redirects
    logic wrap;
    logic redirectPhaseBit;
    assign wrap = tailPointer[width] != headPointer[width];
    always_comb begin
        if (!wrap) begin
            redirectPhaseBit = tailPointer[width];
        end else begin
            if (redirectTag < tailIndexer) begin
                redirectPhaseBit = tailPointer[width];
            end else begin
                redirectPhaseBit = headPointer[width];
            end
        end
    end

    // Redirect Next Pointer
    logic [width:0] redirectPointer;
    assign redirectPointer = {redirectPhaseBit, redirectTag};

    // Next Pointers
    logic [width:0] nextHeadPointer;
    logic [width:0] nextTailPointer;
    assign nextHeadPointer = headPointer + {{width-1{1'b0}}, retireCount};
    assign nextTailPointer = (redirect ? redirectPointer : tailPointer) + 
        {{width{1'b0}}, issuedInstruction1.confirm} + 
        {{width{1'b0}}, issuedInstruction2.confirm};

    // Derived Truncated Pounters for Indexing
    logic [width-1:0] nextHeadIndexer;
    logic [width-1:0] nextTailIndexer;
    assign nextHeadIndexer = nextHeadPointer[width-1:0];
    assign nextTailIndexer = nextTailPointer[width-1:0];

    // Pass Next Age Tags to Issue
    assign freeTag1 = (redirect ? redirectTag : tailIndexer);
    assign freeTag2 = (redirect ? redirectTag : tailIndexer) + 
        {{width-1{1'b0}}, 1'd1};

    // Full / Empty Logic
    logic empty; 
    logic full; // 0 = empty, 1 = full
    assign empty = headPointer == tailPointer;
    assign full = (headPointer[width] != tailPointer[width]) &&
       (headPointer[width-1:0] == tailPointer[width-1:0]);

    // Full Buffer Declaration
    QueueEntry_ reorderBuffer [0:reorderBufferEntries-1];

    // Truncated Next Free Slots Calculation
    logic [width:0] usedEntries;
    logic [width:0] freeEntries;
    logic moreThanOne;
    always_comb begin
        usedEntries = tailPointer - headPointer;
        freeEntries = (width+1)'(reorderBufferEntries) - usedEntries;
        moreThanOne = |freeEntries[width-1:1];
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
            headPointer <= '0;
            tailPointer <= '0;
        end
    end

    // Update Pointers
    always_ff @(posedge clock) begin
        headPointer <= nextHeadPointer;
        tailPointer <= nextTailPointer;
    end

    // Accept New Instructions
    logic [width-1:0] redirectAdjustedTail;
    assign redirectAdjustedTail = (redirect ? redirectTag : tailIndexer);
    always_ff @(posedge clock) begin
        if (!reset) begin
            if (issuedInstruction1.confirm) begin
                reorderBuffer[redirectAdjustedTail].programCounter <= issuedInstruction1.programCounter;
                reorderBuffer[redirectAdjustedTail].destinationRegister <= issuedInstruction1.destinationRegister;
                reorderBuffer[redirectAdjustedTail].ageTag <= issuedInstruction1.ageTag;
                reorderBuffer[redirectAdjustedTail].isStore <= issuedInstruction1.isStore;
                reorderBuffer[redirectAdjustedTail].completed <= 1'b0;
            end
            if (issuedInstruction2.confirm) begin
                reorderBuffer[redirectAdjustedTail+ 'd1].programCounter <= issuedInstruction2.programCounter;
                reorderBuffer[redirectAdjustedTail+ 'd1].destinationRegister <= issuedInstruction2.destinationRegister;
                reorderBuffer[redirectAdjustedTail+ 'd1].ageTag <= issuedInstruction2.ageTag;
                reorderBuffer[redirectAdjustedTail+ 'd1].isStore <= issuedInstruction2.isStore;
                reorderBuffer[redirectAdjustedTail+ 'd1].completed <= 1'b0;
            end
        end
    end

    // Instruction Resolution
    logic [width:0] entries;
    assign entries = tailPointer - headPointer;
    always_comb begin
        resolvedInstruction1 = '0;
        resolvedInstruction2 = '0;
        retireCount = 2'b00;
        triggerStore = 1'd0;
        if ((entries > 'd1) && (reorderBuffer[headIndexer].completed || reorderBuffer[headIndexer].destinationRegister == 5'd0)
        && (reorderBuffer[headIndexer+1].completed || reorderBuffer[headIndexer+1].destinationRegister == 5'd0)) begin
            // Commit Slot 0 and 1
            retireCount = 2'b10;
            if ((reorderBuffer[headIndexer].destinationRegister != 5'd0) && (reorderBuffer[headIndexer].destinationRegister == reorderBuffer[headIndexer+1].destinationRegister)) begin
                // Packet 1 Gets Packet 2 Data and Drops Packet 2 On Conflict
                resolvedInstruction1.ageTag = reorderBuffer[headIndexer+1].ageTag;
                resolvedInstruction1.instructionResult = reorderBuffer[headIndexer+1].instructionResult;
                resolvedInstruction1.destinationRegister = reorderBuffer[headIndexer+1].destinationRegister;
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
                if (reorderBuffer[headIndexer+1].destinationRegister != 5'd0) begin
                    resolvedInstruction2.ageTag = reorderBuffer[headIndexer+1].ageTag;
                    resolvedInstruction2.instructionResult = reorderBuffer[headIndexer+1].instructionResult;
                    resolvedInstruction2.destinationRegister = reorderBuffer[headIndexer+1].destinationRegister;
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
            // Memory Queue is Flused on Redirect
            if (completedMemory.accept) begin
                reorderBuffer[completedMemory.ageTag].instructionResult <= completedMemory.instructionResult;
                reorderBuffer[completedMemory.ageTag].completed <= 1'b1;
            end
        end
    end

endmodule

// STILL NEED: 
// full empty use case missing (prob need for entry calc)
// Restore RST State on Redirect (Set to RF OR ROB Valid. MUST CHECK!!)