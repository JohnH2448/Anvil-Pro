set script_dir [file dirname [file normalize [info script]]]
set synthesis_dir [file dirname $script_dir]
set root_dir [file dirname $synthesis_dir]
set reports_dir [file join $synthesis_dir Reports]
set checkpoints_dir [file join $synthesis_dir Checkpoints]
set logs_dir [file join $synthesis_dir Logs]
set dcp_path [file join $checkpoints_dir artix7_impl.dcp]
set paths_path [file join $reports_dir artix7_timing_paths_failing_100mhz.rpt]
set csv_path [file join $reports_dir artix7_timing_paths_failing_100mhz.csv]

proc collect_vivado_side_files {synthesis_dir logs_dir} {
    foreach side_file {clockInfo.txt dfx_runtime.txt tight_setup_hold_pins.txt} {
        set side_path [file join $synthesis_dir $side_file]
        if {[file exists $side_path]} {
            file rename -force $side_path [file join $logs_dir $side_file]
        }
    }
}

file mkdir $synthesis_dir
file mkdir $reports_dir
file mkdir $checkpoints_dir
file mkdir $logs_dir
cd $synthesis_dir

open_checkpoint $dcp_path

update_timing

set current_clock [get_clocks clock]
set current_period [get_property PERIOD $current_clock]
set target_period 10.000
set slack_threshold [expr {$current_period - $target_period}]

report_timing -delay_type max -slack_lesser_than $slack_threshold -max_paths 10000 -nworst 1 -file $paths_path

set fp [open $csv_path w]
puts $fp "index,current_slack_ns,projected_100mhz_slack_ns,source,destination"

set index 0
foreach path [get_timing_paths -delay_type max -slack_lesser_than $slack_threshold -max_paths 10000 -nworst 1] {
    incr index
    set slack [get_property SLACK $path]
    set projected_slack [expr {$slack - $slack_threshold}]
    set source [get_property STARTPOINT_PIN $path]
    set destination [get_property ENDPOINT_PIN $path]
    puts $fp "$index,$slack,$projected_slack,$source,$destination"
}

close $fp
puts "Current period: $current_period ns"
puts "Target period: $target_period ns"
puts "Slack threshold: $slack_threshold ns"
puts "Failing endpoint paths at projected 100 MHz: $index"
puts "Wrote $paths_path"
puts "Wrote $csv_path"
collect_vivado_side_files $synthesis_dir $logs_dir
