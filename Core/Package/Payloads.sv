import Enumerations::*;
import Configuration::*;

package Payloads;

    // Scoreboard Entry
    typedef struct packed {
        logic isLoad;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic resultReady;
        logic resultCommitted;
    } RegisterStatusEntry_;

    // Scoreboard Output
    typedef struct packed {
        logic resultReady;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic resultCommitted;
    } RegisterStatusOutput_;

    // Ring Buffer for Prefetch Queue
    typedef struct packed {
        logic [31:0] programCounter;
        logic [31:0] instructionData;
        logic requested;
        logic ready;
    } RingBufferEntry_; 

    // For Upper Slot with Memory Support
    typedef struct packed {
        logic [31:0] programCounter;
        logic [4:0] sourceRegister2;
        logic [4:0] sourceRegister1;
        logic [31:0] immediate;
        logic [4:0] destinationRegister;
        AluSource_ aluSource;
        MemoryOperation_ memoryOperation;
        logic [1:0] memoryWidth;
        logic memorySigned;
        BranchType_ branchType; 
        AluOperation_ aluOperation;
        JumpType_ jumpType;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic [1:0] staleVector;
        RegisterStatusOutput_ oldStatus;
        logic predicted;
        logic valid;
    } UpperIssuerOperandPayload_;

    // For Lower Slot
    typedef struct packed {
        logic [31:0] programCounter;
        logic [4:0] sourceRegister2;
        logic [4:0] sourceRegister1;
        logic [31:0] immediate;
        logic [4:0] destinationRegister;
        AluSource_ aluSource;
        BranchType_ branchType; 
        AluOperation_ aluOperation;
        JumpType_ jumpType;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic [1:0] bypassEnable;
        logic [1:0] staleVector;
        RegisterStatusOutput_ oldStatus;
        logic predicted;
        logic valid;
    } LowerIssuerOperandPayload_;

    // For Upper Slot with Memory Support
    typedef struct packed {
        logic [31:0] programCounter;
        logic [31:0] operand1;
        logic [31:0] operand2;
        logic [31:0] extraField; // branch target, store data, etc
        logic [4:0] destinationRegister;
        AluOperation_ aluOperation;
        JumpType_ jumpType;
        BranchType_ branchType;
        MemoryOperation_ memoryOperation;
        logic [1:0] memoryWidth;
        logic memorySigned;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic predicted;
        logic valid;
    } UpperOperandExecutePayload_;

    // For Lower Slot 
    typedef struct packed {
        logic [31:0] operand1;
        logic [31:0] operand2;
        logic [31:0] extraField; // branch target, store data, etc
        logic [4:0] destinationRegister;
        AluOperation_ aluOperation;
        JumpType_ jumpType;
        BranchType_ branchType;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic [1:0] bypassEnable;
        logic predicted;
        logic valid;
    } LowerOperandExecutePayload_;

    // Upper Slot to Memory
    typedef struct packed {
        logic [31:0] address;
        logic [31:0] storeData;
        MemoryOperation_ memoryOperation;
        logic [1:0] memoryWidth;
        logic memorySigned;
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
    } ExecuteMemoryPayload_;

    // Instruction from Pipeline to ROB
    typedef struct packed {
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic [31:0] instructionResult;
        logic [4:0] destinationRegister;
        logic accept;
    } InputInstruction_;

    // Instruction from Issuer to ROB
    typedef struct packed {
        logic [31:0] programCounter;
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic standardOp;
        logic confirm;
    } IssuedIntruction_;

    // Queue Entry Struct
    typedef struct packed {
        logic [31:0] programCounter;
        logic [31:0] instructionResult;
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic standardOp;
        logic completed;
    } QueueEntry_;

    // ROB Output to Regiser File
    typedef struct packed {
        logic [31:0] instructionResult;
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic valid;
    } RetiredInstruction_;

    typedef struct packed {
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
        logic ready;
        logic retired; // store/load status is irrelevant MAYBE NOT LOAD
        logic valid;
    } RestoreStateBus_;

    typedef struct packed {
        logic [31:0] address;
        logic [31:0] storeData;
        logic writeEnable;
        logic [3:0] byteSelect;
        logic cycle;
        logic strobe;
    } WishboneMaster_;

    typedef struct packed {
        logic [31:0] loadData;
        logic acknowledge;
    } WishboneSlave_;

    // Memory Queue Entry
    typedef struct packed {
        logic [31:0] address;
        logic [31:0] storeData;
        MemoryOperation_ memoryOperation;
        logic [3:0] memoryBytes;
        logic [1:0] memoryWidth;
        logic memorySigned;
        logic [4:0] destinationRegister;
        logic [reorderBufferIndexWidth-1:0] ageTag;
    } MemoryQueueEntry_;

    typedef struct packed {
        logic [31:0] address;
        logic [31:0] storeData;
        logic [3:0] memoryBytes;
        logic valid;
    } StoreBus_;

endpackage


