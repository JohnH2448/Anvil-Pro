import Configuration::*;
import Payloads::*;
import Enumerations::*;

module BranchPredictor (

    // Standard
    input logic clock, 
    input logic reset, 

    // Input Prediction Metadata
    input logic [31:0] precalcAddress,
    input logic [31:0] branchProgramCounter,
    input logic validAddress,
    input logic predictionSlot0,
    input logic outputJal,

    // Update Metadata for Future Dynamic Predictors
    input logic bpUpdateValid1,
    input logic [31:0] bpUpdatePC1,
    input logic bpUpdateTaken1,
    input logic bpUpdateValid2,
    input logic [31:0] bpUpdatePC2,
    input logic bpUpdateTaken2,

    // Taken / Not Taken Signal
    output logic taken

);

    localparam int predictorEntries = 64;
    localparam int predictorIndexWidth = 6;

    logic [1:0] counterTable [0:predictorEntries-1];
    logic [predictorIndexWidth-1:0] predictIndex;
    logic [predictorIndexWidth-1:0] updateIndex1;
    logic [predictorIndexWidth-1:0] updateIndex2;
    logic staticTaken;
    integer i;

    assign predictIndex = branchProgramCounter[predictorIndexWidth+1:2];
    assign updateIndex1 = bpUpdatePC1[predictorIndexWidth+1:2];
    assign updateIndex2 = bpUpdatePC2[predictorIndexWidth+1:2];
    assign staticTaken = (precalcAddress < branchProgramCounter);

    function automatic logic [1:0] saturatingUpdate(
        input logic [1:0] counter,
        input logic wasTaken
    );
        begin
            if (wasTaken) begin
                if (counter != 2'b11) begin
                    saturatingUpdate = counter + 2'b01;
                end else begin
                    saturatingUpdate = counter;
                end
            end else begin
                if (counter != 2'b00) begin
                    saturatingUpdate = counter - 2'b01;
                end else begin
                    saturatingUpdate = counter;
                end
            end
        end
    endfunction

    always_ff @(posedge clock) begin
        if (reset) begin
            for (i = 0; i < predictorEntries; i++) begin
                // Weakly not taken is a simple, conventional reset state.
                counterTable[i] <= 2'b01;
            end
        end else begin
            if (bpUpdateValid1) begin
                counterTable[updateIndex1] <= saturatingUpdate(counterTable[updateIndex1], bpUpdateTaken1);
            end
            if (bpUpdateValid2) begin
                if (bpUpdateValid1 && (updateIndex1 == updateIndex2)) begin
                    counterTable[updateIndex2] <= saturatingUpdate(
                        saturatingUpdate(counterTable[updateIndex2], bpUpdateTaken1),
                        bpUpdateTaken2
                    );
                end else begin
                    counterTable[updateIndex2] <= saturatingUpdate(counterTable[updateIndex2], bpUpdateTaken2);
                end 
            end
        end
    end

    always_comb begin
        taken = 1'b0;
        if (validAddress) begin
            if (outputJal) begin
                taken = 1'b1;
            end else begin
                case (counterTable[predictIndex])
                    2'b00: taken = 1'b0;
                    2'b11: taken = 1'b1;
                    default: taken = staticTaken;
                endcase
            end
        end
    end

endmodule
