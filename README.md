# Anvil-Pro: A Superscalar RISC-V Processor
![Pipeline](Docs/Pipeline.png)

## Overview
Anvil-Pro is a RISC-V RV32I + Zicsr + Zifencei softcore optimized for FPGA platforms. The core supports M-mode execution, strict Harvard memory architecture, and a Wishbone Classic data interface for external memory integration.

The design is optimized for efficient FPGA fabric utilization, competitive performance, and scalable off-chip data memory capacity. The core is provided as synthesizable SystemVerilog and is suitable for FPGA compute, architectural experimentation, simulation, and custom SoC system integration.

## Feature List
- Dual-Issue Superscalar
- In-Order Commit ROB
- Latency Reordered Execution
- M-Mode RV32I + Zicsr + Zifencei
- Harvard Split BRAM IMEM + External DMEM
- Branch Prediction
- 256-Bit "Walking Window" Prefetch
- FreeRTOS Compatable
- MMIO Interfaceable CLINT
- Single LSU (Wishbone Classic)
- 6-Stage Pipeline

## Repository Graph
```bash
Core/                              # Main RTL Folder
├─ Blocks/                         # Reusable IP Blocks
│  └─ Decoder.sv                   # Decodes Instructions Into Enable Signals
├─ Control/                        # Pipeline Support Infrastructure Folder
│  ├─ BranchPredictor.sv           # Configurable Non-BTB Branch Prediction
│  ├─ Control.sv                   # Flushes Pipeline
│  ├─ RegisterFile.sv              # Holds Objective Register Data
│  ├─ RegisterStatusTable.sv       # Dictates Register Ownership and State
│  ├─ BusArbitrator.sv             # Multiplexes Slave Bus From Address Range
│  ├─ CSRFile.sv                   # Holds and Updates Objective CSR Data
│  ├─ InterruptController.sv       # MMIO Configurable Interrupt Timer
│  └─ StoreBuffer.sv               # Bypasses Load Issue Restrictions
├─ Memory/                         # Memory Interface Folder
│  ├─ InstructionMemory.sv         # BRAM Instruction Memory
│  ├─ Instructions.hex             # Hex Instruction Initializer
│  └─ PlaceholderDMEM.sv           # Placeholder Data Memory For Simulation
├─ Package/                        # SystemVerilog Package Folder
│  ├─ Configuration.sv             # Configurable Parameters
│  ├─ Enumerations.sv              # Vector Enumeration Definitions
│  └─ Payloads.sv                  # Structure Definitions
├─ Pipeline/                       # Pipeline Folder
│  ├─ DecodeIssue.sv               # Decoder And Issue Contract Enforcer
│  ├─ Execute.sv                   # ALU And Memory Packet Contructor
│  ├─ MemoryQueue.sv               # Drives Wishbone And Queues Memory Ops
│  ├─ OperandSelect.sv             # Multiplexes And Selects Data Sources 
│  ├─ ReorderBuffer.sv             # Accepts And Retires Results From Pipeline
│  └─ WalkingWindow.sv             # Feeds Decoders And Holds PC
└─ Top.sv                          # Hirearchical Top Level Module
```

## Reference
See `ARCHITECTURE.md` for technical reference, design philosophy, and performance microarchitecture rationale. For writing software, stay tuned. A full software-perspective interface guide will be provided with the first published release. 

## Notice
This is not done. I do not reccomend you use it unless you masochistically enjoy debugging CPUs.
