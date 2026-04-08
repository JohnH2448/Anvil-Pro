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
    logic [1:0] nextFreeSlots;
    logic [31:0] upperROBData1;
    logic [31:0] upperROBData2;
    logic [31:0] lowerROBData1;
    logic [31:0] lowerROBData2;
    logic [reorderBufferIndexWidth-1:0] freeTag1;
    logic [reorderBufferIndexWidth-1:0] freeTag2;
    RestoreStateBus_ rstBus1;
    RestoreStateBus_ rstBus2;
    RestoreStateBus_ rstBus3;

    // Register Status Table Outputs
    RegisterStatusOutput_ upperSource1Status;
    RegisterStatusOutput_ upperSource2Status;
    RegisterStatusOutput_ lowerSource1Status;
    RegisterStatusOutput_ lowerSource2Status;
    RegisterStatusOutput_ oldLowerStatus;
    RegisterStatusOutput_ oldUpperStatus;
    logic upperInFlightLoad1;
    logic upperInFlightLoad2;
    logic lowerInFlightLoad1;
    logic lowerInFlightLoad2;
    logic destRegLoad1;
    logic destRegLoad2;

    // Decode / Issue Outputs
    logic instructionConsumed1;
    logic instructionConsumed2;
    logic [4:0] oldUpperStatusRd;
    logic [4:0] oldLowerStatusRd;
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
    logic [reorderBufferIndexWidth-1:0] ageTag1;
    logic [reorderBufferIndexWidth-1:0] ageTag2;
    IssuedIntruction_ instructionPacket1;
    IssuedIntruction_ instructionPacket2;

    // Operand Select Outputs
    UpperOperandExecutePayload_ exPayload1;
    LowerOperandExecutePayload_ exPayload2;
    logic [4:0] upperSourceRegister1;
    logic [4:0] upperSourceRegister2;
    logic [4:0] lowerSourceRegister1;
    logic [4:0] lowerSourceRegister2;
    logic [4:0] upperAddress1;
    logic [4:0] upperAddress2;
    logic [4:0] lowerAddress1;
    logic [4:0] lowerAddress2;
    logic [reorderBufferIndexWidth-1:0] upperTagIndex1;
    logic [reorderBufferIndexWidth-1:0] upperTagIndex2;
    logic [reorderBufferIndexWidth-1:0] lowerTagIndex1;
    logic [reorderBufferIndexWidth-1:0] lowerTagIndex2;
    logic osMemory;

    // Register File Outputs
    logic [31:0] upperSourceData1;
    logic [31:0] upperSourceData2;
    logic [31:0] lowerSourceData1;
    logic [31:0] lowerSourceData2;

    // Execute Outputs
    InputInstruction_ resultPayload1;
    InputInstruction_ resultPayload2;
    ExecuteMemoryPayload_ memPayload;
    logic redirect;
    logic [31:0] redirectVector;
    logic redirect1;
    logic redirect2;
    logic exMemory;
    logic [31:0] inputAddress;
    logic [1:0] loadWidth;
    logic loadSigned;

    // Walking Window Outputs
    logic [31:0] lowFetchAddress;
    logic [31:0] highFetchAddress;
    logic [31:0] instruction1;
    logic [31:0] instruction2;
    logic [31:0] programCounter;
    logic badData;

    // Memory Queue Outputs
    InputInstruction_ completedMemory;
    WishboneMaster_ memBusOut;
    logic memFreeSlot;
    StoreBus_ storeBus1;
    StoreBus_ storeBus2;
    StoreBus_ storeBus3;
    StoreBus_ storeBus4;
    StoreBus_ storeBus5;
    StoreBus_ storeBus6;
    StoreBus_ storeBus7;
    StoreBus_ storeBus8;

    // Store Buffer Outputs
    logic [31:0] finalOutputData;
    logic outputValid;

    // Data Memory Outputs
    WishboneSlave_ memBusIn;

    // Instruction Memory Outputs
    logic [127:0] lowFetchData;
    logic [127:0] highFetchData;

    MemoryQueue memoryQueue (
        .clock(clock), // input
        .reset(reset), // input

        .osMemory(osMemory), // input
        .exMemory(exMemory), // input

        .memPayload(memPayload), // input
        .memBusOut(memBusOut), // output
        .memBusIn(memBusIn), // input
        .completedMemory(completedMemory), // output
        .memFreeSlot(memFreeSlot), // output

        .storeBus1(storeBus1), // output
        .storeBus2(storeBus2), // output
        .storeBus3(storeBus3), // output
        .storeBus4(storeBus4), // output
        .storeBus5(storeBus5), // output
        .storeBus6(storeBus6), // output
        .storeBus7(storeBus7), // output
        .storeBus8(storeBus8) // output

    );

    StoreBuffer storeBuffer (
        .clock(clock), // input
        .reset(reset), // input

        .storeBus1(storeBus1), // input
        .storeBus2(storeBus2), // input
        .storeBus3(storeBus3), // input
        .storeBus4(storeBus4), // input
        .storeBus5(storeBus5), // input
        .storeBus6(storeBus6), // input
        .storeBus7(storeBus7), // input
        .storeBus8(storeBus8), // input

        .acknowledge(memBusIn.acknowledge), // input

        .inputAddress(inputAddress), // input
        .loadWidth(loadWidth), // input
        .loadSigned(loadSigned), // input

        .finalOutputData(finalOutputData), // output
        .outputValid(outputValid) // output
    );

    PlaceholderDMEM placeholderDMEM (
        .clock(clock), // input
        .reset(reset), // input
        .memBusOut(memBusOut), // input
        .memBusIn(memBusIn) // output
    );

    ReorderBuffer reorderBuffer (

        .clock(clock), // input
        .reset(reset), // input

        .redirect(redirect), // input
        .redirectVector(redirectVector), // input
        .redirect1(redirect1), // input
        .redirect2(redirect2), // input

        .completedMemory(completedMemory), // input
        .completedInstruction1(resultPayload1), // input
        .completedInstruction2(resultPayload2), // input
        .issuedInstruction1(instructionPacket1), // input
        .issuedInstruction2(instructionPacket2), // input

        .resolvedInstruction1(resolvedInstruction1), // output
        .resolvedInstruction2(resolvedInstruction2), // output

        .nextFreeSlots(nextFreeSlots), // output
        .freeTag1(freeTag1), // output
        .freeTag2(freeTag2), // output

        .enqueuedStoreTag(memPayload.ageTag), // input
        .enqueuedStoreAccept(memPayload.memoryOperation), // input

        .rstBus1(rstBus1), // output
        .rstBus2(rstBus2), // output
        .rstBus3(rstBus3), // output

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

        .rstBus1(rstBus1), // input
        .rstBus2(rstBus2), // input
        .rstBus3(rstBus3), // input

        .upperSource1Status(upperSource1Status), // output
        .upperSource2Status(upperSource2Status), // output
        .lowerSource1Status(lowerSource1Status), // output
        .lowerSource2Status(lowerSource2Status), // output
        .oldUpperStatus(oldUpperStatus), // output
        .oldLowerStatus(oldLowerStatus), // output

        .upperIssuerRegister1(upperIssuerRegister1), // input
        .upperIssuerRegister2(upperIssuerRegister2), // input
        .lowerIssuerRegister1(lowerIssuerRegister1), // input
        .lowerIssuerRegister2(lowerIssuerRegister2), // input

        .oldUpperStatusRd(oldUpperStatusRd), // input
        .oldLowerStatusRd(oldLowerStatusRd), // input

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

        .memReady(completedMemory.accept), // input
        .memReg(completedMemory.destinationRegister), // input
        .memAgeTag(completedMemory.ageTag), // input

        .retire1(resolvedInstruction1.valid), // input
        .retire2(resolvedInstruction2.valid), // input
        .retireRegister1(resolvedInstruction1.destinationRegister), // input
        .retireRegister2(resolvedInstruction2.destinationRegister), // input
        .retireAgeTag1(resolvedInstruction1.ageTag), // input
        .retireAgeTag2(resolvedInstruction2.ageTag), // input

        .ready1(resultPayload1.accept), // input
        .ready2(resultPayload2.accept), // input
        .readyRegister1(resultPayload1.destinationRegister), // input
        .readyRegister2(resultPayload2.destinationRegister), // input
        .readyAgeTag1(resultPayload1.ageTag), // input
        .readyAgeTag2(resultPayload2.ageTag) // input
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

        .redirect(redirect), // input

        .upperSourceRegister1(upperSourceRegister1), // output
        .upperSourceRegister2(upperSourceRegister2), // output
        .lowerSourceRegister1(lowerSourceRegister1), // output
        .lowerSourceRegister2(lowerSourceRegister2), // output

        .upperSource1StatusDummy(upperSource1Status), // input
        .upperSource2StatusDummy(upperSource2Status), // input
        .lowerSource1StatusDummy(lowerSource1Status), // input
        .lowerSource2StatusDummy(lowerSource2Status), // input

        .upperAddress1(upperAddress1), // output
        .upperAddress2(upperAddress2), // output
        .lowerAddress1(lowerAddress1), // output
        .lowerAddress2(lowerAddress2), // output

        .upperData1(upperSourceData1), // input
        .upperData2(upperSourceData2), // input
        .lowerData1(lowerSourceData1), // input
        .lowerData2(lowerSourceData2), // input

        .osMemory(osMemory), // output

        .upperTagIndex1(upperTagIndex1), // output
        .upperTagIndex2(upperTagIndex2), // output
        .lowerTagIndex1(lowerTagIndex1), // output
        .lowerTagIndex2(lowerTagIndex2), // output

        .upperROBData1(upperROBData1), // input
        .upperROBData2(upperROBData2), // input
        .lowerROBData1(lowerROBData1), // input
        .lowerROBData2(lowerROBData2), // input

        .upperExData(resultPayload1.instructionResult), // input
        .lowerExData(resultPayload2.instructionResult), // input
        .upperExTag(resultPayload1.ageTag), // input
        .lowerExTag(resultPayload2.ageTag), // input
        .lowerExValid(exPayload2.valid), // input

        .payload1(payload1), // input
        .payload2(payload2), // input

        .exPayload1(exPayload1), // output
        .exPayload2(exPayload2) // output
    );

    Execute execute (

        .clock(clock), // input
        .reset(reset), // input

        .redirect(redirect), // output
        .redirectVector(redirectVector), // output

        .redirect1(redirect1), // output
        .redirect2(redirect2), // output

        .exMemory(exMemory), // output

        .exPayload1(exPayload1), // input
        .exPayload2(exPayload2), // input

        .memPayload(memPayload), // output

        .outputValid(outputValid), // input
        .finalOutputData(finalOutputData), // input
        .loadSigned(loadSigned), // output
        .loadWidth(loadWidth), // output
        .inputAddress(inputAddress), // output

        .resultPayload1(resultPayload1), // output
        .resultPayload2(resultPayload2) // output
    );

    DecodeIssue decodeIssue (

        .clock(clock), // input
        .reset(reset), // input

        .redirect(redirect), // input

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

        .oldLowerStatus(oldLowerStatus), // input
        .oldUpperStatus(oldUpperStatus), // input

        .nextFreeSlots(nextFreeSlots), // input
        .freeTag1(freeTag1), // input
        .freeTag2(freeTag2), // input

        .memFreeSlot(memFreeSlot), // input

        .oldUpperStatusRd(oldUpperStatusRd), // output
        .oldLowerStatusRd(oldLowerStatusRd), // output

        .retireTag1(resolvedInstruction1.ageTag), // input
        .retireValid1(resolvedInstruction1.valid), // input
        .retireTag2(resolvedInstruction2.ageTag), // input
        .retireValid2(resolvedInstruction2.valid), // input

        .acceptTag1(resultPayload1.ageTag), // input
        .acceptValid1(resultPayload1.accept), // input
        .acceptTag2(resultPayload2.ageTag), // input
        .acceptValid2(resultPayload2.accept), // input

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
        .redirect(redirect), // input
        .redirectVector(redirectVector), // input
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
        .redirect(redirect), // input
        .redirectVector(redirectVector), // input
        .readAddressA(lowFetchAddress), // input
        .readDataA(lowFetchData), // output
        .readAddressB(highFetchAddress), // input
        .readDataB(highFetchData) // output
    );

endmodule

// some stalls are probably optimal so long as they dont break assumptions
