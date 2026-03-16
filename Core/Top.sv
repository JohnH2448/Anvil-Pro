import Configuration::*;
import Payloads::*;
import Enumerations::*;

module Top (

    // Standard
    input logic clock,
    input logic reset
    
);

    // Reorder Buffer Outputs
    RetiredInstruction_ resolvedInstruction1;
    RetiredInstruction_ resolvedInstruction2;
    logic triggerStore;
    logic [4:0] nextFreeSlots;

    // Register Status Table Outputs
    RegisterStatusOutput_ upperSource1Status;
    RegisterStatusOutput_ upperSource2Status;
    RegisterStatusOutput_ lowerSource1Status;
    RegisterStatusOutput_ lowerSource2Status;
    logic upperInFlightLoad1;
    logic upperInFlightLoad2;
    logic lowerInFlightLoad1;
    logic lowerInFlightLoad2;
    logic destRegLoad1;
    logic destRegLoad2;

    // Decode / Issue Outputs
    logic instructionConsumed1;
    logic instructionConsumed2;
    logic [31:0] requestPC1;
    logic [31:0] requestPC2;
    UpperIssuerOperandPayload_ payload1;
    LowerIssuerOperandPayload_ payload2;
    logic [4:0] upperIssuerRegister1;
    logic [4:0] upperIssuerRegister2;
    logic [4:0] lowerIssuerRegister1;
    logic [4:0] lowerIssuerRegister2;
    logic [4:0] rstDestinationRegister1;
    logic [4:0] rstDestinationRegister2;
    logic isLoad1;
    logic isLoad2;
    logic [4:0] ageTag1;
    logic [4:0] ageTag2;
    IssuedIntruction_ instructionPacket1;
    IssuedIntruction_ instructionPacket2;

    // Walking Window Outputs
    logic [31:0] lowFetchAddress;
    logic [31:0] highFetchAddress;
    logic [31:0] instruction1;
    logic [31:0] instruction2;
    logic [31:0] programCounter;
    logic badData;

    // Instruction Memory Outputs
    logic [127:0] lowFetchData;
    logic [127:0] highFetchData;

    ReorderBuffer reorderBuffer (

        .clock(clock), // input
        .reset(reset), // input

        .completedMemory(), // input
        .completedInstruction1(), // input
        .completedInstruction2(), // input
        .issuedInstruction1(), // input
        .issuedInstruction2(), // input

        .resolvedInstruction1(resolvedInstruction1), // output
        .resolvedInstruction2(resolvedInstruction2), // output
        .triggerStore(triggerStore), // output

        .nextFreeSlots(nextFreeSlots) // output
    );

    RegisterStatusTable registerStatusTable (

        .clock(clock), // input
        .reset(reset), // input

        .upperSourceRegister1(), // input
        .upperSourceRegister2(), // input
        .lowerSourceRegister1(), // input
        .lowerSourceRegister2(), // input

        .upperSource1Status(upperSource1Status), // output
        .upperSource2Status(upperSource2Status), // output
        .lowerSource1Status(lowerSource1Status), // output
        .lowerSource2Status(lowerSource2Status), // output

        .upperIssuerRegister1(upperIssuerRegister1), // input
        .upperIssuerRegister2(upperIssuerRegister2), // input
        .lowerIssuerRegister1(lowerIssuerRegister1), // input
        .lowerIssuerRegister2(lowerIssuerRegister2), // input

        .upperInFlightLoad1(upperInFlightLoad1), // output
        .upperInFlightLoad2(upperInFlightLoad2), // output
        .lowerInFlightLoad1(lowerInFlightLoad1), // output
        .lowerInFlightLoad2(lowerInFlightLoad2), // output
        .destRegLoad1(destRegLoad1), // output
        .destRegLoad2(destRegLoad2), // output

        .instructionConsumed1(instructionConsumed1), // input
        .instructionConsumed2(instructionConsumed2), // input
        .rstDestinationRegister1(rstDestinationRegister1), // input
        .rstDestinationRegister2(rstDestinationRegister2), // input
        .isLoad1(isLoad1), // input
        .isLoad2(isLoad2), // input
        .ageTag1(ageTag1), // input
        .ageTag2(ageTag2), // input

        .retire1(resolvedInstruction1.valid), // input
        .retire2(resolvedInstruction2.valid), // input
        .retireRegister1(resolvedInstruction1.destinationRegister), // input
        .retireRegister2(resolvedInstruction2.destinationRegister), // input
        .retireAgeTag1(resolvedInstruction1.ageTag), // input
        .retireAgeTag2(resolvedInstruction2.ageTag), // input

        .ready1(), // input
        .ready2(), // input
        .readyRegister1(), // input
        .readyRegister2(), // input
        .readyAgeTag1(), // input
        .readyAgeTag2() // input
    );

    DecodeIssue decodeIssue (

        .clock(clock), // input
        .reset(reset), // input

        .redirect(), // input
        .redirectVector(), // input

        .instruction1(instruction1), // input
        .instruction2(instruction2), // input

        .instructionConsumed1(instructionConsumed1), // output
        .instructionConsumed2(instructionConsumed2), // output
        .requestPC1(requestPC1), // output
        .requestPC2(requestPC2), // output
        .programCounter(programCounter), // input
        .badData(badData), // input

        .payload1(payload1), // output
        .payload2(payload2), // output

        .nextFreeSlots(nextFreeSlots), // input

        .upperIssuerRegister1(upperIssuerRegister1), // output
        .upperIssuerRegister2(upperIssuerRegister2), // output
        .lowerIssuerRegister1(lowerIssuerRegister1), // output
        .lowerIssuerRegister2(lowerIssuerRegister2), // output

        .upperInFlightLoad1(upperInFlightLoad1), // input
        .upperInFlightLoad2(upperInFlightLoad2), // input
        .lowerInFlightLoad1(lowerInFlightLoad1), // input
        .lowerInFlightLoad2(lowerInFlightLoad2), // input
        .destRegLoad1(destRegLoad1), // input
        .destRegLoad2(destRegLoad2), // input

        .rstDestinationRegister1(rstDestinationRegister1), // output
        .rstDestinationRegister2(rstDestinationRegister2), // output
        .isLoad1(isLoad1), // output
        .isLoad2(isLoad2), // output
        .ageTag1(ageTag1), // output
        .ageTag2(ageTag2), // output

        .instructionPacket1(instructionPacket1), // output
        .instructionPacket2(instructionPacket2) // output
    );

    WalkingWindow walkingWindow (
        .clock(clock), // input
        .reset(reset), // input
        .redirect(), // input
        .redirectVector(), // input
        .lowFetchData(lowFetchData), // input
        .highFetchData(highFetchData), // input
        .lowFetchAddress(lowFetchAddress), // output
        .highFetchAddress(highFetchAddress), // output
        .instruction1(instruction1), // output
        .instruction2(instruction2), // output
        .instructionConsumed1(instructionConsumed1), // input
        .instructionConsumed2(instructionConsumed2), // input
        .programCounter(programCounter), // output
        .requestPC1(requestPC1), // input
        .requestPC2(requestPC2), // input
        .badData(badData) // output
    );

    InstructionMemory instructionMemory (
        .clock(clock), // input
        .reset(reset), // input
        .redirect(), // input
        .redirectVector(), // input
        .readAddressA(lowFetchAddress), // input
        .readDataA(lowFetchData), // output
        .readAddressB(highFetchAddress), // input
        .readDataB(highFetchData) // output
    );

endmodule

    // ROB Output to Regiser File
    typedef struct packed {
        logic [31:0] instructionResult;
        logic [4:0] destinationRegister;
        logic [4:0] ageTag;
        logic valid;
    } RetiredInstruction_;