import Configuration::*;
import Payloads::*;
import Enumerations::*;

module StoreBuffer (

    // Standard
    input logic clock,
    input logic reset,

    // Buses from Store Buffer
    input StoreBus_ storeBus1,
    input StoreBus_ storeBus2,
    input StoreBus_ storeBus3,
    input StoreBus_ storeBus4,
    input StoreBus_ storeBus5,
    input StoreBus_ storeBus6,
    input StoreBus_ storeBus7,
    input StoreBus_ storeBus8,

    // DMEM Acknowledge
    input logic acknowledge,

    // Input Address
    input logic [31:0] inputAddress,
    input logic [1:0] loadWidth,
    input logic loadSigned,

    // Output Data
    output logic [31:0] finalOutputData,
    output logic outputValid

); 

    // Store Buffer Shift Register Entries
    StoreBus_ shiftEntries [0:storeBufferEntries-1];

    // Full State Logic
    always_ff @(posedge clock) begin
        if (reset) begin
            for (int unsigned i = 0; i < storeBufferEntries; i++) begin
                shiftEntries[i] <= '0;
            end
        end else begin
            for (int unsigned i = 0; i < storeBufferEntries; i++) begin
                if (acknowledge && storeBus1.valid && !storeBus1.address[31]) begin
                    if (i != (storeBufferEntries - 1)) begin
                        shiftEntries[i] <= shiftEntries[i + 1];
                    end else begin
                        shiftEntries[storeBufferEntries-1] <= storeBus1;
                    end
                end
            end
        end
    end

    // Priority Selector Byte 1
    logic [7:0] outputByte1;
    logic [7:0] outputByte2;
    logic [7:0] outputByte3;
    logic [7:0] outputByte4;
    logic outputByte1Valid;
    logic outputByte2Valid;
    logic outputByte3Valid;
    logic outputByte4Valid;
    always_comb begin
        outputByte1 = '0;
        outputByte1Valid = 1'b0;
        if (storeBus8.address[31:2] == inputAddress[31:2] && storeBus8.valid && storeBus8.memoryBytes[0]) begin
            outputByte1 = storeBus8.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus7.address[31:2] == inputAddress[31:2] && storeBus7.valid && storeBus7.memoryBytes[0]) begin
            outputByte1 = storeBus7.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus6.address[31:2] == inputAddress[31:2] && storeBus6.valid && storeBus6.memoryBytes[0]) begin
            outputByte1 = storeBus6.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus5.address[31:2] == inputAddress[31:2] && storeBus5.valid && storeBus5.memoryBytes[0]) begin
            outputByte1 = storeBus5.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus4.address[31:2] == inputAddress[31:2] && storeBus4.valid && storeBus4.memoryBytes[0]) begin
            outputByte1 = storeBus4.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus3.address[31:2] == inputAddress[31:2] && storeBus3.valid && storeBus3.memoryBytes[0]) begin
            outputByte1 = storeBus3.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus2.address[31:2] == inputAddress[31:2] && storeBus2.valid && storeBus2.memoryBytes[0]) begin
            outputByte1 = storeBus2.storeData[7:0];
            outputByte1Valid = 1'b1;
        end else if (storeBus1.address[31:2] == inputAddress[31:2] && storeBus1.valid && storeBus1.memoryBytes[0]) begin
            outputByte1 = storeBus1.storeData[7:0];
            outputByte1Valid = 1'b1;
        end
        // "else if"
        for (int i = storeBufferEntries - 1; i >= 0; i--) begin
            if (!outputByte1Valid &&
                shiftEntries[i].valid &&
                shiftEntries[i].memoryBytes[0] &&
                (shiftEntries[i].address[31:2] == inputAddress[31:2])) begin
                outputByte1 = shiftEntries[i].storeData[7:0];
                outputByte1Valid = 1'b1;
            end
        end
    end

    // Priority Selector Byte 2
    always_comb begin
        outputByte2 = '0;
        outputByte2Valid = 1'b0;
        if (storeBus8.address[31:2] == inputAddress[31:2] && storeBus8.valid && storeBus8.memoryBytes[1]) begin
            outputByte2 = storeBus8.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus7.address[31:2] == inputAddress[31:2] && storeBus7.valid && storeBus7.memoryBytes[1]) begin
            outputByte2 = storeBus7.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus6.address[31:2] == inputAddress[31:2] && storeBus6.valid && storeBus6.memoryBytes[1]) begin
            outputByte2 = storeBus6.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus5.address[31:2] == inputAddress[31:2] && storeBus5.valid && storeBus5.memoryBytes[1]) begin
            outputByte2 = storeBus5.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus4.address[31:2] == inputAddress[31:2] && storeBus4.valid && storeBus4.memoryBytes[1]) begin
            outputByte2 = storeBus4.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus3.address[31:2] == inputAddress[31:2] && storeBus3.valid && storeBus3.memoryBytes[1]) begin
            outputByte2 = storeBus3.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus2.address[31:2] == inputAddress[31:2] && storeBus2.valid && storeBus2.memoryBytes[1]) begin
            outputByte2 = storeBus2.storeData[15:8];
            outputByte2Valid = 1'b1;
        end else if (storeBus1.address[31:2] == inputAddress[31:2] && storeBus1.valid && storeBus1.memoryBytes[1]) begin
            outputByte2 = storeBus1.storeData[15:8];
            outputByte2Valid = 1'b1;
        end
        for (int i = storeBufferEntries - 1; i >= 0; i--) begin
            if (!outputByte2Valid &&
                shiftEntries[i].valid &&
                shiftEntries[i].memoryBytes[1] &&
                (shiftEntries[i].address[31:2] == inputAddress[31:2])) begin
                outputByte2 = shiftEntries[i].storeData[15:8];
                outputByte2Valid = 1'b1;
            end
        end
    end

    // Priority Selector Byte 3
    always_comb begin
        outputByte3 = '0;
        outputByte3Valid = 1'b0;
        if (storeBus8.address[31:2] == inputAddress[31:2] && storeBus8.valid && storeBus8.memoryBytes[2]) begin
            outputByte3 = storeBus8.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus7.address[31:2] == inputAddress[31:2] && storeBus7.valid && storeBus7.memoryBytes[2]) begin
            outputByte3 = storeBus7.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus6.address[31:2] == inputAddress[31:2] && storeBus6.valid && storeBus6.memoryBytes[2]) begin
            outputByte3 = storeBus6.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus5.address[31:2] == inputAddress[31:2] && storeBus5.valid && storeBus5.memoryBytes[2]) begin
            outputByte3 = storeBus5.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus4.address[31:2] == inputAddress[31:2] && storeBus4.valid && storeBus4.memoryBytes[2]) begin
            outputByte3 = storeBus4.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus3.address[31:2] == inputAddress[31:2] && storeBus3.valid && storeBus3.memoryBytes[2]) begin
            outputByte3 = storeBus3.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus2.address[31:2] == inputAddress[31:2] && storeBus2.valid && storeBus2.memoryBytes[2]) begin
            outputByte3 = storeBus2.storeData[23:16];
            outputByte3Valid = 1'b1;
        end else if (storeBus1.address[31:2] == inputAddress[31:2] && storeBus1.valid && storeBus1.memoryBytes[2]) begin
            outputByte3 = storeBus1.storeData[23:16];
            outputByte3Valid = 1'b1;
        end
        for (int i = storeBufferEntries - 1; i >= 0; i--) begin
            if (!outputByte3Valid &&
                shiftEntries[i].valid &&
                shiftEntries[i].memoryBytes[2] &&
                (shiftEntries[i].address[31:2] == inputAddress[31:2])) begin
                outputByte3 = shiftEntries[i].storeData[23:16];
                outputByte3Valid = 1'b1;
            end
        end
    end

    // Priority Selector Byte 4
    always_comb begin
        outputByte4 = '0;
        outputByte4Valid = 1'b0;
        if (storeBus8.address[31:2] == inputAddress[31:2] && storeBus8.valid && storeBus8.memoryBytes[3]) begin
            outputByte4 = storeBus8.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus7.address[31:2] == inputAddress[31:2] && storeBus7.valid && storeBus7.memoryBytes[3]) begin
            outputByte4 = storeBus7.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus6.address[31:2] == inputAddress[31:2] && storeBus6.valid && storeBus6.memoryBytes[3]) begin
            outputByte4 = storeBus6.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus5.address[31:2] == inputAddress[31:2] && storeBus5.valid && storeBus5.memoryBytes[3]) begin
            outputByte4 = storeBus5.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus4.address[31:2] == inputAddress[31:2] && storeBus4.valid && storeBus4.memoryBytes[3]) begin
            outputByte4 = storeBus4.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus3.address[31:2] == inputAddress[31:2] && storeBus3.valid && storeBus3.memoryBytes[3]) begin
            outputByte4 = storeBus3.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus2.address[31:2] == inputAddress[31:2] && storeBus2.valid && storeBus2.memoryBytes[3]) begin
            outputByte4 = storeBus2.storeData[31:24];
            outputByte4Valid = 1'b1;
        end else if (storeBus1.address[31:2] == inputAddress[31:2] && storeBus1.valid && storeBus1.memoryBytes[3]) begin
            outputByte4 = storeBus1.storeData[31:24];
            outputByte4Valid = 1'b1;
        end
        for (int i = storeBufferEntries - 1; i >= 0; i--) begin
            if (!outputByte4Valid &&
                shiftEntries[i].valid &&
                shiftEntries[i].memoryBytes[3] &&
                (shiftEntries[i].address[31:2] == inputAddress[31:2])) begin
                outputByte4 = shiftEntries[i].storeData[31:24];
                outputByte4Valid = 1'b1;
            end
        end
    end

    // Combine All Bytes
    logic [31:0] byteBlob;
    assign byteBlob = {outputByte4, outputByte3, outputByte2, outputByte1};

    // Final Data Constructor
    logic [31:0] shiftedLoadData;
    logic [7:0] loadByte;
    logic [15:0] loadHalf;
    always_comb begin
        outputValid = 1'd0;
        // Load Data + Sign Extention
        finalOutputData = '0;
        shiftedLoadData = byteBlob >> (8 * inputAddress[1:0]);
        loadByte = shiftedLoadData[7:0];
        loadHalf = shiftedLoadData[15:0];
        if (!inputAddress[31]) begin
            unique case (loadWidth)
                2'b00: begin
                    unique case (inputAddress[1:0])
                        2'b00: outputValid = outputByte1Valid;
                        2'b01: outputValid = outputByte2Valid;
                        2'b10: outputValid = outputByte3Valid;
                        2'b11: outputValid = outputByte4Valid;
                    endcase
                end
                2'b01: begin
                    unique case (inputAddress[1:0])
                        2'b00: outputValid = outputByte1Valid && outputByte2Valid;
                        2'b01: outputValid = outputByte2Valid && outputByte3Valid;
                        2'b10: outputValid = outputByte3Valid && outputByte4Valid;
                        2'b11: outputValid = 1'b0;
                    endcase
                end
                2'b11: outputValid = (inputAddress[1:0] == 2'b00)
                    && outputByte4Valid && outputByte3Valid && outputByte2Valid && outputByte1Valid;
            endcase
            if (outputValid) begin
                outputValid = 1'd1;
                unique case (loadWidth)
                    2'b00: begin
                        if (loadSigned) begin
                            finalOutputData = {{24{loadByte[7]}}, loadByte};
                        end else begin
                            finalOutputData = {24'b0, loadByte};
                        end
                    end
                    2'b01: begin
                        if (loadSigned) begin
                            finalOutputData = {{16{loadHalf[15]}}, loadHalf};
                        end else begin
                            finalOutputData = {16'b0, loadHalf};
                        end
                    end
                    2'b11: finalOutputData = byteBlob;
                endcase
            end
        end
    end
    
endmodule 
