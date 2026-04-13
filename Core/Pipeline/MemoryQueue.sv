import Configuration::*;
import Payloads::*;
import Enumerations::*;

module MemoryQueue (

    // Standard
    input logic clock,
    input logic reset,

    // Instruction Input
    input ExecuteMemoryPayload_ memPayload,

    // Memory Bus
    output WishboneMaster_ memBusOut,
    input WishboneSlave_ memBusIn,

    // Data to ROB
    output InputInstruction_ completedMemory,
    output logic [reorderBufferIndexWidth-1:0] loadTag,

    // Free Slots to Issuer
    output logic memFreeSlot,

    // Pipeline Metadata for Capacity
    input logic osMemory,
    input logic exMemory,

    // Buses to Store Buffer
    output StoreBus_ storeBus1,
    output StoreBus_ storeBus2,
    output StoreBus_ storeBus3,
    output StoreBus_ storeBus4,
    output StoreBus_ storeBus5,
    output StoreBus_ storeBus6,
    output StoreBus_ storeBus7,
    output StoreBus_ storeBus8

);

    // Queue Instantiation
    MemoryQueueEntry_ queueEntry[0:7];

    // Tail Pointer
    logic [3:0] tailPointer;
    integer debugCycle;

    // Store Bus Drivers
    assign storeBus1.address = queueEntry[0].address;
    assign storeBus1.storeData = queueEntry[0].storeData;
    assign storeBus1.memoryBytes = queueEntry[0].memoryBytes;
    assign storeBus1.valid = (queueEntry[0].memoryOperation == MEM_STORE)
    && (tailPointer > 'd0);

    assign storeBus2.address = queueEntry[1].address;
    assign storeBus2.storeData = queueEntry[1].storeData;
    assign storeBus2.memoryBytes = queueEntry[1].memoryBytes;
    assign storeBus2.valid = (queueEntry[1].memoryOperation == MEM_STORE)
    && (tailPointer > 'd1);

    assign storeBus3.address = queueEntry[2].address;
    assign storeBus3.storeData = queueEntry[2].storeData;
    assign storeBus3.memoryBytes = queueEntry[2].memoryBytes;
    assign storeBus3.valid = (queueEntry[2].memoryOperation == MEM_STORE)
    && (tailPointer > 'd2);

    assign storeBus4.address = queueEntry[3].address;
    assign storeBus4.storeData = queueEntry[3].storeData;
    assign storeBus4.memoryBytes = queueEntry[3].memoryBytes;
    assign storeBus4.valid = (queueEntry[3].memoryOperation == MEM_STORE)
    && (tailPointer > 'd3);

    assign storeBus5.address = queueEntry[4].address;
    assign storeBus5.storeData = queueEntry[4].storeData;
    assign storeBus5.memoryBytes = queueEntry[4].memoryBytes;
    assign storeBus5.valid = (queueEntry[4].memoryOperation == MEM_STORE)
    && (tailPointer > 'd4);

    assign storeBus6.address = queueEntry[5].address;
    assign storeBus6.storeData = queueEntry[5].storeData;
    assign storeBus6.memoryBytes = queueEntry[5].memoryBytes;
    assign storeBus6.valid = (queueEntry[5].memoryOperation == MEM_STORE)
    && (tailPointer > 'd5);

    assign storeBus7.address = queueEntry[6].address;
    assign storeBus7.storeData = queueEntry[6].storeData;
    assign storeBus7.memoryBytes = queueEntry[6].memoryBytes;
    assign storeBus7.valid = (queueEntry[6].memoryOperation == MEM_STORE)
    && (tailPointer > 'd6);

    assign storeBus8.address = queueEntry[7].address;
    assign storeBus8.storeData = queueEntry[7].storeData;
    assign storeBus8.memoryBytes = queueEntry[7].memoryBytes;
    assign storeBus8.valid = (queueEntry[7].memoryOperation == MEM_STORE)
    && (tailPointer > 'd7);

    // Entry Processed Completion Bit
    logic completed;
    assign completed = memBusIn.acknowledge;
    assign loadTag = queueEntry[0].ageTag;

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
        unique case (memPayload.memoryWidth)
            2'b00: byteSelectTransform = 4'b0001 << memPayload.address[1:0];
            2'b01: byteSelectTransform = 4'b0011 << memPayload.address[1:0];
            2'b11: byteSelectTransform = 4'b1111;
        endcase
        // Latched on Enqueue
        alignedStoreData = memPayload.storeData << (8 * memPayload.address[1:0]);
    end

    // Drives Wishbone Bus
    always_comb begin
        memBusOut = '0;
        if (queueEntry[0].memoryOperation == MEM_LOAD) begin
            memBusOut.address = queueEntry[0].address;
            memBusOut.writeEnable = 1'b0;
            memBusOut.byteSelect = queueEntry[0].memoryBytes;
            memBusOut.cycle = 1'b1;
            memBusOut.strobe = 1'b1;
        end
        if (queueEntry[0].memoryOperation == MEM_STORE) begin
            memBusOut.address = queueEntry[0].address;
            memBusOut.writeEnable = 1'b1;
            memBusOut.byteSelect = queueEntry[0].memoryBytes;
            memBusOut.storeData = queueEntry[0].storeData;
            memBusOut.cycle = 1'b1;
            memBusOut.strobe = 1'b1;
        end
    end

    // Packet Construction for ROB
    always_comb begin
        logic [31:0] shiftedLoadData;
        logic [7:0] loadByte;
        logic [15:0] loadHalf;
        // Load Packet + Sign Extention
        completedMemory = '0;
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
                queueEntry[index].address <= memPayload.address;
                queueEntry[index].address <= memPayload.address;
                queueEntry[index].memoryOperation <= memPayload.memoryOperation;
                queueEntry[index].memorySigned <= memPayload.memorySigned;
                queueEntry[index].destinationRegister <= memPayload.destinationRegister;
                queueEntry[index].ageTag <= memPayload.ageTag;
                queueEntry[index].memoryWidth <= memPayload.memoryWidth;
                // Precomputed Store Formatting for StoreBuffer
                queueEntry[index].storeData <= alignedStoreData; 
                queueEntry[index].memoryBytes <= byteSelectTransform;
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
        if (!reset && debugMode) begin
            $display(
                "Memory Queue\ntail=%0d completed=%0b ack=%0b",
                tailPointer,
                completed,
                memBusIn.acknowledge
            );
            if (tailPointer == '0) begin
                $display("empty");
            end else begin
                for (int unsigned i = 0; i < 8; i++) begin
                    if (i < tailPointer) begin
                        $display("[%0d] op=%0d addr=%08h data=%08h sign=%0b tag=%0d rd=x%0d",
                            i,
                            queueEntry[i].memoryOperation,
                            queueEntry[i].address,
                            queueEntry[i].storeData,
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

// Potential Store Buffer that forwards to in-flight loads in ex. they
// then go straight to rob and skip mem queue.
