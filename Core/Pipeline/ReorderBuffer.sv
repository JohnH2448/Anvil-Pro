typedef struct packed {
    logic [31:0] programCounter; 
    logic [3:0] ageTag;
    logic [31:0] instructionResult;
    logic valid;
} InputInstruction_;

typedef struct packed {
    logic [31:0] programCounter;
    logic [4:0] destinationRegister;
    logic [3:0] ageTag;
    logic isStore;
    logic confirm;
} IssuedIntruction_;

typedef struct packed {
    logic [31:0] programCounter;
    logic [31:0] instructionResult;
    logic [4:0] destinationRegister;
    logic isStore;
    logic valid;
    logic resultsReady;
} QueueEntry_;

typedef struct packed {
    logic [31:0] instructionResult;
    logic [4:0] destinationRegister;
    logic valid;
} RetiredInstruction_;

module ReorderBuffer (
    
    // Standard
    input logic clock,
    input logic reset,

    // Instruction Inputs
    input InputInstruction_ completedMemory,
    input InputInstruction_ completedInstruction1,
    input InputInstruction_ completedInstruction2,
    input IssuedIntruction_ issuedInstruction1,
    input IssuedIntruction_ issuedInstruction2,

    // Writeback Output
    output RetiredInstruction_ resolvedInstruction1,
    output RetiredInstruction_ resolvedInstruction2,
    output logic triggerStore,

    // Control Signals
    output logic bufferFull,

    // Issuer Control Signals
    output logic bufferEntries [3:0],
    output logic [1:0] retireCount
);

    // Full Buffer Declaration
    QueueEntry_ reorderBuffer [0:15];

    always_ff @(posedge clock) begin
        // Reset Clear
        if (reset) begin
            for (int i=0; i<16; i++) begin
                reorderBuffer[i] <= '0;
            end
        end else begin
            // Queue Steps
            case (retireCount)
                // No Retirement
                2'b00: begin

                end
                // Single Retirement
                2'b01: begin
                    // Shift Buffer
                    for (int i=0; i<15; i++) begin
                        reorderBuffer[i] <= reorderBuffer[i+1];
                    end
                    // Entry Fill Logic
                    if (issuedInstruction1.confirm) begin
                        reorderBuffer.programCounter[15] <= issuedInstruction1.programCounter;
                        reorderBuffer.destinationRegister[15] <= issuedInstruction1.destinationRegister;
                        reorderBuffer.ageTag[15] <= issuedInstruction1.ageTag;
                        reorderBuffer.isStore[15] <= issuedInstruction1.isStore;
                    end
                end
                // Dual Retirement
                2'b10: begin
                    // Shift Buffer
                    for (int i=0; i<14; i++) begin
                        reorderBuffer[i] <= reorderBuffer[i+2];
                    end
                    // Entry Fill Logic
                    if (issuedInstruction1.confirm) begin
                        reorderBuffer.programCounter[14] <= issuedInstruction1.programCounter;
                        reorderBuffer.destinationRegister[14] <= issuedInstruction1.destinationRegister;
                        reorderBuffer.ageTag[14] <= issuedInstruction1.ageTag;
                        reorderBuffer.isStore[14] <= issuedInstruction1.isStore;
                    end
                    if (issuedInstruction2.confirm) begin
                        reorderBuffer.programCounter[15] <= issuedInstruction2.programCounter;
                        reorderBuffer.destinationRegister[15] <= issuedInstruction2.destinationRegister;
                        reorderBuffer.ageTag[15] <= issuedInstruction2.ageTag;
                        reorderBuffer.isStore[15] <= issuedInstruction2.isStore;
                    end
                end
                // Cannot Occur
                default: ;
            endcase
        end
    end

endmodule

// EX to EX bypass
// forward else
// must block issuing on WAW
// mem ops must detect illegal before buffer
// store buffer and forward to in progress loads
// try and be conservative with issue rules
// store queue is mandatory
// unified load and store memory queue
// no dual branch issues
// Wait for the head to be a store, 
// then fire it, and then wait for it to come back, 
// and only then continue to commit more
// store uses completedMemory with rd = 0
// for age tags distance = (B - A) mod ROB_SIZE
// 16 entry rob 4 bit age tag
