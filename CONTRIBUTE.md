# Contributing
This core was almost entirely solo designed with hefty bit level optimizations in place. There is significant subtle state, many heavily interacting parts, and poor modularity between IP blocks. 
Changing one thing without knowing the full context of the design (down to exact implimentation details) is likely to break something downstream. For this reason, it is slightly difficult to
approach contributing. While certainly possible, the time sink relative to actual contribution weight is likely not worth it.

However... There are several areas where contributions would be both straightforward, feasible, and extremely helpful. They are as follows:

Verification
- If you can find a particular combination of instructions that produces an incorrect result, this is extremely useful.
- If you can set up the current repository to work with the RISCOF framework, this would provide needed certificate generation.

Memory Queue
- This block in particular is fairly modular to the rest of the design. Optimizing this structure would be very helpful.
In particular, allowing loads to progress to queue head and skip stores would boost IPC. Batching memory operations over
wishbone (if possible) would also help significantly.
- The bus likely does not meet wishbone spec exactly. The bus protocol hasn't been verified against a wishbone corner
case test suite. More verification here and the inevitable subsequent bug fixing would be very helpful.

Software
- CPU runtime code and compiler stuff is not my area of expertise. Creating a strong C runtime environment would be fantastic.

Synthesis
- Imrpoving timing numbers without damaging IPC or correctnes would be much appreciated.
