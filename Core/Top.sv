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

    // Operand Select Outputs
    logic [4:0] upperSourceRegister1;
    logic [4:0] upperSourceRegister2;
    logic [4:0] lowerSourceRegister1;
    logic [4:0] lowerSourceRegister2;
    logic [4:0] upperAddress1;
    logic [4:0] upperAddress2;
    logic [4:0] lowerAddress1;
    logic [4:0] lowerAddress2;
    logic [4:0] upperTagIndex1;
    logic [4:0] upperTagIndex2;
    logic [4:0] lowerTagIndex1;
    logic [4:0] lowerTagIndex2;

    // Register File Outputs
    logic [31:0] upperSourceData1;
    logic [31:0] upperSourceData2;
    logic [31:0] lowerSourceData1;
    logic [31:0] lowerSourceData2;

    // Reorder Buffer Outputs
    logic [31:0] upperROBData1;
    logic [31:0] upperROBData2;
    logic [31:0] lowerROBData1;
    logic [31:0] lowerROBData2;

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
        .issuedInstruction1(instructionPacket1), // input
        .issuedInstruction2(instructionPacket2), // input

        .resolvedInstruction1(resolvedInstruction1), // output
        .resolvedInstruction2(resolvedInstruction2), // output
        .triggerStore(triggerStore), // output

        .nextFreeSlots(nextFreeSlots), // output

        .storeACK(), // input

        .upperTagIndex1(upperTagIndex1), // input
        .upperTagIndex2(upperTagIndex2), // input
        .lowerTagIndex1(lowerTagIndex1), // input
        .lowerTagIndex2(lowerTagIndex2), // input

        .upperForward1(upperROBData1), // output
        .upperForward2(upperROBData2), // output
        .lowerForward1(lowerROBData1), // output
        .lowerForward2(lowerROBData2) // output
    );

    RegisterStatusTable registerStatusTable (

        .clock(clock), // input
        .reset(reset), // input

        .upperSourceRegister1(upperSourceRegister1), // input
        .upperSourceRegister2(upperSourceRegister2), // input
        .lowerSourceRegister1(lowerSourceRegister1), // input
        .lowerSourceRegister2(lowerSourceRegister2), // input

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

    RegisterFile registerFile (

        .clock(clock), // input
        .reset(reset), // input

        .upperSourceRegister1(upperAddress1), // input
        .upperSourceRegister2(upperAddress2), // input
        .lowerSourceRegister1(lowerAddress1), // input
        .lowerSourceRegister2(lowerAddress2), // input

        .upperSourceData1(upperSourceData1), // output
        .upperSourceData2(upperSourceData2), // output
        .lowerSourceData1(lowerSourceData1), // output
        .lowerSourceData2(lowerSourceData2), // output

        .resolvedInstruction1(resolvedInstruction1), // input
        .resolvedInstruction2(resolvedInstruction2) // input
    );

    OperandSelect operandSelect (

        .clock(clock), // input
        .reset(reset), // input

        .upperSourceRegister1(upperSourceRegister1), // output
        .upperSourceRegister2(upperSourceRegister2), // output
        .lowerSourceRegister1(lowerSourceRegister1), // output
        .lowerSourceRegister2(lowerSourceRegister2), // output

        .upperSource1Status(upperSource1Status), // input
        .upperSource2Status(upperSource2Status), // input
        .lowerSource1Status(lowerSource1Status), // input
        .lowerSource2Status(lowerSource2Status), // input

        .upperAddress1(upperAddress1), // output
        .upperAddress2(upperAddress2), // output
        .lowerAddress1(lowerAddress1), // output
        .lowerAddress2(lowerAddress2), // output

        .upperData1(upperSourceData1), // input
        .upperData2(upperSourceData2), // input
        .lowerData1(lowerSourceData1), // input
        .lowerData2(lowerSourceData2), // input

        .upperTagIndex1(upperTagIndex1), // output
        .upperTagIndex2(upperTagIndex2), // output
        .lowerTagIndex1(lowerTagIndex1), // output
        .lowerTagIndex2(lowerTagIndex2), // output

        .upperROBData1(upperROBData1), // input
        .upperROBData2(upperROBData2), // input
        .lowerROBData1(lowerROBData1), // input
        .lowerROBData2(lowerROBData2), // input

        .upperExData(), // input
        .lowerExData(), // input
        .upperExTag(), // input
        .lowerExTag(), // input

        .payload1(payload1), // input
        .payload2(payload2), // input

        .exPayload1(), // output
        .exPayload2() // output
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
