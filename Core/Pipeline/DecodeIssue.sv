import Configuration::*;
import Payloads::*;
import Enumerations::*;


module DecodeIssue (

    // Standard
    input logic clock,
    input logic reset,

    // Control Signals
    input logic redirect,

    // Instruction Inputs
    input logic [31:0] instruction1,
    input logic [31:0] instruction2,

    // Window Communication
    output logic instructionConsumed1,
    output logic instructionConsumed2,
    output logic [31:0] requestPC1,
    output logic [31:0] requestPC2,
    input logic [31:0] programCounter,
    input logic badData,

    // Issue Outputs
    output UpperIssuerOperandPayload_ payload1,
    output LowerIssuerOperandPayload_ payload2,

    // ROB Communication
    input logic [1:0] nextFreeSlots,

    // Memory Queue Capacity
    input logic memFreeSlot,

    // Read From RST
    output logic [4:0] oldUpperStatusRd,
    output logic [4:0] oldLowerStatusRd,

    // From RST
    input logic destRegLoad1,
    input logic destRegLoad2,
    input RegisterStatusOutput_ oldUpperStatus,
    input RegisterStatusOutput_ oldLowerStatus,

    // Write To RST
    output logic [4:0] rstDestinationRegister1,
    output logic [4:0] rstDestinationRegister2,
    output logic isLoad1,
    output logic isLoad2,
    output logic [reorderBufferIndexWidth-1:0] ageTag1,
    output logic [reorderBufferIndexWidth-1:0] ageTag2,

    // Instruction Packets to ROB
    output IssuedIntruction_ instructionPacket1,
    output IssuedIntruction_ instructionPacket2,

    // Fresh Tags from ROB
    input logic [reorderBufferIndexWidth-1:0] freeTag1,
    input logic [reorderBufferIndexWidth-1:0] freeTag2,

    // Retire Tags For Stale Vector Calculation
    input logic [reorderBufferIndexWidth-1:0] retireTag1,
    input logic retireValid1,
    input logic [reorderBufferIndexWidth-1:0] retireTag2,
    input logic retireValid2,

    // Accept Tags For Stale Vector Calculation
    input logic [reorderBufferIndexWidth-1:0] acceptTag1,
    input logic acceptValid1,
    input logic [reorderBufferIndexWidth-1:0] acceptTag2,
    input logic acceptValid2,
    input logic memReady,
    input logic [reorderBufferIndexWidth-1:0] memAgeTag,

    // Branch Predictor Metadata
    output logic validAddress,
    output logic [31:0] precalcAddress,
    output logic [31:0] branchProgramCounter,
    output logic predictionSlot0,
    input logic taken,
    output logic outputJal,

    // Stall Bit
    input logic stall,

    // CSR Retirement Data
    input DestinationCSR_ CSRRd1,
    input DestinationCSR_ CSRRd2,
    input logic CSRWriteIntent1,
    input logic CSRWriteIntent2,

    // CSR Table Restore From ROB
    input CSRRestore_ csrBus1,
    input CSRRestore_ csrBus2,
    input CSRRestore_ csrBus3,

    // Trap Detected
    input logic exceptionForFrontend,
    input logic exceptionTaken,

    // Interrupt Interaction
    input logic interrupt,
    output logic interruptTaken

);

    // Decode Producer 2
    UpperIssuerOperandPayload_ tempPayload2;
    logic [4:0] destinationRegister2;

    // Decode Producer 1
    UpperIssuerOperandPayload_ tempPayload1;
    logic [4:0] destinationRegister1;

    // To RST
    // Upper Issue Slot Source Registers + rd
    assign rstDestinationRegister1 = destinationRegister1;

    // Stale Vector Registers
    assign oldUpperStatusRd = destinationRegister1;
    assign oldLowerStatusRd = destinationRegister2;

    // Lower Issue Slot Source Registers + rd
    assign rstDestinationRegister2 = destinationRegister2;

    // Extra Issuer Data to RST
    assign isLoad1 = tempPayload1.memoryOperation == MEM_LOAD;
    assign isLoad2 = tempPayload2.memoryOperation == MEM_LOAD;
    assign ageTag1 = freeTag1;
    assign ageTag2 = freeTag2;
    
    // Final Payloads Passed to OS
    UpperIssuerOperandPayload_ finalUpperPayload;
    LowerIssuerOperandPayload_ finalLowerPayload;

    // Registered Instructions and PCs for Decode 
    logic [31:0] IR1;
    logic [31:0] IR2;
    logic [31:0] PC1;
    logic [31:0] PC2;

    // Vaidity of Instructions in Decode
    logic instructionsValid;

    // Saturating Counter for Post Redirect Use
    logic postRedirectCounter;
    integer debugCycle;

    // Internal Bad Data
    logic internalBadData;

    always_ff @(posedge clock) begin
        if (reset || redirect || taken || exceptionTaken) begin
            if (reset) begin
                debugCycle <= 0;
            end
            instructionsValid <= 1'b0;
            postRedirectCounter <= 1'b0;
            // Can Be Removed
            IR1 <= 32'hdead_beef;
            IR2 <= 32'hdead_beef;
        end else begin
            debugCycle <= debugCycle + 1;
            if (postRedirectCounter) begin
                // Validate Payload
                instructionsValid <= 1'b1;
                // Relatch Fresh Presents Every Valid Cycle
                IR1 <= instruction1;
                IR2 <= instruction2;
                PC1 <= requestPC1;
                PC2 <= requestPC2;
                internalBadData <= badData;
            end else begin
                // Incriment Post Redirect Counter
                postRedirectCounter <= 1'b1;
            end
        end
    end

    // Request PC Speculation Logic
    always_comb begin
        if (instructionsValid == 1'd1) begin
            if (instructionConsumed1 && instructionConsumed2) begin
                requestPC1 = programCounter + 32'd8;
                requestPC2 = programCounter + 32'd12;
            end else if (instructionConsumed1) begin
                requestPC1 = programCounter + 32'd4;
                requestPC2 = programCounter + 32'd8;
            end else begin
                requestPC1 = programCounter;
                requestPC2 = programCounter + 32'd4;
            end
        end else begin
            requestPC1 = programCounter;
            requestPC2 = programCounter + 32'd4;
        end
    end

    Decoder decoder1 (
        .instruction(IR1),
        .programCounter(PC1),
        .payload(tempPayload1),
        .destinationRegister(destinationRegister1)
    );

    Decoder decoder2 (
        .instruction(IR2),
        .programCounter(PC2),
        .payload(tempPayload2),
        .destinationRegister(destinationRegister2)
    );

    // Small Exception Stall FSM
    // NOT DONE
    logic exceptionPending;
    always_ff @(posedge clock) begin
        if (reset) begin
            exceptionPending <= 1'b0;
        end else if (!exceptionPending && redirect && exceptionForFrontend) begin
            exceptionPending <= 1'b1;
        end else if (exceptionPending && exceptionTaken) begin
            exceptionPending <= 1'b0;
        end
    end

    // In Flight CSR FSM
    logic CSRStatus [0:rMCAUSE];
    always_ff @(posedge clock) begin
        if (reset) begin
            for (int i = 0; i <= 10; i++) begin
                CSRStatus[i] <= 1'b0;
            end
        end else begin
            // Clear CSR Status on Commit
            if (CSRWriteIntent1 && (CSRRd1 <= rMCAUSE)) begin
                CSRStatus[CSRRd1] <= 1'b0;
            end
            if (CSRWriteIntent2 && (CSRRd2 <= rMCAUSE)) begin
                CSRStatus[CSRRd2] <= 1'b0;
            end
            // Set CSR Status on Issue
            if (instructionConsumed1 && tempPayload1.system.CSRWriteIntent
            && (tempPayload1.system.destinationCSR <= rMCAUSE)) begin
                CSRStatus[tempPayload1.system.destinationCSR] <= 1'b1;
            end
            if (instructionConsumed2 && tempPayload2.system.CSRWriteIntent
            && (tempPayload2.system.destinationCSR <= rMCAUSE)) begin
                CSRStatus[tempPayload2.system.destinationCSR] <= 1'b1;
            end

            // Clear CSR Status on ROB Restore
            // (instructionComsumed is gated by redirect)
            if (csrBus1.restore && (csrBus1.destinationCSR < rMISA)) begin
                CSRStatus[csrBus1.destinationCSR] <= 1'b0;
            end
            if (csrBus2.restore && (csrBus2.destinationCSR < rMISA)) begin
                CSRStatus[csrBus2.destinationCSR] <= 1'b0;
            end
            if (csrBus3.restore && (csrBus3.destinationCSR < rMISA)) begin
                CSRStatus[csrBus3.destinationCSR] <= 1'b0;
            end

        end
    end

    // Frontend-Visible Trap Overrides
    TrapType_ effectiveTrap1;
    TrapType_ effectiveTrap2;
    always_comb begin
        effectiveTrap1 = tempPayload1.trapType;
        effectiveTrap2 = tempPayload2.trapType;

        if (interrupt) begin
            effectiveTrap1 = INTERRUPT;
        end else if (PC1 < iLowerBound || PC1 >= iUpperBound) begin
            effectiveTrap1 = ACCESS_INST;
        end else if (PC1[1:0] != 2'b00) begin
            effectiveTrap1 = MIS_INST;
        end

        if (PC2 < iLowerBound || PC2 >= iUpperBound) begin
            effectiveTrap2 = ACCESS_INST;
        end else if (PC2[1:0] != 2'b00) begin
            effectiveTrap2 = MIS_INST;
        end
    end

    // Slot 0 Taken Signal
    logic slot0TakenHelper;
    assign slot0TakenHelper = ((tempPayload1.branchType != BR_NONE || tempPayload1.jumpType == JUMP_JAL) && (effectiveTrap1 == NONE)) && taken;

    // Issuer Helper Signals
    logic block1;
    logic block2;
    logic [1:0] bypassEnable;
    logic reasonIllegal1;
    logic reasonIllegal2;
    logic reasonSlot1Memory;
    logic reasonWawConflict;
    logic reasonSlotDependency;
    logic reasonDualRedirect;
    logic reasonBadFetch;
    logic reasonRobOneFree;
    logic reasonRobFull;
    logic reasonUpperLoadHazard;
    logic reasonLowerLoadHazard;
    logic reasonBackwardDependency;

    // Issuer Contract Logic
    always_comb begin
        // Zero Initialize
        block1 = 1'b0;
        block2 = 1'b0;
        bypassEnable = 2'b00;
        reasonIllegal1 = 1'b0;
        reasonIllegal2 = 1'b0;
        reasonSlot1Memory = 1'b0;
        reasonWawConflict = 1'b0;
        reasonSlotDependency = 1'b0;
        reasonDualRedirect = 1'b0;
        reasonBadFetch = 1'b0;
        reasonRobOneFree = 1'b0;
        reasonRobFull = 1'b0;
        reasonUpperLoadHazard = 1'b0;
        reasonLowerLoadHazard = 1'b0;
        reasonBackwardDependency = 1'b0;
        // Both Instructions Valid
        if (instructionsValid) begin
            // Memory Ops Must Always Issue in Slot 0
            if (tempPayload2.memoryOperation != MEM_NONE) begin
                block2 = 1'b1;
                reasonSlot1Memory = 1'b1;
            end
            // Slot 0/1 Dependency Param Gated Generator
            if (!crossLaneExBypass) begin : BYPASS_PARAM
                // Block Slot 0 + Slot 1 Dependencies
                if ((tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) ||
                (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0)) begin
                    block2 = 1'b1;
                    reasonSlotDependency = 1'b1;
                end
            end else begin
                // Ensures Slot 1 Isn't Used Load
                if ((tempPayload1.memoryOperation == MEM_LOAD) 
                && ((destinationRegister1 == tempPayload2.sourceRegister1)
                || (destinationRegister1 == tempPayload2.sourceRegister2))) begin
                    block2 = 1'b1;
                end else begin
                    // Ex/Ex Bypass Bits
                    if (tempPayload2.sourceRegister1 == destinationRegister1 && destinationRegister1 != 5'd0) begin
                        bypassEnable[0] = 1'd1;
                    end
                    if (tempPayload2.sourceRegister2 == destinationRegister1 && destinationRegister1 != 5'd0) begin
                        bypassEnable[1] = 1'd1;
                    end
                end
            end
            // Block Issue on Bad Fetch
            if (internalBadData) begin
                block2 = 1'd1;
                reasonBadFetch = 1'b1;
            end
            // ROB Capacity Gating
            if (nextFreeSlots == 'd1) begin
                block2 = 1'b1;
                reasonRobOneFree = 1'b1;
            end else if (nextFreeSlots == 'd0) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonRobFull = 1'b1;
            end
            // No Issue On Redirect
            if (redirect) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end
            // This is fixable
            if (destRegLoad1) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonUpperLoadHazard = 1'b1;
            end
            if (destRegLoad2) begin
                block2 = 1'b1;
                reasonLowerLoadHazard = 1'b1;
            end
            // Block Memory Ops If Memory Queue is Full
            if (tempPayload1.memoryOperation != MEM_NONE && !memFreeSlot) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end
            // Block Slot 1 If Slot 0 is Prediction
            if (slot0TakenHelper) begin
                // Implimented At Latch Time
            end
            // No Issue on Stall
            if (stall) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end
            // No Issue on CSR WAW
            if (tempPayload1.system.CSROp != CSR_NONE && tempPayload2.system.CSROp != CSR_NONE && tempPayload1.system.destinationCSR == tempPayload2.system.destinationCSR) begin
                block2 = 1'b1;
            end
            // Prevent all CSR Forwarding Cases
            if ((tempPayload1.system.CSROp != CSR_NONE)
            && (tempPayload1.system.destinationCSR <= rMCAUSE)
            && CSRStatus[tempPayload1.system.destinationCSR]) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end else if ((tempPayload2.system.CSROp != CSR_NONE)
            && (tempPayload2.system.destinationCSR <= rMCAUSE)
            && CSRStatus[tempPayload2.system.destinationCSR]) begin
                block2 = 1'b1;
            end
            if (tempPayload1.system.mret && CSRStatus[rMEPC]) begin
                block1 = 1'b1;
                block2 = 1'b1;
             end
             if (tempPayload2.system.mret && CSRStatus[rMEPC]) begin
                block2 = 1'b1;
             end
            // Block Issue While Exception Pending
            if (exceptionPending) begin
                block1 = 1'b1;
                block2 = 1'b1;
            end
        end else begin
            block1 = 1'b1;
            block2 = 1'b1;
        end
    end

    // Redirect Target Precalculation
    logic [31:0] BrIm1;
    logic [31:0] BrIm2;
    logic [31:0] JalIm1;
    logic [31:0] JalIm2;
    logic [31:0] target1;
    logic [31:0] target2;

    always_comb begin
        // Immediate Construction
        BrIm1 = {{19{IR1[31]}}, IR1[31], IR1[7], IR1[30:25], IR1[11:8], 1'b0};
        BrIm2 = {{19{IR2[31]}}, IR2[31], IR2[7], IR2[30:25], IR2[11:8], 1'b0};
        JalIm1 = {{12{IR1[31]}},IR1[19:12],IR1[20],IR1[30:21],1'b0};
        JalIm2 = {{12{IR2[31]}},IR2[19:12],IR2[20],IR2[30:21],1'b0};
        target1 = '0;
        target2 = '0;
        // Result Calculation
        if (tempPayload1.branchType != BR_NONE) begin
            target1 = PC1 + BrIm1;
        end else if (tempPayload1.jumpType == JUMP_JAL) begin
            target1 = PC1 + JalIm1;
        end // JALR needs a register
        if (tempPayload2.branchType != BR_NONE) begin
            target2 = PC2 + BrIm2;
        end else if (tempPayload2.jumpType == JUMP_JAL) begin
            target2 = PC2 + JalIm2;
        end // JALR needs a register
    end
 
    // Redirect Validity
    logic slot0Taken;
    always_comb begin
        validAddress = '0;
        precalcAddress = '0;
        slot0Taken = '0;
        predictionSlot0 = '0;
        outputJal = '0;
        branchProgramCounter = '0;
        if ((tempPayload1.branchType != BR_NONE || tempPayload1.jumpType == JUMP_JAL) && (effectiveTrap1 == NONE) && !block1) begin
            precalcAddress = target1;
            branchProgramCounter = PC1;
            predictionSlot0 = 1'b1;
            outputJal = (tempPayload1.jumpType == JUMP_JAL);
            slot0Taken = taken;
            validAddress = !stall;
        end else if ((tempPayload2.branchType != BR_NONE || tempPayload2.jumpType == JUMP_JAL) && (effectiveTrap1 == NONE) && (effectiveTrap2 == NONE) && !block1 && !block2) begin
            precalcAddress = target2;
            branchProgramCounter = PC2;
            predictionSlot0 = 1'b0;
            outputJal = (tempPayload2.jumpType == JUMP_JAL);
            validAddress = !stall;
        end
        if (precalcAddress[1:0] != 2'b00) begin 
            validAddress = 1'b0;
            slot0Taken = 1'b0;
        end
    end

    // Stale Vector Calculations (rd = rs1 or rs2)
    logic [1:0] staleVector1;
    logic [1:0] staleVector2;
    always_comb begin
        staleVector1 = 2'b00;
        staleVector2 = 2'b00;
        if (tempPayload1.sourceRegister1 == destinationRegister1) begin
            staleVector1[0] = 1'b1;
        end
        if ((tempPayload1.sourceRegister2 == destinationRegister1) 
            && tempPayload1.aluSource == ALU_RS1_RS2) begin
            staleVector1[1] = 1'b1;
        end
        if (tempPayload2.sourceRegister1 == destinationRegister2) begin
            staleVector2[0] = 1'b1;
        end
        if ((tempPayload2.sourceRegister2 == destinationRegister2) 
            && tempPayload2.aluSource == ALU_RS1_RS2) begin
            staleVector2[1] = 1'b1;
        end
    end

    // Stale Vector For Backwards Rd Ownership
    logic [1:0] staleVector3;
    always_comb begin
        staleVector3 = 2'b00;
        // Allow Issue On Backwards Slot 0/1 Dependency to Fix RST Ownership Problems
        if (!block2 && !slot0TakenHelper) begin
            if ((tempPayload1.sourceRegister1 == destinationRegister2 && destinationRegister2 != 5'd0)) begin
                staleVector3[0] = 1'b1;
            end
            if ((tempPayload1.sourceRegister2 == destinationRegister2 && destinationRegister2 != 5'd0)) begin
                staleVector3[1] = 1'b1;
            end
        end
    end

    // Final Payload Assignment
    always_comb begin
        // Instruction Consumption Descision
        instructionConsumed1 = 1'd0;
        instructionConsumed2 = 1'd0;
        if (!reset && !redirect) begin
            if (!block1 && !block2) begin
                instructionConsumed1 = 1'd1;
                if (!slot0TakenHelper) begin
                    instructionConsumed2 = 1'd1;
                end
            end else if (!block1) begin
                instructionConsumed1 = 1'd1;
            end
        end
        // Payload Construction
        if (instructionConsumed1 && instructionConsumed2) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.ageTag = freeTag1;
            finalUpperPayload.oldStatus = oldUpperStatus;
            if (((oldUpperStatus.ageTag == retireTag1) && retireValid1)
                || ((oldUpperStatus.ageTag == retireTag2) && retireValid2)) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldUpperStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldUpperStatus.ageTag == acceptTag2) && acceptValid2)
                || ((oldUpperStatus.ageTag == memAgeTag) && memReady)) &&
                !oldUpperStatus.resultCommitted) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalUpperPayload.predicted = taken ? (slot0Taken ? 1'b1 : 1'b0) : 1'b0;
            finalUpperPayload.staleVector = staleVector1;
            finalUpperPayload.staleVector2 = staleVector3;
            finalUpperPayload.trapType = effectiveTrap1;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload Splice
            finalLowerPayload.programCounter = tempPayload2.programCounter;
            finalLowerPayload.destinationRegister = destinationRegister2;
            finalLowerPayload.sourceRegister1 = tempPayload2.sourceRegister1;
            finalLowerPayload.sourceRegister2 = tempPayload2.sourceRegister2;
            finalLowerPayload.immediate = tempPayload2.immediate;
            finalLowerPayload.aluSource = tempPayload2.aluSource;
            finalLowerPayload.trapType = effectiveTrap2;
            finalLowerPayload.branchType = tempPayload2.branchType;
            finalLowerPayload.aluOperation = tempPayload2.aluOperation;
            finalLowerPayload.jumpType = tempPayload2.jumpType;
            finalLowerPayload.ageTag = freeTag2;
            finalLowerPayload.system = tempPayload2.system;
            finalLowerPayload.bypassEnable = bypassEnable;
            finalLowerPayload.staleVector = staleVector2;
            finalLowerPayload.oldStatus = oldLowerStatus;
            if (((oldLowerStatus.ageTag == retireTag1) && retireValid1)
                || ((oldLowerStatus.ageTag == retireTag2) && retireValid2)) begin
                finalLowerPayload.oldStatus.resultReady = 1'b1;
                finalLowerPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldLowerStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldLowerStatus.ageTag == acceptTag2) && acceptValid2)
                || ((oldLowerStatus.ageTag == memAgeTag) && memReady)) &&
                !oldLowerStatus.resultCommitted) begin
                finalLowerPayload.oldStatus.resultReady = 1'b1;
                finalLowerPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalLowerPayload.predicted = taken ? (slot0Taken ? 1'b0 : 1'b1) : 1'b0;
            finalLowerPayload.trapType = effectiveTrap2;
            finalLowerPayload.valid = 1'd1;
        end else if (instructionConsumed1) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.staleVector = staleVector1;
            finalUpperPayload.oldStatus = oldUpperStatus;
            finalUpperPayload.staleVector2 = staleVector3; 
            if (((oldUpperStatus.ageTag == retireTag1) && retireValid1)
                || ((oldUpperStatus.ageTag == retireTag2) && retireValid2)) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldUpperStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldUpperStatus.ageTag == acceptTag2) && acceptValid2)
                || ((oldUpperStatus.ageTag == memAgeTag) && memReady)) &&
                !oldUpperStatus.resultCommitted) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalUpperPayload.ageTag = freeTag1;
            finalUpperPayload.predicted = taken ? (slot0Taken ? 1'b1 : 1'b0) : 1'b0;
            finalUpperPayload.trapType = effectiveTrap1;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload
            finalLowerPayload = '0;
        end else begin
            // Invalidate Both
            finalUpperPayload = '0;
            finalLowerPayload = '0;
        end
    end 

    // Old Status Update on Stall
    always_ff @(posedge clock) begin
        if (stall) begin
            if (((payload1.oldStatus.ageTag == retireTag1) && retireValid1)
                || ((payload1.oldStatus.ageTag == retireTag2) && retireValid2)) begin
                payload1.oldStatus.resultReady <= 1'b1;
                payload1.oldStatus.resultCommitted <= 1'b1;
            end else if ((((payload1.oldStatus.ageTag == acceptTag1) && acceptValid1)
                || ((payload1.oldStatus.ageTag == acceptTag2) && acceptValid2)
                || ((payload1.oldStatus.ageTag == memAgeTag) && memReady)) &&
                !payload1.oldStatus.resultCommitted) begin
                payload1.oldStatus.resultReady <= 1'b1;
                payload1.oldStatus.resultCommitted <= 1'b0;
            end
            if (((payload2.oldStatus.ageTag == retireTag1) && retireValid1)
                || ((payload2.oldStatus.ageTag == retireTag2) && retireValid2)) begin
                payload2.oldStatus.resultReady <= 1'b1;
                payload2.oldStatus.resultCommitted <= 1'b1;
            end else if ((((payload2.oldStatus.ageTag == acceptTag1) && acceptValid1)
                || ((payload2.oldStatus.ageTag == acceptTag2) && acceptValid2)
                || ((payload2.oldStatus.ageTag == memAgeTag) && memReady)) &&
                !payload2.oldStatus.resultCommitted) begin
                payload2.oldStatus.resultReady <= 1'b1;
                payload2.oldStatus.resultCommitted <= 1'b0;
            end
        end
    end
    
    // Instruction Packet Construction
    logic standardOp1;
    logic standardOp2;
    always_comb begin
        
        instructionPacket1 = '0;
        instructionPacket2 = '0;

        // Dictates Quick Retire Eligibility
        standardOp1 = ((tempPayload1.memoryOperation == MEM_NONE)
        && (tempPayload1.branchType == BR_NONE)
        && (tempPayload1.jumpType == JUMP_NONE)
        && (tempPayload1.system.CSROp == CSR_NONE)
        && (!tempPayload1.system.mret));
        standardOp2 = ((tempPayload2.memoryOperation == MEM_NONE)
        && (tempPayload2.branchType == BR_NONE)
        && (tempPayload2.jumpType == JUMP_NONE)
        && (tempPayload2.system.CSROp == CSR_NONE)
        && (!tempPayload2.system.mret));

        if (instructionConsumed1 && instructionConsumed2) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.standardOp = standardOp1;
            instructionPacket1.CSRWriteIntent = tempPayload1.system.CSRWriteIntent;
            instructionPacket1.destinationCSR = tempPayload1.system.destinationCSR;
            instructionPacket1.mret = tempPayload1.system.mret;
            instructionPacket1.confirm = 1'd1;
            // Instruction 2 to ROB
            instructionPacket2.programCounter = PC2;
            instructionPacket2.destinationRegister = destinationRegister2;
            instructionPacket2.ageTag = freeTag2;
            instructionPacket2.standardOp = standardOp2;
            instructionPacket2.CSRWriteIntent = tempPayload2.system.CSRWriteIntent;
            instructionPacket2.destinationCSR = tempPayload2.system.destinationCSR;
            instructionPacket2.mret = tempPayload2.system.mret;
            instructionPacket2.confirm = 1'd1;
        end else if (instructionConsumed1) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.standardOp = standardOp1;
            instructionPacket1.CSRWriteIntent = tempPayload1.system.CSRWriteIntent;
            instructionPacket1.destinationCSR = tempPayload1.system.destinationCSR;
            instructionPacket1.mret = tempPayload1.system.mret;
            instructionPacket1.confirm = 1'd1;
        end
    end

    // Instruction Payload Assignment
    always_ff @(posedge clock) begin
        if (!stall) begin
            payload1 <= finalUpperPayload;
            payload2 <= finalLowerPayload;
        end
    end

    // Interrupt Acknowledge
    always_comb begin
        interruptTaken = 1'b0;
        if (interrupt && instructionConsumed1) begin
            interruptTaken = 1'd1;
        end
    end

    function automatic string slot0BlockReason();
        if (!instructionsValid || (postRedirectCounter == 1'b0)) begin
            return "Pipeline Refill";
        end
        if (redirect) begin
            return "Redirect Flush";
        end
        if (stall) begin
            return "Operand Select Stall";
        end
        if (reasonIllegal1) begin
            return "Illegal Instruction";
        end
        if (reasonRobFull) begin
            return "ROB Full";
        end
        if (reasonUpperLoadHazard) begin
            return "Load-Owned rd";
        end
        if ((tempPayload1.system.CSROp != CSR_NONE)
        && (tempPayload1.system.destinationCSR <= rMCAUSE)
        && CSRStatus[tempPayload1.system.destinationCSR]) begin
            return "CSR Busy";
        end
        if ((tempPayload1.memoryOperation != MEM_NONE) && !memFreeSlot) begin
            return "Memory Queue Full";
        end
        return "Unknown Stall";
    endfunction

    function automatic string slot1BlockReason();
        if (!instructionsValid || (postRedirectCounter == 1'b0)) begin
            return "Pipeline Refill";
        end
        if (redirect) begin
            return "Redirect Flush";
        end
        if (stall) begin
            return "Operand Select Stall";
        end
        if (slot0TakenHelper) begin
            return "Slot 0 Predicted";
        end
        if (reasonIllegal1) begin
            return "Slot 0 Illegal";
        end
        if (reasonIllegal2) begin
            return "Illegal Instruction";
        end
        if (reasonSlot1Memory) begin
            return "Memory Must Use Slot 0";
        end
        if (reasonWawConflict) begin
            return "WAW Conflict";
        end
        if (reasonSlotDependency) begin
            return "Slot Dependency";
        end
        if (reasonDualRedirect) begin
            return "Dual Redirect";
        end
        if (reasonBadFetch) begin
            return "Bad Fetch";
        end
        if (reasonRobOneFree) begin
            return "One ROB Slot Free";
        end
        if (reasonRobFull) begin
            return "ROB Full";
        end
        if (reasonUpperLoadHazard) begin
            return "Slot 0 Load-Owned rd";
        end
        if (reasonLowerLoadHazard) begin
            return "Load-Owned rd";
        end
        if (crossLaneExBypass && (tempPayload1.memoryOperation == MEM_LOAD)
        && ((destinationRegister1 == tempPayload2.sourceRegister1)
        || (destinationRegister1 == tempPayload2.sourceRegister2))) begin
            return "Slot 0 Load Dependency";
        end
        if (reasonBackwardDependency) begin
            return "Backward Dependency";
        end
        if (tempPayload1.system.CSROp != CSR_NONE && tempPayload2.system.CSROp != CSR_NONE
        && tempPayload1.system.destinationCSR == tempPayload2.system.destinationCSR) begin
            return "CSR WAW Conflict";
        end
        if ((tempPayload1.system.CSROp != CSR_NONE)
        && (tempPayload1.system.destinationCSR <= rMCAUSE)
        && CSRStatus[tempPayload1.system.destinationCSR]) begin
            return "Slot 0 CSR Busy";
        end
        if ((tempPayload2.system.CSROp != CSR_NONE)
        && (tempPayload2.system.destinationCSR <= rMCAUSE)
        && CSRStatus[tempPayload2.system.destinationCSR]) begin
            return "CSR Busy";
        end
        if ((tempPayload1.memoryOperation != MEM_NONE) && !memFreeSlot) begin
            return "Memory Queue Full";
        end
        return "Unknown Stall";
    endfunction

    always_ff @(posedge clock) begin
        if (!reset) begin
            if (instructionConsumed1) begin
                $display("Issued 0x%08h", PC1);
            end else begin
                $display("Blocked 0x%08h: %s", PC1, slot0BlockReason());
            end

            if (instructionConsumed2) begin
                $display("Issued 0x%08h", PC2);
            end else begin
                $display("Blocked 0x%08h: %s", PC2, slot1BlockReason());
            end
        end
    end

endmodule

// ============ ISSUE RULES ============
// Issuer Must Enforce No Forwarding on CSR Ops to Avoid Logic Size in CSR Bypass Logic
// Never create a case when forwarding csr data would happen from pipe, rob, ex/ex bypass etc. 
// Best solution is 1 csr per csr rd 
