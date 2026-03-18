import Configuration::*;
import Payloads::*;
import Enumerations::*;

module OperandSelect (

    // Standard
    input logic clock,
    input logic reset,

    // Read From RST
    output logic [4:0] upperSourceRegister1,
    output logic [4:0] upperSourceRegister2,
    output logic [4:0] lowerSourceRegister1,
    output logic [4:0] lowerSourceRegister2,

    // Register Data From RST
    input RegisterStatusOutput_ upperSource1Status,
    input RegisterStatusOutput_ upperSource2Status,
    input RegisterStatusOutput_ lowerSource1Status,
    input RegisterStatusOutput_ lowerSource2Status,

    // Reg File Read Addresses
    output logic [4:0] upperAddress1,
    output logic [4:0] upperAddress2,
    output logic [4:0] lowerAddress1,
    output logic [4:0] lowerAddress2,

    // Reg File Data
    input logic [31:0] upperData1,
    input logic [31:0] upperData2,
    input logic [31:0] lowerData1,
    input logic [31:0] lowerData2,

    // Quad Index Forward Requests To ROB
    output logic [4:0] upperTagIndex1,
    output logic [4:0] upperTagIndex2,
    output logic [4:0] lowerTagIndex1,
    output logic [4:0] lowerTagIndex2,

    // ROB Forward Data
    input logic [31:0] upperROBData1,
    input logic [31:0] upperROBData2,
    input logic [31:0] lowerROBData1,
    input logic [31:0] lowerROBData2,

    // Forward From Ex
    input logic [31:0] upperExData,
    input logic [31:0] lowerExData,
    input logic [4:0] upperExTag,
    input logic [4:0] lowerExTag,

    // Payloads From Issuer
    input UpperIssuerOperandPayload_ payload1,
    input LowerIssuerOperandPayload_ payload2,

    // Payloads to Execute
    UpperOperandExecutePayload_ exPayload1,
    LowerOperandExecutePayload_ exPayload2

);
    // Dummy Candidate Payloads
    UpperOperandExecutePayload_ exPayloadCandidate1;
    LowerOperandExecutePayload_ exPayloadCandidate2;

    // RST Signal Assignment
    assign upperSourceRegister1 = payload1.sourceRegister1;
    assign upperSourceRegister2 = payload1.sourceRegister2;
    assign lowerSourceRegister1 = payload2.sourceRegister1;
    assign lowerSourceRegister2 = payload2.sourceRegister2;

    // Redundant Reg File Signals (Can Use RST Signals)
    assign upperAddress1 = payload1.sourceRegister1;
    assign upperAddress2 = payload1.sourceRegister2;
    assign lowerAddress1 = payload2.sourceRegister1;
    assign lowerAddress2 = payload2.sourceRegister2;

    // ROB Forwarding Requests
    assign upperTagIndex1 = upperSource1Status.ageTag;
    assign upperTagIndex2 = upperSource2Status.ageTag;
    assign lowerTagIndex1 = lowerSource1Status.ageTag;
    assign lowerTagIndex2 = lowerSource2Status.ageTag;

    // Register Portion of Operand Mux
    always_comb begin

        // Candidate Payloads
        exPayloadCandidate1 = '0;
        exPayloadCandidate2 = '0;

        // Upper Source Register 1
        if (upperSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            exPayloadCandidate1.operand1 = upperData1;
        end else if (upperSource1Status.resultReady) begin
            // Use ROB Forward Data
            exPayloadCandidate1.operand1 = upperROBData1;
        end else if (lowerExTag == upperSource1Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            exPayloadCandidate1.operand1 = lowerExData;
        end else if (upperExTag == upperSource1Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            exPayloadCandidate1.operand1 = upperExData;
        end

        // Upper Source Register 2
        if (upperSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            exPayloadCandidate1.operand2 = upperData2;
        end else if (upperSource2Status.resultReady) begin
            // Use ROB Forward Data
            exPayloadCandidate1.operand2 = upperROBData2;
        end else if (lowerExTag == upperSource2Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            exPayloadCandidate1.operand2 = lowerExData;
        end else if (upperExTag == upperSource2Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            exPayloadCandidate1.operand2 = upperExData;
        end


        // Lower Source Register 1
        if (lowerSource1Status.resultCommitted) begin
            // Use Fresh Register Data
            exPayloadCandidate2.operand1 = lowerData1;
        end else if (lowerSource1Status.resultReady) begin
            // Use ROB Forward Data
            exPayloadCandidate2.operand1 = lowerROBData1;
        end else if (lowerExTag == lowerSource1Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            exPayloadCandidate2.operand1 = lowerExData;
        end else if (upperExTag == lowerSource1Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            exPayloadCandidate2.operand1 = upperExData;
        end

        // Lower Source Register 2
        if (lowerSource2Status.resultCommitted) begin
            // Use Fresh Register Data
            exPayloadCandidate2.operand2 = lowerData2;
        end else if (lowerSource2Status.resultReady) begin
            // Use ROB Forward Data
            exPayloadCandidate2.operand2 = lowerROBData2;
        end else if (lowerExTag == lowerSource2Status.ageTag) begin
            // Use Slot 1 Execute Bypass Data
            exPayloadCandidate2.operand2 = lowerExData;
        end else if (upperExTag == lowerSource2Status.ageTag) begin
            // Use Slot 0 Execute Bypass Data
            exPayloadCandidate2.operand2 = upperExData;
        end
    end

endmodule

// do branch target parallel here
// assumes no cross dependencies in mux logic. propably resolve in ex
