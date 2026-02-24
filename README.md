## Architectural Roadmap
- 2-Issue Superscalar Front-End
- In-Order Commit ROB
- Precise Trap / Exception Support
- M-Mode RV32I + Zicsr
- Harvard Split BRAM IMEM + External DMEM
- 256-Bit "Walking Window" Prefetch
- Single LSU (Wishbone Classic)
- Store / Load Buffering + Queue
- 6-Stage Pipeline

## Overview
sds

Anvil-Pro specifically targets FPGA platforms, and is optimized around FPGA specific mechanics such as synchronous BRAM and bus routing to an external RAM chip. 

# Frontend
The following section outlines the design philosophy and implimentation of the Anvil-Pro frontend subsystem.

## Fetch Methodology
Anvil-Pro’s front end is designed to sustain a 2-wide issue demand while minimizing redirect penalty and keeping FPGA fabric cost low. Sharing an external instruction interface with the DMEM subsystem was evaluated and rejected: bus arbitration and protocol state add latency, introduce additional control complexity, and reduce deterministic control of fetch timing. Instead, Anvil-Pro uses a strict Harvard organization. IMEM is implemented as inferred synchronous BRAM, allowing instruction fetch to run independently of LSU traffic.

With BRAM-backed IMEM, the remaining optimization is microarchitectural. Canonical queue-driven fetch buffering was initially deployed, but the additional state (FIFO depth, fill/drain behavior, tagging, and boundary handling) increased area and amplified redirect recovery cost. The final design uses a custom 256-bit “Walking Window” prefetch mechanism that exploits wide BRAM reads and dual read ports. Two adjacent 128-bit aligned windows track the canonical PC and are incremented alongside it. Decode requests are satisfied by slicing 32-bit instructions directly from these windows, allowing the BRAM -> IF/ID path to remain direct with no additional stateful staging.

Redirects are wired directly into the registered BRAM address path, so a control transfer immediately updates the fetch address without draining or refilling an intermediate queue. Because no FIFO sits between BRAM and IF/ID, redirect recovery does not pay a queue drain/refill penalty; the next-path instruction becomes visible as soon as the redirected BRAM read returns. This keeps the front end small, deterministic, and tightly aligned with FPGA memory behavior while still providing enough lookahead to sustain a 2-issue demand under sequential flow.

## Issuer Logic and Responsibility
Anvil-Pro utilizes a two-lane issuer that plays a critical role in full system functionality. Through strategic issuer "rule" assignment, potential hazards and complex control logic can be preemtively avoided by preventing hazard cases from ever occuring in the first place. To illustrate this, take an example of a dependency between slot zero and slot one. Determine that slot one needs an operand from slot zero. Given that the instructions are parrallel in the pipeline, their results are executed and finished during the course of the same cycle. To resolve this dependency with forwarding, data would run through a slot execute stage, resolve its results, forward them to the dependent slot, and then that dependent slot would rerun execute. Clearly, this approach creates unsustainable combinational paths that would dramatically reduce Fmax. To avoid this hazard, the issuer may have engrained logic that refuses to issue two instructions that would cause this case, thus preserving performance. 

Anvil-Pro's issuer operates under a strict ruleset contract with the pipeline that prevents many such problems. Primarily, the issuer logic serves three goals:
- Avoid the deliberate creation of non-trivial pipeline hazards
- Solve troublesome dependencies through issue refusal rather than complex control logic and deep combinational paths
- Prevent the need for stall logic entirely in the backend execution flow

To accomplish this, the following rules are established:
- Slot 0 must be older // Dramaticly simplifies control and forward logic
- LSU access must be through slot 0 // Allows for single LSU and simple control
- Memory queue must have slots available including older in pipeline requests (x-1 = capacity) // Prevents stalls on full queue
- No dependencies on unresolved loads // Prevents stalls for arbitrary load times
- ROB must have slots available // Mandatory to functionality
- No slot 0 + slot 1 dependencies // Prevents double execute combinational path
- No slot 1 issues when badData flag is active // Ensures all instructions are valid
- No same cycle dual redirect issues // Simplifies redirect conflicts
- No Write-after-Write hazards in a cycle // prevents age wise forwarding

## Dataflow Diagram
![Pipeline](Pipeline.png)

