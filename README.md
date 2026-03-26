# Anvil-Pro: A Superscalar RISC-V Processor
![Pipeline](Docs/Pipeline.png)

---
## Overview
Anvil-Pro is a dual-issue RISC-V RV32I + Zicsr softcore targeting FPGA platforms. The core supports M-mode execution, a strict Harvard memory architecture, and a Wishbone Classic data interface for external memory integration.

The microarchitecture implements a 6-stage pipeline with in-order commit via a reorder buffer, a LSU with buffered memory queueing, and a 256-bit “Walking Window” fetch system. Instruction memory is implemented using inferred synchronous BRAM, while data memory is accessed through an external Wishbone interface.

The design is optimized for efficient FPGA fabric utilization, competitive performace, and scalable off-chip data memory capacity. The core is provided as synthesizable SystemVerilog and is suitable for FPGA compute, architectural experimentation, simulation, and custom RISC-V system integration.

## Architectural Roadmap
- Dual-Issue Superscalar Front-End
- In-Order Commit ROB
- Precise Trap / Exception Support
- M-Mode RV32I + Zicsr
- Harvard Split BRAM IMEM + External DMEM
- 256-Bit "Walking Window" Prefetch
- Single LSU (Wishbone Classic)
- Store / Load Buffering + Queue
- 6-Stage Pipeline

---
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

Anvil-Pro eliminates this entire category of behavior. ALU operations complete in fixed latency. Memory operations are injected into the Memory Queue and complete asynchronously. ROB entries are allocated strictly at issue. Future multi-cycle executions can be buffered simmilar to the memory queue. Once dispatched, instructions are never held mid-pipeline and no bubbles are injected due to backend hazards.

If the next instruction cannot safely dispatch due to operand availability or structural capacity, the issuer simply refuses it. The backend continues draining in-flight work but never freezes. Throughput modulation therefore occurs exclusively at issue time rather than through dynamic stall control or bubble propagation.

Under strict in-order issue, issue refusal and traditional stall models exhibit similar IPC behavior during true dependency waits. The primary advantage of Anvil-Pro’s methodology is structural: reduced control depth, simplified verification, and improved timing characteristics. The tradeoff is modest additional resume latency when a previously blocked instruction becomes eligible to issue, since it must traverse the full backend pipeline rather than resuming mid-stage. It was concluded that the simplicity and timing benefits generally outweigh the marginal latency impact for this implimentation.

### Issuer Contract
The issuer guarantees that any dispatched instruction group satisfies the following invariants:
```bash
# Dramatically simplifies control and forwarding logic
- Slot 0 must be older

# For a single LSU, drain is the bottleneck rather than fill
- LSU access must be through slot 0

# Prevents structural hazards and dual-write ambiguity
- No Write-after-Write hazards in a cycle

# Prevents combinational dependency paths unless explicitly bypassed
- No slot 1 dependencies on slot 0 unless EX bypass is enabled

# Enables controlled forwarding instead of blocking
- If EX bypass is enabled, slot 1 dependencies use explicit bypass signals

# Prevents dual redirect ambiguity and control hazards
- No simultaneous branch/jump in both slots

# Prevents propagation of invalid fetch data
- No slot 1 issue when badData flag is active

# Prevents over-allocation of backend resources
- ROB must have at least 2 free slots for dual issue

# Prevents pipeline overcommit
- If only 1 ROB slot is available, only slot 0 may issue

# Hard stop when backend is full
- If no ROB slots are available, no issue occurs

# Prevents stalls from unresolved memory latency
- No dependencies on unresolved loads (per-slot enforcement)

# Prevents ownership and tracking conflicts in RST
- No backward dependencies (slot 0 reading slot 1 destination)

# Ensures structural legality of issued pair
- Both instructions must be valid to issue

# Slot 1 is opportunistic, not guaranteed
- Slot 1 may issue only if all structural, hazard, and capacity rules are satisfied
```
---
## Backend
Anvil-Pro contains a relatively simple backend compared to other implementations. It features two pipelines, each with an operand-selection stage and an execute stage. Depending on the operation type, these stages feed either the reorder buffer or a unified memory queue.

The memory queue is buffered and non-blocking, which allows the pipelines to continue flowing even while older operations remain queued. This is enabled by a simplified out-of-order mechanism, even though the overall design remains conceptually in-order. In particular, the reorder buffer is used both to track forwarding and to guarantee in-order commit, allowing the design to maintain correctness while supporting a buffered memory queue.

Operations issue under the assumption that stall conditions do not occur, and that slot 0 is always older than slot 1. As a result, the forwarding logic is relatively simple. With EX/EX bypass disabled, each source register has four possible data sources. The operand-select mux checks the RST to determine whether data should come from the register file, the ROB entry indicated by the age tag, slot 1 execute, and finally slot 0 execute. This avoids excessive fanout and FPGA routing complexity while still preserving correct age-ordered data selection.

Additionally, if EX/EX bypass is enabled, data can also be forwarded directly from the output of slot 0's ALU to the input/s of slot 1's ALU.

