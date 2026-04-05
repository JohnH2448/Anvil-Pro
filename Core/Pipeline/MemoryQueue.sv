import Configuration::*;
import Payloads::*;
import Enumerations::*;

module MemoryQueue (

    // Standard
    input logic clock,
    input logic reset,

    // ROB Store Coms
    output logic storeACK,
    input logic triggerStore,

    // Instruction Input
    input ExecuteMemoryPayload_ memPayload,

    // Memory Bus
    output WishboneMaster_ memBusOut,
    input WishboneSlave_ memBusIn,

    // Data to ROB
    output InputInstruction_ completedMemory,

    // Free Slots to Issuer
    output logic memFreeSlot,

    // Pipeline Metadata for Capacity
    input logic osMemory,
    input logic exMemory

);

    // Queue Instantiation
    MemoryQueueEntry_ queueEntry[0:7];

    // Tail Pointer
    logic [3:0] tailPointer;
    integer debugCycle;

    // Entry Processed Completion Bit
    logic completed;
    assign completed = memBusIn.acknowledge;

    // Free Slot Calculation
    always_comb begin
        logic [3:0] memFreeSlotsTemp;
        memFreeSlot = 1'b0;
        memFreeSlotsTemp = 4'd8 - tailPointer + 
        {3'b000, completed} - {3'b000, osMemory} - {3'b000, exMemory};
        if (memFreeSlotsTemp > 4'd0) begin
            memFreeSlot = 1'b1;
        end

    end

    // Converts Width to Wishbone Format
    logic [3:0] byteSelectTransform;
    logic [31:0] alignedStoreData;
    always_comb begin
        unique case (queueEntry[0].memoryWidth)
            2'b00: byteSelectTransform = 4'b0001 << queueEntry[0].address[1:0];
            2'b01: byteSelectTransform = 4'b0011 << queueEntry[0].address[1:0];
            2'b11: byteSelectTransform = 4'b1111;
        endcase
        alignedStoreData = queueEntry[0].storeData << (8 * queueEntry[0].address[1:0]);
    end

    // Small Store FSM
    logic storeTriggered;
    always_ff @(posedge clock) begin
        if (reset) begin
            storeTriggered <= 1'b0;
        end else begin
            if (triggerStore && !storeTriggered) begin
                storeTriggered <= 1'b1;
            end
            if (memBusIn.acknowledge && storeTriggered) begin
                storeTriggered <= 1'b0;
            end
        end
    end

    // Drives Wishbone Bus
    always_comb begin
        memBusOut = '0;
        if (queueEntry[0].memoryOperation == MEM_LOAD) begin
            memBusOut.address = queueEntry[0].address;
            memBusOut.writeEnable = 1'b0;
            memBusOut.byteSelect = byteSelectTransform;
            memBusOut.cycle = 1'b1;
            memBusOut.strobe = 1'b1;
        end
        if (queueEntry[0].memoryOperation == MEM_STORE) begin
            memBusOut.address = queueEntry[0].address;
            memBusOut.writeEnable = 1'b1;
            memBusOut.byteSelect = byteSelectTransform;
            memBusOut.storeData = alignedStoreData;
            if (!storeTriggered) begin
                memBusOut.cycle = triggerStore;
                memBusOut.strobe = triggerStore;
            end else begin
                memBusOut.cycle = storeTriggered;
                memBusOut.strobe = storeTriggered;
            end
        end
    end

    // Packet Construction for ROB
    always_comb begin
        logic [31:0] shiftedLoadData;
        logic [7:0] loadByte;
        logic [15:0] loadHalf;
        // Load Packet + Sign Extention
        completedMemory = '0;
        storeACK = 1'b0;
        shiftedLoadData = memBusIn.loadData >> (8 * queueEntry[0].address[1:0]);
        loadByte = shiftedLoadData[7:0];
        loadHalf = memBusIn.loadData >> (16 * queueEntry[0].address[1]);
        if ((queueEntry[0].memoryOperation == MEM_LOAD) && memBusIn.acknowledge) begin
            unique case (queueEntry[0].memoryWidth)
                2'b00: begin
                    if (queueEntry[0].memorySigned) begin
                        completedMemory.instructionResult = {{24{loadByte[7]}}, loadByte};
                    end else begin
                        completedMemory.instructionResult = {24'b0, loadByte};
                    end
                end
                2'b01: begin
                    if (queueEntry[0].memorySigned) begin
                        completedMemory.instructionResult = {{16{loadHalf[15]}}, loadHalf};
                    end else begin
                        completedMemory.instructionResult = {16'b0, loadHalf};
                    end
                end
                2'b11: completedMemory.instructionResult = memBusIn.loadData;
            endcase
            completedMemory.ageTag = queueEntry[0].ageTag;
            completedMemory.destinationRegister = queueEntry[0].destinationRegister;
            completedMemory.accept = 1'b1;
        end
        // Store Packet
        if ((queueEntry[0].memoryOperation == MEM_STORE) && memBusIn.acknowledge) begin
            storeACK = 1'b1;
        end
    end

    // Reset + Accept New Instruction + Shift Queue
    always_ff @(posedge clock) begin
        logic canAccept;
        canAccept = ((tailPointer != 4'd8) || completed);
        if (reset) begin
            debugCycle <= 0;
            for (int i=0; i<8; i++) begin
                queueEntry[i] <= '0;
            end
            tailPointer <= '0;
        end else begin
            // Accept New Instruction
            logic [2:0] index;
            index = tailPointer[2:0] - {2'b00, completed};
            // Shift Queue if Completed
            if (completed) begin
                for (int i=0; i<7; i++) begin
                    queueEntry[i] <= queueEntry[i+1];
                end
            end
            if (canAccept && (memPayload.memoryOperation != MEM_NONE)) begin
                queueEntry[index] <= memPayload;
            end else if (completed) begin
                // Can be removed
                queueEntry[7] <= '0;
            end
            // Tail Pointer Update
            tailPointer <= tailPointer - {3'b00, completed}
            + {3'b000, (canAccept && (memPayload.memoryOperation != MEM_NONE))};

            debugCycle <= debugCycle + 1;
        end
    end

    // Memory Queue Debug Print
    always_ff @(negedge clock) begin
        if (!reset) begin
            $display(
                "Memory Queue\ntail=%0d completed=%0b trig=%0b hold=%0b ack=%0b",
                tailPointer,
                completed,
                triggerStore,
                storeTriggered,
                memBusIn.acknowledge,
            );
            if (tailPointer == '0) begin
                $display("empty");
            end else begin
                for (int unsigned i = 0; i < 8; i++) begin
                    if (i < tailPointer) begin
                        $display("[%0d] op=%0d addr=%08h data=%08h width=%02b sign=%0b tag=%0d rd=x%0d",
                            i,
                            queueEntry[i].memoryOperation,
                            queueEntry[i].address,
                            queueEntry[i].storeData,
                            queueEntry[i].memoryWidth,
                            queueEntry[i].memorySigned,
                            queueEntry[i].ageTag,
                            queueEntry[i].destinationRegister);
                    end
                end
            end
        end
    end

endmodule
// mini single req store buffer with forwarding so you dont need to wait for ack
// back. fairly simple, just hold recent outgoing store and forward
// to in flight loads. This is past ROB and lets stores commit fast.
// basically stall mem queue but forward to loads if needed. must keep
// bus live to maintain transaction for ack.
// actually with inter queue forwarding this may not be necissary.
// unless theres a case im missing, rob doesnt need ack 

// to start, rob will wait for ack. optimize later with above
// StoreACK to ROB must be broadcast in this domain by Queue until next edge

// definitely do a store buffer that bypasses issue restrictions. It can forward to OS
// Maybe 16ish entries from most recent stores. configurable size?
// Actualy this is problematic because address must be known at issue time.

 // Potential Store Buffer that forwards to in-flight loads in ex. they
 // then go straight to rob and skip mem queue.

 // redo retirement logic so that its more streamlined and can fire two stores
 // and doesnt wait for ack.
