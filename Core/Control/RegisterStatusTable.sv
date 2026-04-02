import Configuration::*;
import Payloads::*;
import Enumerations::*;

localparam int width = $clog2(reorderBufferEntries);

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

    // Read From Issuer
    input logic [4:0] upperIssuerRegister1,
    input logic [4:0] upperIssuerRegister2,
    input logic [4:0] lowerIssuerRegister1,
    input logic [4:0] lowerIssuerRegister2,

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
    input logic [width-1:0] ageTag1,
    input logic [width-1:0] ageTag2,

    // Retire Signals From ROB
    input logic retire1,
    input logic retire2,
    input logic [4:0] retireRegister1,
    input logic [4:0] retireRegister2,
    input logic [width-1:0] retireAgeTag1,
    input logic [width-1:0] retireAgeTag2,

    // Ready Signals From ROB
    input logic ready1,
    input logic ready2,
    input logic [4:0] readyRegister1,
    input logic [4:0] readyRegister2,
    input logic [width-1:0] readyAgeTag1,
    input logic [width-1:0] readyAgeTag2,

    // Restore State Buses from ROB
    input RestoreStateBus_ rstBus1,
    input RestoreStateBus_ rstBus2,
    input RestoreStateBus_ rstBus3

);

    // Register Status Table Declaration
    RegisterStatusEntry_ registerStatusTable [0:31];

    // Write Block
    always_ff @(posedge clock) begin
        if (reset) begin
            // Reset State
            for (int i=0; i < 32; i++) begin
                registerStatusTable[i].isLoad <= 1'd0;
                registerStatusTable[i].resultReady <= 1'd1;
                registerStatusTable[i].resultCommitted <= 1'd1;
            end
        end else begin
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

            if (retire2 &&
                (!instructionConsumed2 || (retireRegister2 != rstDestinationRegister2)) &&
                (!instructionConsumed1 || (retireRegister2 != rstDestinationRegister1)) &&
                (!ready2 || (retireRegister2 != readyRegister2)) &&
                (!ready1 || (retireRegister2 != readyRegister1))) begin
                // Instruction Retired From ROB 2
                if (registerStatusTable[retireRegister2].ageTag == retireAgeTag2) begin
                    registerStatusTable[retireRegister2].resultReady <= 1'd1;
                    registerStatusTable[retireRegister2].resultCommitted <= 1'd1;
                end
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
        end else begin
            upperSource1Status.resultReady = 1'b1;
            upperSource1Status.resultCommitted = 1'b1;
        end
        // Upper Source Register 2
        if (upperSourceRegister2 != 5'd0) begin
            upperSource2Status.ageTag = registerStatusTable[upperSourceRegister2].ageTag;
            upperSource2Status.resultReady = registerStatusTable[upperSourceRegister2].resultReady;
            upperSource2Status.resultCommitted = registerStatusTable[upperSourceRegister2].resultCommitted;
        end else begin
            upperSource2Status.resultReady = 1'b1;
            upperSource2Status.resultCommitted = 1'b1;
        end
        // Lower Source Register 1
        if (lowerSourceRegister1 != 5'd0) begin
            lowerSource1Status.ageTag = registerStatusTable[lowerSourceRegister1].ageTag;
            lowerSource1Status.resultReady = registerStatusTable[lowerSourceRegister1].resultReady;
            lowerSource1Status.resultCommitted = registerStatusTable[lowerSourceRegister1].resultCommitted;
        end else begin
            lowerSource1Status.resultReady = 1'b1;
            lowerSource1Status.resultCommitted = 1'b1;
        end
        // Lower Source Register 2
        if (lowerSourceRegister2 != 5'd0) begin
            lowerSource2Status.ageTag = registerStatusTable[lowerSourceRegister2].ageTag;
            lowerSource2Status.resultReady = registerStatusTable[lowerSourceRegister2].resultReady;
            lowerSource2Status.resultCommitted = registerStatusTable[lowerSourceRegister2].resultCommitted;
        end else begin
            lowerSource2Status.resultReady = 1'b1;
            lowerSource2Status.resultCommitted = 1'b1;
        end
        // Upper Issuer Register 1
        if (upperIssuerRegister1 != 5'd0) begin
            upperInFlightLoad1 = registerStatusTable[upperIssuerRegister1].isLoad && !registerStatusTable[upperIssuerRegister1].resultReady;
        end else begin
            upperInFlightLoad1 = 1'b0;
        end
        // Upper Issuer Register 2
        if (upperIssuerRegister2 != 5'd0) begin
            upperInFlightLoad2 = registerStatusTable[upperIssuerRegister2].isLoad && !registerStatusTable[upperIssuerRegister2].resultReady;
        end else begin
            upperInFlightLoad2 = 1'b0;
        end
        // Lower Issuer Register 1
        if (lowerIssuerRegister1 != 5'd0) begin
            lowerInFlightLoad1 = registerStatusTable[lowerIssuerRegister1].isLoad && !registerStatusTable[lowerIssuerRegister1].resultReady;
        end else begin
            lowerInFlightLoad1 = 1'b0;
        end
        // Lower Issuer Register 2
        if (lowerIssuerRegister2 != 5'd0) begin
            lowerInFlightLoad2 = registerStatusTable[lowerIssuerRegister2].isLoad && !registerStatusTable[lowerIssuerRegister2].resultReady;
        end else begin
            lowerInFlightLoad2 = 1'b0;
        end
    end

endmodule
// May be wise to split into two tables. Issuer only needs 1 bit
// zero isLoad on redirect restore. may actually be a load but its irrelevant once ready
// retire gets priority over state restore