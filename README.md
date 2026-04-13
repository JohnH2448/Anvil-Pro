# Anvil-Pro: A Superscalar RISC-V Processor
![Pipeline](Docs/Pipeline.png)

## Overview
Anvil-Pro is a dual-issue RISC-V RV32I + Zicsr softcore targeting FPGA platforms. The core supports M-mode execution, a strict Harvard memory architecture, and a Wishbone Classic data interface for external memory integration.

The microarchitecture implements a 6-stage pipeline with in-order commit via a reorder buffer, a LSU with buffered memory queueing, and a 256-bit “Walking Window” fetch system. Instruction memory is implemented using inferred synchronous BRAM, while data memory is accessed through an external Wishbone interface.

The design is optimized for efficient FPGA fabric utilization, competitive performance, and scalable off-chip data memory capacity. The core is provided as synthesizable SystemVerilog and is suitable for FPGA compute, architectural experimentation, simulation, and custom RISC-V system integration.

## Architecture Highlights
- Dual-Issue Superscalar Front-End
- In-Order Commit ROB
- Precise Trap / Exception Support
- M-Mode RV32I + Zicsr
- Harvard Split BRAM IMEM + External DMEM
- 256-Bit "Walking Window" Prefetch
- Single LSU (Wishbone Classic)
- Store / Load Buffering + Queue
- 6-Stage Pipeline

## Repository Graph
```bash
Core/                              # Main RTL Folder
├─ Blocks/                         # Reusable IP Blocks
│  └─ Decoder.sv                   # Decodes Instructions Into Enable Signals
├─ Control/                        # Pipeline Support Infrastructure Folder
│  ├─ Control.sv                   # Flushes Pipeline
│  ├─ RegisterFile.sv              # Holds Objective Register Data
│  ├─ RegisterStatusTable.sv       # Dictates Register Ownership and State
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

## Frontend
### Fetch Methodology
Anvil-Pro’s front end is designed to sustain a 2-wide issue demand while minimizing redirect penalty and keeping FPGA fabric cost low. Sharing an external instruction interface with the DMEM subsystem was evaluated and rejected: bus arbitration and protocol state add latency, introduce additional control complexity, and reduce deterministic control of fetch timing. Instead, Anvil-Pro uses a strict Harvard organization. IMEM is implemented as inferred synchronous BRAM, allowing instruction fetch to run independently of LSU traffic.

With BRAM-backed IMEM, the remaining optimization is microarchitectural. Canonical queue-driven fetch buffering was initially deployed, but the additional state (FIFO depth, fill/drain behavior, tagging, and boundary handling) increased area and amplified redirect recovery cost. The final design uses a custom 256-bit “Walking Window” prefetch mechanism that exploits wide BRAM reads and dual read ports. Two adjacent 128-bit aligned windows track the canonical PC and are incremented alongside it. Decode requests are satisfied by slicing 32-bit instructions directly from these windows, allowing the BRAM -> IF/ID path to remain direct with no additional stateful staging.

![Pipeline](Docs/WalkingWindow.png)

Redirects are wired directly into the registered BRAM address path, so a control transfer immediately updates the fetch address without draining or refilling an intermediate queue. Because no FIFO sits between BRAM and IF/ID, redirect recovery does not pay a queue drain/refill penalty; the next-path instruction becomes visible as soon as the redirected BRAM read returns. This keeps the front end small, deterministic, and tightly aligned with FPGA memory behavior while still providing enough lookahead to sustain a 2-issue demand under sequential flow.

Taken together, the design sustains ~2 IPC to the backend on branchless workloads. Following a misprediction, fetch incurs no cycle penalty and the correct instruction stream is already available as if in linear program-order. The approach also avoids LUTRAM-heavy structures such as caches or prefetch queues, substantially reducing FPGA resource usage.

### Issuer Architecture
In many dual-issue designs, the backend is responsible for dynamically resolving hazards through stall propagation, cross-lane forwarding, replay behavior, and inter-stage backpressure. While flexible, that approach introduces long combinational paths, additional control state, and significant verification complexity. These mechanisms directly impact Fmax and make timing closure more difficult.

Anvil-Pro adopts a different philosophy: hazards are prevented at dispatch rather than repaired during execution. The issuer enforces a strict structural contract that guarantees the backend never encounters a stall condition. Once an instruction is dispatched into the pipeline, it flows forward unconditionally. There are no backend freeze signals, no inter-stage ready/valid backpressure, and no replay logic. All throttling occurs exclusively at issue time through refusal.

Traditional stall-based pipelines require bubble injection when a hazard is encountered. If one instruction cannot advance, pipeline registers must be frozen and bubbles inserted to preserve correctness. In a paired in-order machine, this typically forces both lanes to stall to maintain age alignment, even if one instruction could logically continue. This demands inter-lane stall propagation, stage enable gating, and careful management of partially executed instructions.

Anvil-Pro eliminates this entire category of behavior. ALU operations complete in fixed latency. Memory operations are injected into the Memory Queue and complete asynchronously. ROB entries are allocated strictly at issue. Future multi-cycle executions can be buffered similar to the memory queue. Once dispatched, instructions are never held mid-pipeline and no bubbles are injected due to backend hazards.

If the next instruction cannot safely dispatch due to operand availability or structural capacity, the issuer simply refuses it. The backend continues draining in-flight work but never freezes. Throughput modulation therefore occurs exclusively at issue time rather than through dynamic stall control or bubble propagation.

Under strict in-order issue, issue refusal and traditional stall models exhibit similar IPC behavior during true dependency waits. The primary advantage of Anvil-Pro’s methodology is structural: reduced control depth, simplified verification, and improved timing characteristics. The tradeoff is modest additional resume latency when a previously blocked instruction becomes eligible to issue, since it must traverse the full backend pipeline rather than resuming mid-stage. It was concluded that the simplicity and timing benefits generally outweigh the marginal latency impact for this implementation.

### Issuer Contract
The issuer guarantees that any dispatched work satisfies the following invariants for common instruction types:
```txt
# Single Slot Access to LSU
- Lower Slot May Not Issue Memory Operations
# Solves RST Ownership Conflicts
- Lower Slot Must Not Issue When Writing to an Upper Slot Source Register
# Solves RST Ownership + Forwarding Conflicts
- Upper and Lower Slot Must Not Write the Same Register
# Handles Edge Case Window Alignment Failure
- Lower Slot Must Not Issue on Bad Fetch
# Solves RST Ownership Conflicts
- Neither Slot May Issue When It's Destination Register is Being Loaded
# Prevents Ghost Instructions
- Neither Slot May Issue When Reorder Buffer is Full
# Ensures Pipeline is Flushed Correctly
- Neither Slot May Issue During a Redirect
# Prevents Stalls for Arbitrary Load Latency
- Neither Slot May Issue When It's Source Register is Being Loaded
# Prevents Ghost Memory Operations
- Neither Slot May Issue Memory Operations When Memory Queue is Full
```
## Backend
### Philosophy
Anvil-Pro contains a relatively simple backend compared to many other superscalar implementations. It features two pipelines, each composed of an operand-selection stage followed by an execute stage. After execution, instructions either return directly to the reorder buffer or are handed off to a unified memory queue, depending on the operation type.

The backend is built around a strict issue contract. Once an instruction is dispatched, it is expected to continue flowing forward without encountering a backend stall, and slot 0 is always older than slot 1. This allows the design to avoid replay behavior, bubble injection, and inter-stage freeze logic. Rather than repairing hazards dynamically after dispatch, Anvil-Pro prevents them at issue time.

These assumptions lead naturally to a useful distinction between two classes of backend work: non-blocking instructions and blocking instructions. Non-blocking instructions are fixed-latency operations that remain entirely within the core backend pipeline. They pass through operand select and execute, then present their results in-order to the reorder buffer after exactly three cycles. Because their timing is predictable, they form the basis of the backend’s permissive issue model and are intended to flow continuously.

Blocking instructions follow a different path. Rather than completing at a fixed latency inside the main execution fabric, they are handed off to a separate buffered execution structure. In Anvil-Pro, these are primarily memory operations. Once issued, they may remain in flight for an arbitrary amount of time while younger fixed-latency instructions continue to execute. When they eventually finish, they write their results back to the reorder buffer out of issue order.

This is where the reorder buffer becomes central to the backend organization. Although the machine remains architecturally in-order, the reorder buffer allows completion and retirement to be separated. Fixed-latency instructions and buffered operations may finish at different times, but the reorder buffer preserves correctness by holding results, providing forwarded data for completed but uncommitted instructions, and guaranteeing in-order commit. In this sense, the backend supports a constrained and purpose-built form of out-of-order completion without requiring a fully out-of-order scheduler.

Because of this structure, the issuer treats non-blocking and blocking instructions differently. Non-blocking instructions benefit from the backend’s fixed-latency assumptions and can be issued permissively. Blocking instructions require a more conservative issue policy, since unresolved memory operations can create dependencies that cannot be repaired later by backend stall logic. The design therefore attempts to hide the latency of blocking instructions through buffering, but when true dependencies arise, progress is regulated at issue time rather than by freezing the backend.

Additionally, if EX/EX bypass is enabled, data can be forwarded directly from the output of slot 0’s ALU to one or both input operands of slot 1’s ALU. This allows specific same-cycle inter-slot dependencies to be handled explicitly, while still preserving the broader philosophy of issue-time hazard prevention and a stall-free backend.

### Redirect Handling
The pipeline handles redirects carefully to ensure precise architectural state is maintained and all speculative work is properly flushed. The dual execute stages generate a unified redirect signal gated by both legality and validity. When those conditions hold, the signal is asserted. All architectural side effects are then derived combinationally from that single assertion. The primary concerns are fourfold: flushing invalid reorder buffer entries, flushing invalid blocking-instruction queues, restoring correct register status table state, and invalidating the pipeline.

To flush the reorder buffer, the preexisting age-tag system is used to identify the exact desired state. Age tags in the pipeline serve as unique IDs as well as index variables for the reorder buffer. Despite the naming convention, they do not explicitly encode age. When a redirect is detected, the reorder buffer moves its tail pointer to the age tag of the taken branch plus one, which is already implicitly presented to the reorder buffer through the normal instruction retirement interface. Since the validity of the buffer is implicitly encoded by the range between the tail and head pointers, adjusting the tail pointer guarantees a precise flush. This mechanism is both simple and exact, avoiding the usual complexity associated with discarding speculative work.

To flush invalid blocking-instruction queues, the microarchitecture implicitly prevents blocking instructions from ever executing speculatively. Because the pipeline remains in order until post-execute, all branches are resolved before any younger blocking instruction can enter an asynchronous unit such as the memory queue.

Restoring correct RST state is subtle, yet absolutely critical to a proper redirect mechanism. Checkpoint-based systems were considered, but ultimately rejected due to unnecessary state and complexity. Instead, Anvil-Pro derives prior RST state directly from reorder buffer metadata. At most, only three additional instructions can be in the pipeline that may have corrupted RST state. As a result, only three buses or write indexes into the RST are required, which is surprisingly lightweight. On redirect, the pipeline examines the registers modified by speculative work, checks the reorder buffer to determine whether a previous owner exists, and derives the prior state from that metadata. That state is then broadcast to the RST, which restores itself on the following clock edge. The ROB contains three exclusive buses to the RST that are unrolled exclusively on redirect. An internal counter sums the entries being flushed, allocates a bus, checks reduncancy, and finally reconstructs final state and passes it to RST.

Pipeline invalidation is simple and arguably unnecessary, but it is still performed to eliminate ambiguity around valid and invalid work. On redirect, all younger instructions in the pipeline are invalidated. This prevents any edge-case architectural state change and ensures that no speculative work can take effect.

### Forwarding Network
Anvil-Pro dedicates an entire pipeline stage to the multiplexing and selection of operands, and since slot 0 is always older than slot 1, the operand-select stage only needs to consider a small, age-ordered set of candidate data sources. Each source operand can come from one of four places: the register file, the reorder buffer entry identified by the relevant age tag, slot 1 execute, or slot 0 execute.

Selecting the correct producer in the presence of multiple in-flight candidates is the responsibility of the Register Status Table. The RST is deliberately engineered to reflect, from the perspective of operand-select pipeline time, where each architectural register should source from at that exact moment. It tracks the current age-wise owner of each register result, along with whether that result is still in flight, already produced, or fully committed. Operand select interprets this state to arrive at a final source decision. By construction, and under the guarantees established by the issuer contract, one of these candidate sources is always valid. As a result, operand resolution never depends on replay behavior, backend freeze logic, or dynamic stall repair.

The candidate data sources are visualized in the following diagram.

![Pipeline](Docs/Forwarding.png)

The blue arrows in the diagram correspond to data sources for the lower pipeline lane, while the green arrows correspond to data sources for the upper lane. The light red arrow from the upper execute stage to the lower execute stage indicates an additional and optional source path. In a dual-issue superscalar machine, a same-cycle cross-lane dependency can arise when one instruction depends on a value being produced by the other instruction issued alongside it. Resolving this dependency requires dataflow that passes through both ALUs within the same cycle, which can become a timing hazard depending on the target FPGA fabric.

This dependency can always be avoided conservatively by refusing such instruction pairs at issue time. However, doing so sacrifices real dual-issue opportunities and reduces IPC on common code patterns. Since many FPGA platforms provide specialized arithmetic hardware that significantly shortens ALU delay, this path is left as a compile-time parameter. The user may therefore choose whether Anvil-Pro should explicitly support this dependency through direct cross-lane execute bypass, or block it at issue time in favor of a shorter critical path.

There is also an orange arrow from the memory queue to the upper execute slot. This corresponds to store-load forwarding, which is handled separately from ordinary register-result forwarding. Recent stores are held in a small store buffer, allowing younger dependent loads to source their data directly without waiting for the full external memory round trip. This substantially reduces effective load latency, prevents unnecessary pressure on the memory queue, and allows store retirement to remain decoupled from external DMEM acknowledgement.

### Register Status Table
The Register Status Table is the central ownership structure for architectural registers in Anvil-Pro. It does not merely indicate that a register is busy. For each register, it tracks the current producing age tag, whether that producer is a load, whether the result has been produced, and whether it has committed. This gives the pipeline a precise view of register state from the perspective of in-flight work rather than only architected state.

This information is consumed in multiple places. At issue time, the RST is consulted to determine whether source operands are blocked behind unresolved loads, and whether a destination register is currently load-owned in a way that would violate the issue contract. When an instruction is accepted, the destination register is reassigned to the newly issued age tag and marked unready and uncommitted. When a fixed-latency instruction completes, or when a load returns from the memory queue, the corresponding entry is marked ready. When the ROB retires that same age tag, the entry is finally marked committed.

Because the same structure is used for issue gating, operand ownership, and completion bookkeeping, operand select can interpret it directly into a forwarding decision without requiring a separate rename map, a separate scoreboard, or backend repair logic. The RST therefore acts as the pipeline-time source of truth for where each operand should come from and whether a register is safe to consume or overwrite.

This same structure is also restored on redirect. Rather than checkpointing the entire table, the ROB reconstructs the correct prior owner for each flushed destination register and drives that state back into the RST over a small number of restore buses. The result is that register ownership, readiness, and commit visibility are all repaired precisely without introducing broader snapshot machinery.

### Stale Vectors
Stale vectors exist to solve a specific pipeline-time ownership problem created by early destination claiming. When an instruction issues, its destination register is immediately written into the RST as the new owner. For most instructions this is correct. However, for instructions whose source register is the same as their destination register, operand select in the following stage must not observe that newly written ownership. It must instead observe the older producer that existed before issue.

To handle this, the issuer computes a two-bit stale vector for each dispatched instruction. Each bit corresponds to one source operand and indicates whether that source should ignore the live RST view. At the same time, the issuer captures the previous RST state of the destination register and carries it alongside the instruction payload. In operand select, each source operand chooses between the live RST entry and this captured older state according to the stale vector.

This keeps self-referential instructions aligned with correct pipeline-time ownership without weakening the normal RST model. An instruction such as `addi x1, x1, 1` must read the previous owner of `x1`, not the age tag that was just assigned to itself one cycle earlier. The stale-vector mechanism enforces exactly that behavior.

The old-status path is also adjusted for same-cycle ready and retire events before the payload is registered forward. This is necessary because the captured state may otherwise lag the true pipeline view by one cycle. By patching that state before operand select consumes it, Anvil-Pro avoids false dependencies and source mis-selection without introducing heavier inter-stage correction logic.

### Memory
Not globally visable at retirement. 

## Implimentation
### Notice
This core is in progress. The README is currently a technical reference notepad and architectural source of truth, and much is subject to change. Do not take it as a perfect reference, but rather a formalization of design ideas to hold myself accountable to.

## Performance
| Test | No Predictor | Static BTFNT |
|---|---:|---:|
| `add.hex` | 1.4774 | 1.3237 |
| `addi.hex` | 1.4873 | 1.3584 |
| `and.hex` | 1.3977 | 1.2579 |
| `andi.hex` | 1.3643 | 1.2403 |
| `auipc.hex` | 1.1591 | 1.2750 |
| `beq.hex` | 1.0327 | 0.8987 |
| `bge.hex` | 0.9350 | 0.8436 |
| `bgeu.hex` | 0.9424 | 0.8628 |
| `blt.hex` | 1.0327 | 0.8987 |
| `bltu.hex` | 1.0475 | 0.9335 |
| `bne.hex` | 1.0143 | 0.9221 |
| `dependency.hex` | 0.5469 | 0.6425 |
| `jal.hex` | 1.1163 | 1.2308 |
| `jalr.hex` | 0.9000 | 0.8438 |
| `lui.hex` | 1.4500 | 1.4500 |
| `memstress.hex` | 0.4683 | 0.5977 |
| `or.hex` | 1.3588 | 1.2270 |
| `ori.hex` | 1.3469 | 1.2298 |
| `simple.hex` | 1.5455 | 1.5455 |
| `sll.hex` | 1.4551 | 1.3029 |
| `slli.hex` | 1.4717 | 1.3605 |
| `slt.hex` | 1.4868 | 1.3294 |
| `slti.hex` | 1.5033 | 1.3690 |
| `sltiu.hex` | 1.5033 | 1.3690 |
| `sltu.hex` | 1.4868 | 1.3294 |
| `sra.hex` | 1.5030 | 1.3575 |
| `srai.hex` | 1.4647 | 1.3387 |
| `srl.hex` | 1.4896 | 1.3450 |
| `srli.hex` | 1.4727 | 1.3500 |
| `sub.hex` | 1.4706 | 1.3158 |
| `xor.hex` | 1.3953 | 1.2565 |
| `xori.hex` | 1.3333 | 1.2121 |

### Potential Optimizations
- Dual Lane Memory Support
- Allow Issue on Load WAW
- Stalls
- Load Skip to Queue Head
- Better Branch Predictor
- Allow Slot 1 Issue on Slot 0 Taken

### TODO List
- CSR Ecosystem
- System Instruction Support
- Precise Exceptions
- Interupt Support
- Illegal Flag + Handling
- RISCOF Pass

