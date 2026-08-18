# Non-project implementation script for an Artix-7 target.
# Uses the synthesis-focused top and synth-only small configuration.
# Args:
#   1: Artix-7 part name
#   2: clock period in ns, default 13.500 (~74.1 MHz)
#   3: opt_design directive, default ExploreWithRemap
#   4: place_design directive, default ExtraNetDelay_high
#   5: phys_opt_design directive, default AggressiveExplore
#   6: route_design directive, default MoreGlobalIterations
#   7: post-route phys_opt_design directive, default AggressiveExplore

set part_name [expr {[llength $argv] > 0 ? [lindex $argv 0] : "xc7a35tcpg236-1"}]
set clock_period [expr {[llength $argv] > 1 ? [lindex $argv 1] : "13.500"}]
set opt_directive [expr {[llength $argv] > 2 ? [lindex $argv 2] : "ExploreWithRemap"}]
set place_directive [expr {[llength $argv] > 3 ? [lindex $argv 3] : "ExtraNetDelay_high"}]
set phys_opt_directive [expr {[llength $argv] > 4 ? [lindex $argv 4] : "AggressiveExplore"}]
set route_directive [expr {[llength $argv] > 5 ? [lindex $argv 5] : "MoreGlobalIterations"}]
set post_route_phys_opt_directive [expr {[llength $argv] > 6 ? [lindex $argv 6] : "AggressiveExplore"}]
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

puts "Artix-7 impl: part=$part_name clock_period=${clock_period}ns opt=$opt_directive place=$place_directive phys_opt=$phys_opt_directive route=$route_directive post_route_phys_opt=$post_route_phys_opt_directive"

file mkdir $synthesis_dir
file mkdir $reports_dir
file mkdir $checkpoints_dir
file mkdir $logs_dir
cd $synthesis_dir

source [file join $core_dir vivado_artix7_sources.tcl]
read_verilog -sv $anvil_artix7_sources

synth_design -top SynthTop -part $part_name

create_clock -name clock -period $clock_period [get_ports clock]

opt_design -directive $opt_directive
place_design -directive $place_directive
phys_opt_design -directive $phys_opt_directive
route_design -directive $route_directive
if {$post_route_phys_opt_directive ne "none"} {
    phys_opt_design -directive $post_route_phys_opt_directive
    route_design -directive $route_directive
}

report_utilization -file [file join $reports_dir artix7_impl_utilization.rpt]
report_timing_summary -file [file join $reports_dir artix7_impl_timing_summary.rpt]
write_checkpoint -force [file join $checkpoints_dir artix7_impl.dcp]
collect_vivado_side_files $synthesis_dir $logs_dir
