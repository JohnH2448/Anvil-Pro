# Non-project synthesis script for an Artix-7 target.
# Override PART when invoking Vivado if your board uses a different Artix-7:
#   vivado -mode batch -source Synthesis/Scripts/vivado_artix7_synth.tcl -tclargs xc7a100tcsg324-1
# Optional second arg is clock period in ns. Default is relaxed near the current
# routed-path estimate so timing reports describe the design around ~72 MHz:
#   vivado -mode batch -source Synthesis/Scripts/vivado_artix7_synth.tcl -tclargs xc7a100tcsg324-1 14.000

set part_name [expr {[llength $argv] > 0 ? [lindex $argv 0] : "xc7a35tcpg236-1"}]
set clock_period [expr {[llength $argv] > 1 ? [lindex $argv 1] : "14.000"}]
set script_dir [file dirname [file normalize [info script]]]
set synthesis_dir [file dirname $script_dir]
set root_dir [file dirname $synthesis_dir]
set core_dir [file join $root_dir Core]
set reports_dir [file join $synthesis_dir Reports]
set checkpoints_dir [file join $synthesis_dir Checkpoints]
set logs_dir [file join $synthesis_dir Logs]

proc collect_vivado_side_files {synthesis_dir logs_dir} {
    foreach side_file {clockInfo.txt dfx_runtime.txt tight_setup_hold_pins.txt} {
        set side_path [file join $synthesis_dir $side_file]
        if {[file exists $side_path]} {
            file rename -force $side_path [file join $logs_dir $side_file]
        }
    }
}

puts "Artix-7 synth: part=$part_name clock_period=${clock_period}ns"

file mkdir $synthesis_dir
file mkdir $reports_dir
file mkdir $checkpoints_dir
file mkdir $logs_dir
cd $synthesis_dir

source [file join $core_dir vivado_artix7_sources.tcl]
read_verilog -sv $anvil_artix7_sources

synth_design -top SynthTop -part $part_name

create_clock -name clock -period $clock_period [get_ports clock]

report_utilization -file [file join $reports_dir artix7_utilization.rpt]
report_timing_summary -file [file join $reports_dir artix7_timing_summary.rpt]
write_checkpoint -force [file join $checkpoints_dir artix7_synth.dcp]
collect_vivado_side_files $synthesis_dir $logs_dir
