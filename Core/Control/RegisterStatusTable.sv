import Configuration::*;
import Payloads::*;
import Enumerations::*;


module RegisterStatusTable (

    // Standard
    input logic clock,
    input logic reset,

    // Read From Operand Select
    input logic [4:0] upperSourceRegister1,
    input logic [4:0] upperSourceRegister2,
    input logic [4:0] lowerSourceRegister1,
    input logic [4:0] lowerSourceRegister2,

    // To Operand Select
    output RegisterStatusOutput_ upperSource1Status,
    output RegisterStatusOutput_ upperSource2Status,
    output RegisterStatusOutput_ lowerSource1Status,
    output RegisterStatusOutput_ lowerSource2Status,
    output RegisterStatusOutput_ oldUpperStatus,
    output RegisterStatusOutput_ oldLowerStatus,

    // Read From Issuer
    input logic [4:0] oldUpperStatusRd,
    input logic [4:0] oldLowerStatusRd,

    // To Issuer
    output logic upperInFlightLoad1,
    output logic upperInFlightLoad2,
    output logic lowerInFlightLoad1,
    output logic lowerInFlightLoad2,
    output logic destRegLoad1,
    output logic destRegLoad2,

    // Write Signals From Issue
    input logic instructionConsumed1,
    input logic instructionConsumed2,
    input logic [4:0] rstDestinationRegister1,
    input logic [4:0] rstDestinationRegister2,
    input logic isLoad1,
    input logic isLoad2,
    input logic [reorderBufferIndexWidth-1:0] ageTag1,
    input logic [reorderBufferIndexWidth-1:0] ageTag2,

    // Retire Signals From ROB
    input logic retire1,
    input logic retire2,
    input logic [4:0] retireRegister1,
    input logic [4:0] retireRegister2,
    input logic [reorderBufferIndexWidth-1:0] retireAgeTag1,
    input logic [reorderBufferIndexWidth-1:0] retireAgeTag2,

    // Ready Signals From ROB
    input logic ready1,
    input logic ready2,
    input logic [4:0] readyRegister1,
    input logic [4:0] readyRegister2,
    input logic [reorderBufferIndexWidth-1:0] readyAgeTag1,
    input logic [reorderBufferIndexWidth-1:0] readyAgeTag2,

    // Ready Signal From Memory
    input logic memReady,
    input logic [4:0] memReg,
    input logic [reorderBufferIndexWidth-1:0] memAgeTag,

    // Restore State Buses from ROB
    input RestoreStateBus_ rstBus1,
    input RestoreStateBus_ rstBus2,
    input RestoreStateBus_ rstBus3

);

    // Register Status Table Declaration
    RegisterStatusEntry_ registerStatusTable [0:31];
    integer debugCycle;

    // Write Block
    always_ff @(posedge clock) begin
        if (reset) begin
            // Reset State
            debugCycle <= 0;
            for (int i=0; i < 32; i++) begin
                registerStatusTable[i].isLoad <= 1'd0;
                registerStatusTable[i].resultReady <= 1'd1;
                registerStatusTable[i].resultCommitted <= 1'd1;
            end
        end else begin
            debugCycle <= debugCycle + 1;
            // Full State Bookkeeping Logic
            if (instructionConsumed1 &&
                (!instructionConsumed2 || (rstDestinationRegister1 != rstDestinationRegister2))) begin
                // New Issue 1 Write
                registerStatusTable[rstDestinationRegister1].ageTag <= ageTag1;
                registerStatusTable[rstDestinationRegister1].isLoad <= isLoad1;
                registerStatusTable[rstDestinationRegister1].resultReady <= 1'd0;
                registerStatusTable[rstDestinationRegister1].resultCommitted <= 1'd0;
            end
            if (ready1 &&
                (!instructionConsumed2 || (readyRegister1 != rstDestinationRegister2)) &&
                (!instructionConsumed1 || (readyRegister1 != rstDestinationRegister1)) &&
                (!ready2 || (readyRegister1 != readyRegister2))) begin
                // Instruction Ready 1
                if (registerStatusTable[readyRegister1].ageTag == readyAgeTag1) begin
                    registerStatusTable[readyRegister1].resultReady <= 1'd1;
                    registerStatusTable[readyRegister1].resultCommitted <= 1'd0;
                end
            end

            if (retire1 &&
                (!instructionConsumed2 || (retireRegister1 != rstDestinationRegister2)) &&
                (!instructionConsumed1 || (retireRegister1 != rstDestinationRegister1)) &&
                (!ready2 || (retireRegister1 != readyRegister2)) &&
                (!ready1 || (retireRegister1 != readyRegister1)) &&
                (!memReady || (retireRegister1 != memReg)) &&
                (!retire2 || (retireRegister1 != retireRegister2))) begin
                // Instruction Retired From ROB 1
                if (registerStatusTable[retireRegister1].ageTag == retireAgeTag1) begin
                    registerStatusTable[retireRegister1].resultReady <= 1'd1;
                    registerStatusTable[retireRegister1].resultCommitted <= 1'd1;
                end
            end

            if (instructionConsumed2) begin
                // New Issue 2 Write
                registerStatusTable[rstDestinationRegister2].ageTag <= ageTag2;
                registerStatusTable[rstDestinationRegister2].isLoad <= isLoad2;
                registerStatusTable[rstDestinationRegister2].resultReady <= 1'd0;
                registerStatusTable[rstDestinationRegister2].resultCommitted <= 1'd0;
            end
            if (ready2 &&
                (!instructionConsumed2 || (readyRegister2 != rstDestinationRegister2)) &&
                (!instructionConsumed1 || (readyRegister2 != rstDestinationRegister1))) begin
                // Instruction Ready 2
                if (registerStatusTable[readyRegister2].ageTag == readyAgeTag2) begin
                    registerStatusTable[readyRegister2].resultReady <= 1'd1;
                    registerStatusTable[readyRegister2].resultCommitted <= 1'd0;
                end
            end
            // Mem Ready
            if (memReady) begin
                // Load Data Arrived
                if (registerStatusTable[memReg].ageTag == memAgeTag) begin
                    registerStatusTable[memReg].resultReady <= 1'd1;
                    registerStatusTable[memReg].resultCommitted <= 1'd0;
                end
            end

            if (retire2 &&
                (!instructionConsumed2 || (retireRegister2 != rstDestinationRegister2)) &&
                (!instructionConsumed1 || (retireRegister2 != rstDestinationRegister1)) &&
                (!ready2 || (retireRegister2 != readyRegister2)) &&
                (!ready1 || (retireRegister2 != readyRegister1)) &&
                (!memReady || (retireRegister2 != memReg))) begin
                // Instruction Retired From ROB 2
                if (registerStatusTable[retireRegister2].ageTag == retireAgeTag2) begin
                    registerStatusTable[retireRegister2].resultReady <= 1'd1;
                    registerStatusTable[retireRegister2].resultCommitted <= 1'd1;
                end
            end
            // RST Redirect State Restore
            // Should Never Conflict With Consumed/Ready or Eachother
            if (rstBus1.valid) begin
                registerStatusTable[rstBus1.destinationRegister].ageTag <= rstBus1.ageTag;
                registerStatusTable[rstBus1.destinationRegister].resultReady <= rstBus1.ready;
                registerStatusTable[rstBus1.destinationRegister].resultCommitted <= rstBus1.retired;
                registerStatusTable[rstBus1.destinationRegister].isLoad <= 1'd0;
            end
            if (rstBus2.valid) begin
                registerStatusTable[rstBus2.destinationRegister].ageTag <= rstBus2.ageTag;
                registerStatusTable[rstBus2.destinationRegister].resultReady <= rstBus2.ready;
                registerStatusTable[rstBus2.destinationRegister].resultCommitted <= rstBus2.retired;
                registerStatusTable[rstBus2.destinationRegister].isLoad <= 1'd0;
            end
            if (rstBus3.valid) begin
                registerStatusTable[rstBus3.destinationRegister].ageTag <= rstBus3.ageTag;
                registerStatusTable[rstBus3.destinationRegister].resultReady <= rstBus3.ready;
                registerStatusTable[rstBus3.destinationRegister].resultCommitted <= rstBus3.retired;
                registerStatusTable[rstBus3.destinationRegister].isLoad <= 1'd0;
            end
        end
    end

    // Large Index Block
    always_comb begin
        // Destination Register isLoad Check 1
        if (rstDestinationRegister1 != 5'd0) begin
            destRegLoad1 = registerStatusTable[rstDestinationRegister1].isLoad && !registerStatusTable[rstDestinationRegister1].resultReady;
        end else begin
            destRegLoad1 = 1'b0;
        end
        // Destination Register isLoad Check 2
        if (rstDestinationRegister2 != 5'd0) begin
            destRegLoad2 = registerStatusTable[rstDestinationRegister2].isLoad && !registerStatusTable[rstDestinationRegister2].resultReady;
        end else begin
            destRegLoad2 = 1'b0;
        end
        // Upper Source Register 1
        if (upperSourceRegister1 != 5'd0) begin
            upperSource1Status.ageTag = registerStatusTable[upperSourceRegister1].ageTag;
            upperSource1Status.resultReady = registerStatusTable[upperSourceRegister1].resultReady;
            upperSource1Status.resultCommitted = registerStatusTable[upperSourceRegister1].resultCommitted;
            upperSource1Status.isLoad = registerStatusTable[upperSourceRegister1].isLoad;
        end else begin
            upperSource1Status.resultReady = 1'b1;
            upperSource1Status.resultCommitted = 1'b1;
            upperSource1Status.isLoad = 1'b0;
        end
        // Upper Source Register 2
        if (upperSourceRegister2 != 5'd0) begin
            upperSource2Status.ageTag = registerStatusTable[upperSourceRegister2].ageTag;
            upperSource2Status.resultReady = registerStatusTable[upperSourceRegister2].resultReady;
            upperSource2Status.resultCommitted = registerStatusTable[upperSourceRegister2].resultCommitted;
            upperSource2Status.isLoad = registerStatusTable[upperSourceRegister2].isLoad;
        end else begin
            upperSource2Status.resultReady = 1'b1;
            upperSource2Status.resultCommitted = 1'b1;
            upperSource2Status.isLoad = 1'b0;
        end
        // Lower Source Register 1
        if (lowerSourceRegister1 != 5'd0) begin
            lowerSource1Status.ageTag = registerStatusTable[lowerSourceRegister1].ageTag;
            lowerSource1Status.resultReady = registerStatusTable[lowerSourceRegister1].resultReady;
            lowerSource1Status.resultCommitted = registerStatusTable[lowerSourceRegister1].resultCommitted;
            lowerSource1Status.isLoad = registerStatusTable[lowerSourceRegister1].isLoad;
        end else begin
            lowerSource1Status.resultReady = 1'b1;
            lowerSource1Status.resultCommitted = 1'b1;
            lowerSource1Status.isLoad = 1'b0;
        end
        // Lower Source Register 2
        if (lowerSourceRegister2 != 5'd0) begin
            lowerSource2Status.ageTag = registerStatusTable[lowerSourceRegister2].ageTag;
            lowerSource2Status.resultReady = registerStatusTable[lowerSourceRegister2].resultReady;
            lowerSource2Status.resultCommitted = registerStatusTable[lowerSourceRegister2].resultCommitted;
            lowerSource2Status.isLoad = registerStatusTable[lowerSourceRegister2].isLoad;
        end else begin
            lowerSource2Status.resultReady = 1'b1;
            lowerSource2Status.resultCommitted = 1'b1;
            lowerSource2Status.isLoad = 1'b0;
        end
        // Old Upper Status
        if (oldUpperStatusRd != 5'd0) begin
            oldUpperStatus.ageTag = registerStatusTable[oldUpperStatusRd].ageTag;
            oldUpperStatus.resultReady = registerStatusTable[oldUpperStatusRd].resultReady;
            oldUpperStatus.resultCommitted = registerStatusTable[oldUpperStatusRd].resultCommitted;
            oldUpperStatus.isLoad = registerStatusTable[oldUpperStatusRd].isLoad;
        end else begin
            oldUpperStatus.resultReady = 1'b1;
            oldUpperStatus.resultCommitted = 1'b1;
            oldUpperStatus.isLoad = 1'b0;
        end
        // Old Lower Status
        if (oldLowerStatusRd != 5'd0) begin
            oldLowerStatus.ageTag = registerStatusTable[oldLowerStatusRd].ageTag;
            oldLowerStatus.resultReady = registerStatusTable[oldLowerStatusRd].resultReady;
            oldLowerStatus.resultCommitted = registerStatusTable[oldLowerStatusRd].resultCommitted;
            oldLowerStatus.isLoad = registerStatusTable[oldLowerStatusRd].isLoad;
        end else begin
            oldLowerStatus.resultReady = 1'b1;
            oldLowerStatus.resultCommitted = 1'b1;
            oldLowerStatus.isLoad = 1'b0;
        end
    end

endmodule
// May be wise to split into two tables. Issuer only needs 1 bit
// Restore logic may need to account for memory ops ready from queue


