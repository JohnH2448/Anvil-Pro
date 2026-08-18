# Timing Optimization Log

This file tracks timing-closure experiments, RTL changes, Vivado results, and the git checkpoints that make each state easy to recover.

## Measurement Notes

- Default quick comparison flow: `Synthesis/Scripts/vivado_artix7_synth.tcl` on `xc7a100tcsg324-1`.
- Recent quick timing comparison period: `13.333 ns` (`75.002 MHz`).
- Fmax estimates from synthesis use `1000 / (clock_period_ns - WNS_ns)`.
- Routed Fmax must be confirmed with implementation; synth Fmax is only a directionally useful estimate.

## Current Kept Checkpoints

| Checkpoint | Status | RTL Change | Timing Result | Notes |
| --- | --- | --- | --- | --- |
| `39fa5ba` | Kept | Enabled `registerRestoreBuses(1'b1)` on the ROB in `Core/SynthTop.sv`, `Core/Top.sv`, and `Test/Subsystems/PipelineTest.sv`. | Synth WNS improved from `+1.158 ns` to `+1.297 ns` at `13.333 ns`; estimated synth Fmax `~83.1 MHz`. | Attacks ROB restore-bus routing/control pressure. Ready for Verilator correctness check. |
| `133efce` | Kept tooling | Added `Core/vivado_report_100mhz_paths.tcl`. | Enumerated `2394` endpoint paths that would fail projected 100 MHz timing from the latest routed DCP at the time. | Report helper only; no RTL change. |
| `776f186` | Kept | Added two-entry DecodeIssue-to-OperandSelect issue queue. | Synth WNS `+1.158 ns` at `13.333 ns`; estimated synth Fmax `~82.1 MHz`. | Last known good timing baseline before restore-bus registration. Correctness-sensitive; user had been running Verilator checks. |
| `18cdf07` | Kept | Gated unused source2 operand stall work. | Improved prior timing pressure; exact final retained comparison superseded by later checkpoints. | Local pressure relief in OperandSelect/control paths. |
| `c7cee83` | Kept | Added explicit execute bypass outputs. | Improved timing directionally in prior synth iterations. | Reduced implicit/broad execute bypass cones. |
| `16f3034` | Kept | Decoupled decoded `rd` from illegal-trap result. | Improved timing directionally in prior synth iterations. | Reduced DecodeIssue decoder-result coupling. |
| `3ead93f` | Kept | Predecoded memory target for bus return mux. | Improved timing directionally in prior synth iterations. | Reduced memory return select/control pressure. |

## Reverted Or Dropped Experiments

| Checkpoint / State | Status | RTL Change | Timing Result | Reason |
| --- | --- | --- | --- | --- |
| Uncommitted experiment after `776f186` | Dropped | Registered normal ROB commit outputs (`resolvedInstruction*`, `csrOut*`, `retireCount`, exception outputs). | Synth WNS worsened to `+0.946 ns` at `13.333 ns`; estimated synth Fmax `~80.7 MHz`. | Moved worst path into restore-bus/RST logic and increased pressure; reverted before the kept restore-bus change. |
| `412313a` | Reverted by `46836eb` | Tied off store-buffer path in top levels. | Timing was good, but IPC collapsed. | Reverted to restore StoreBuffer behavior. |
| `1958514` | Reverted by `624a0ca` | Cut memory-queue feedback timing paths. | Did not survive correctness/timing iteration. | Reverted. |
| Decode moved into walking-window slices | Reverted by `f502779` | Moved decoder module back toward instruction slices. | Experiment was killed and reverted. | Did not produce a useful implementation result. |

## Latest Useful Numbers

- Artix-7 `-3` full implementation sweep from RTL checkpoint `39fa5ba`:
  - Part: `xc7a100tcsg324-3`
  - Flow: `Synthesis/Scripts/vivado_artix7_impl.tcl`
  - Directives: `opt_design ExploreWithRemap`, `place_design ExtraNetDelay_high`, `phys_opt_design AggressiveExplore`, `route_design MoreGlobalIterations`, post-route `phys_opt_design AggressiveExplore`
  - Highest closed target run: `117 MHz` (`8.547 ns`) with signoff setup slack `+0.000 ns`
  - Practical hard Fmax from this sweep: `117 MHz` routed signoff, but with no usable margin
  - 116 MHz run: `+0.022 ns` WNS, implied edge `~116.3 MHz`
  - 115 MHz run: `+0.002 ns` WNS
  - 117 MHz worst setup path: `operandSelect/exPayload1_reg[operand1][15] -> operandSelect/exPayload1_reg[operand2][2]`
  - 117 MHz data delay: `8.175 ns` (`1.408 ns` logic, `6.767 ns` route)
  - 117 MHz utilization: `11046` LUTs, `4999` FFs, `4` BRAM tiles, `0` DSPs, `106` IOBs
  - Saved reports: `Synthesis/Reports/artix7_impl_timing_summary.xc7a100t-3_100mhz_opt.rpt` through `Synthesis/Reports/artix7_impl_timing_summary.xc7a100t-3_117mhz_opt.rpt`
  - Note: no RTL change was made during this sweep; this is a measurement/logging entry only.

- Latest kept synth result after `39fa5ba`:
  - WNS: `+1.297 ns`
  - WHS: `+0.137 ns`
  - Estimated synth Fmax: `~83.1 MHz`
  - Worst synth path: `operandSelect/exPayload1_reg[operand1][27] -> exceptionForFrontend_reg`
  - Data delay: `11.900 ns` (`3.293 ns` logic, `8.607 ns` route)
  - Utilization: `10932` LUTs, `4999` FFs, `4` BRAM tiles, `0` DSPs, `106` IOBs

- Latest routed 85 MHz default-directive implementation before `39fa5ba`:
  - Period: `11.765 ns`
  - WNS: `-0.522 ns`
  - Implied routed Fmax: `~81.4 MHz`
  - Worst routed path: `reorderBuffer/headPointer_reg[0] -> registerStatusTable/registerStatusTable_reg[16][resultCommitted]`

## Future Entry Format

For each new experiment, add:

| Checkpoint | Status | RTL Change | Timing Result | Correctness Result | Notes |
| --- | --- | --- | --- | --- | --- |
| `<hash>` | Kept / Reverted / Dropped | `<short description>` | `<WNS/Fmax/worst path>` | `<Verilator result if run>` | `<why it matters>` |
