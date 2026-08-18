# Synthesis Artifacts

Vivado synthesis and implementation outputs are collected here.

- `Reports/`: timing, utilization, and path reports.
- `Checkpoints/`: Vivado design checkpoints.
- `Logs/`: Vivado logs and journals from manual runs.

The Tcl scripts in `Core/` create these directories automatically and collect common Vivado side files into `Logs/`.

For the cleanest manual Vivado runs, pass the log and journal paths explicitly:

```powershell
& "C:\AMDDesignTools\2025.2\Vivado\bin\vivado.bat" -mode batch -source Synthesis/Scripts/vivado_artix7_impl.tcl -journal Synthesis/Logs/vivado.jou -log Synthesis/Logs/vivado.log -tclargs xc7a100tcsg324-3 8.547
```
