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
    output logic [4:0] upperIssuerRegister1,
    output logic [4:0] upperIssuerRegister2,
    output logic [4:0] lowerIssuerRegister1,
    output logic [4:0] lowerIssuerRegister2,
    output logic [4:0] oldUpperStatusRd,
    output logic [4:0] oldLowerStatusRd,

    // From RST
    input logic upperInFlightLoad1,
    input logic upperInFlightLoad2,
    input logic lowerInFlightLoad1,
    input logic lowerInFlightLoad2,
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

    // Branch Predictor Metadata
    output logic validAddress,
    output logic [31:0] precalcAddress,
    output logic [31:0] branchProgramCounter,
    input logic taken,
    output logic outputJal

);

    // Decode Producer 2
    logic illegal2;
    UpperIssuerOperandPayload_ tempPayload2;
    logic [4:0] destinationRegister2;

    // Decode Producer 1
    logic illegal1;
    UpperIssuerOperandPayload_ tempPayload1;
    logic [4:0] destinationRegister1;

    // To RST
    // Upper Issue Slot Source Registers + rd
    assign upperIssuerRegister1 = tempPayload1.sourceRegister1;
    assign upperIssuerRegister2 = tempPayload1.sourceRegister2;
    assign rstDestinationRegister1 = destinationRegister1;

    // Stale Vector Registers
    assign oldUpperStatusRd = destinationRegister1;
    assign oldLowerStatusRd = destinationRegister2;

    // Lower Issue Slot Source Registers + rd
    assign lowerIssuerRegister1 = tempPayload2.sourceRegister1;
    assign lowerIssuerRegister2 = tempPayload2.sourceRegister2;
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
        if (reset || redirect || taken) begin
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
                postRedirectCounter <= postRedirectCounter + 1'b1;
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
        .destinationRegister(destinationRegister1),
        .illegal(illegal1)
    );

    Decoder decoder2 (
        .instruction(IR2),
        .programCounter(PC2),
        .payload(tempPayload2),
        .destinationRegister(destinationRegister2),
        .illegal(illegal2)
    );

    // Slot 0 Taken Signal
    logic slot0TakenHelper;
    assign slot0TakenHelper = ((tempPayload1.branchType != BR_NONE || tempPayload1.jumpType == JUMP_JAL) && !illegal1) && taken;

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
            // FOR TESTING ONLY
            if (illegal2) begin
                block2 = 1'b1;
                reasonIllegal2 = 1'b1;
            end
            // FOR TESTING ONLY
            if (illegal1) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonIllegal1 = 1'b1;
            end
            // Memory Ops Must Always Issue in Slot 0
            if (tempPayload2.memoryOperation != MEM_NONE) begin
                block2 = 1'b1;
                reasonSlot1Memory = 1'b1;
            end
            // Block WAW To Simplify Forwarding/RST Logic
            // FIXABLE BY REUSING STALEVECTOR MACHINARY MAYBE
            if (destinationRegister1 == destinationRegister2) begin
                block2 = 1'b1; 
                reasonWawConflict = 1'b1;
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
            // Block Issue On Unready Load rs's or rd's. Calculated in RST
            // VITAL and used in subtle RST/ROB Assumptions
            if (upperInFlightLoad1 || upperInFlightLoad2 || destRegLoad1) begin
                block1 = 1'b1;
                block2 = 1'b1;
                reasonUpperLoadHazard = 1'b1;
            end
            if (lowerInFlightLoad1 || lowerInFlightLoad2 || destRegLoad2) begin
                block2 = 1'b1;
                reasonLowerLoadHazard = 1'b1;
            end
            // Block Issue On Backwards Slot 0/1 Dependency to Fix RST Ownership Problems
            // FIXABLE BY REUSING STALEVECTOR MACHINARY
            if ((tempPayload1.sourceRegister1 == destinationRegister2 && destinationRegister2 != 5'd0) ||
                (tempPayload1.sourceRegister2 == destinationRegister2 && destinationRegister2 != 5'd0)) begin
                block2 = 1'b1;
                reasonBackwardDependency = 1'b1;
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
        outputJal = '0;
        branchProgramCounter = '0;
        if ((tempPayload1.branchType != BR_NONE || tempPayload1.jumpType == JUMP_JAL) && !illegal1 && !block1) begin
            precalcAddress = target1;
            branchProgramCounter = PC1;
            outputJal = (tempPayload1.jumpType == JUMP_JAL);
            slot0Taken = taken;
            validAddress = 1'b1;
        end else if ((tempPayload2.branchType != BR_NONE || tempPayload2.jumpType == JUMP_JAL) && !illegal1 && !illegal2 && !block1 && !block2) begin
            precalcAddress = target2;
            branchProgramCounter = PC2;
            outputJal = (tempPayload2.jumpType == JUMP_JAL);
            validAddress = 1'b1;
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
            // Ensures Stale RST Doesn't Otherwise Change Next Cycle
            // PROB AN ISSUE WITH MEM READY HERE
            // Redirect Isn't a concern. This will flush
            if (((oldUpperStatus.ageTag == retireTag1) && retireValid1)
                || ((oldUpperStatus.ageTag == retireTag2) && retireValid2)) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldUpperStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldUpperStatus.ageTag == acceptTag2) && acceptValid2)) &&
                !oldUpperStatus.resultCommitted) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalUpperPayload.predicted = taken ? (slot0Taken ? 1'b1 : 1'b0) : 1'b0;
            finalUpperPayload.staleVector = staleVector1;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload Splice
            finalLowerPayload.programCounter = tempPayload2.programCounter;
            finalLowerPayload.destinationRegister = destinationRegister2;
            finalLowerPayload.sourceRegister1 = tempPayload2.sourceRegister1;
            finalLowerPayload.sourceRegister2 = tempPayload2.sourceRegister2;
            finalLowerPayload.immediate = tempPayload2.immediate;
            finalLowerPayload.aluSource = tempPayload2.aluSource;
            finalLowerPayload.branchType = tempPayload2.branchType;
            finalLowerPayload.aluOperation = tempPayload2.aluOperation;
            finalLowerPayload.jumpType = tempPayload2.jumpType;
            finalLowerPayload.ageTag = freeTag2;
            finalLowerPayload.bypassEnable = bypassEnable;
            finalLowerPayload.staleVector = staleVector2;
            finalLowerPayload.oldStatus = oldLowerStatus;
            if (((oldLowerStatus.ageTag == retireTag1) && retireValid1)
                || ((oldLowerStatus.ageTag == retireTag2) && retireValid2)) begin
                finalLowerPayload.oldStatus.resultReady = 1'b1;
                finalLowerPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldLowerStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldLowerStatus.ageTag == acceptTag2) && acceptValid2)) &&
                !oldLowerStatus.resultCommitted) begin
                finalLowerPayload.oldStatus.resultReady = 1'b1;
                finalLowerPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalLowerPayload.predicted = taken ? (slot0Taken ? 1'b0 : 1'b1) : 1'b0;
            finalLowerPayload.valid = 1'd1;
        end else if (instructionConsumed1) begin
            // Upper Payload
            finalUpperPayload = tempPayload1;
            finalUpperPayload.destinationRegister = destinationRegister1;
            finalUpperPayload.staleVector = staleVector1;
            finalUpperPayload.oldStatus = oldUpperStatus;
            if (((oldUpperStatus.ageTag == retireTag1) && retireValid1)
                || ((oldUpperStatus.ageTag == retireTag2) && retireValid2)) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b1;
            end else if ((((oldUpperStatus.ageTag == acceptTag1) && acceptValid1)
                || ((oldUpperStatus.ageTag == acceptTag2) && acceptValid2)) &&
                !oldUpperStatus.resultCommitted) begin
                finalUpperPayload.oldStatus.resultReady = 1'b1;
                finalUpperPayload.oldStatus.resultCommitted = 1'b0;
            end
            finalUpperPayload.ageTag = freeTag1;
            finalUpperPayload.predicted = taken ? (slot0Taken ? 1'b1 : 1'b0) : 1'b0;
            finalUpperPayload.valid = 1'd1;
            // Lower Payload
            finalLowerPayload = '0;
        end else begin
            // Invalidate Both
            finalUpperPayload = '0;
            finalLowerPayload = '0;
        end
    end

    // Instruction Packet Construction
    logic standardOp1;
    logic standardOp2;
    always_comb begin
        
        instructionPacket1 = '0;
        instructionPacket2 = '0;
        standardOp1 = ((tempPayload1.memoryOperation == MEM_NONE)
        && (tempPayload1.branchType == BR_NONE)
        && (tempPayload1.jumpType == JUMP_NONE));
        standardOp2 = ((tempPayload2.memoryOperation == MEM_NONE)
        && (tempPayload2.branchType == BR_NONE)
        && (tempPayload2.jumpType == JUMP_NONE));

        if (instructionConsumed1 && instructionConsumed2) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.standardOp = standardOp1;
            instructionPacket1.confirm = 1'd1;
            // Instruction 2 to ROB
            instructionPacket2.programCounter = PC2;
            instructionPacket2.destinationRegister = destinationRegister2;
            instructionPacket2.ageTag = freeTag2;
            instructionPacket2.standardOp = standardOp2;
            instructionPacket2.confirm = 1'd1;
        end else if (instructionConsumed1) begin
            // Instruction 1 to ROB
            instructionPacket1.programCounter = PC1;
            instructionPacket1.destinationRegister = destinationRegister1;
            instructionPacket1.ageTag = freeTag1;
            instructionPacket1.standardOp = standardOp1;
            instructionPacket1.confirm = 1'd1;
        end
    end

    // Instruction Payload Assignment
    always_ff @(posedge clock) begin
        payload1 <= finalUpperPayload;
        payload2 <= finalLowerPayload;
    end

    // Focused issue/prediction trace for branch debug.
    always_ff @(negedge clock) begin
        if (!reset && debugMode) begin
            $display("[DecodeIssue] taken=%0b validAddress=%0b branchPC=%08h precalc=%08h",
                taken, validAddress, branchProgramCounter, precalcAddress);
            $display("  pkt0: confirm=%0b pc=%08h tag=%0d rd=x%0d valid=%0b pred=%0b br=%0d j=%0d",
                instructionPacket1.confirm,
                instructionPacket1.programCounter,
                instructionPacket1.ageTag,
                instructionPacket1.destinationRegister,
                finalUpperPayload.valid,
                finalUpperPayload.predicted,
                finalUpperPayload.branchType,
                finalUpperPayload.jumpType);
            $display("  pkt1: confirm=%0b pc=%08h tag=%0d rd=x%0d valid=%0b pred=%0b br=%0d j=%0d",
                instructionPacket2.confirm,
                instructionPacket2.programCounter,
                instructionPacket2.ageTag,
                instructionPacket2.destinationRegister,
                finalLowerPayload.valid,
                finalLowerPayload.predicted,
                finalLowerPayload.branchType,
                finalLowerPayload.jumpType);
        end
    end

    // Single-line issue summary trace.
    /*
    always_ff @(posedge clock) begin
        string slot0Summary;
        string slot1Summary;
        if (!reset) begin
            if (redirect || (postRedirectCounter == 1'b0) || !instructionsValid) begin
                slot0Summary = $sformatf("%-17s", "BRANCH");
                slot1Summary = $sformatf("%-17s", "BRANCH");
            end else begin
                if (instructionConsumed1) begin
                    slot0Summary = $sformatf("%08h %-8s", PC1, "ISSUED");
                end else if (reasonIllegal1) begin
                    slot0Summary = $sformatf("%08h %-8s", PC1, "ILLEGAL");
                end else if (reasonRobFull) begin
                    slot0Summary = $sformatf("%08h %-8s", PC1, "ROBFULL");
                end else if (reasonUpperLoadHazard) begin
                    slot0Summary = $sformatf("%08h %-8s", PC1, "LOADHAZ");
                end else begin
                    slot0Summary = $sformatf("%08h %-8s", PC1, "STALL");
                end

                if (instructionConsumed2) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "ISSUED");
                end else if (reasonIllegal2) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "ILLEGAL");
                end else if (reasonIllegal1) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "SLOT0ILL");
                end else if (reasonSlot1Memory) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "SLOT1MEM");
                end else if (reasonWawConflict) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "WAW");
                end else if (reasonSlotDependency) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "DEP");
                end else if (reasonDualRedirect) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "DUALREDIR");
                end else if (reasonBadFetch) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "BADFETCH");
                end else if (reasonRobOneFree) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "ROB1FREE");
                end else if (reasonRobFull) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "ROBFULL");
                end else if (reasonUpperLoadHazard) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "SLOT0LOAD");
                end else if (reasonLowerLoadHazard) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "LOADHAZ");
                end else if (reasonBackwardDependency) begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "BACKDEP");
                end else begin
                    slot1Summary = $sformatf("%08h %-8s", PC2, "STALL");
                end
            end
            $display("[DecodeIssue][cycle %0d] SLOT0: %s | SLOT1: %s",
                debugCycle, slot0Summary, slot1Summary);
        end
    end
    */

endmodule

// ============ ISSUE RULES ============
// slot 1 can never be to an non-ready rd MAYBE?????
// One CSR in pipe at a time



