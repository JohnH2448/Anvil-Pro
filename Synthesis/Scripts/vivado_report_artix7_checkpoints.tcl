# Regenerate timing and utilization reports from the current Artix-7 DCPs.

set script_dir [file dirname [file normalize [info script]]]
set synthesis_dir [file dirname $script_dir]
set root_dir [file dirname $synthesis_dir]
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

file mkdir $synthesis_dir
file mkdir $reports_dir
file mkdir $checkpoints_dir
file mkdir $logs_dir
cd $synthesis_dir

set synth_dcp [file join $checkpoints_dir artix7_synth.dcp]
set impl_dcp [file join $checkpoints_dir artix7_impl.dcp]

if {[file exists $synth_dcp]} {
    puts "Regenerating synth reports from $synth_dcp"
    open_checkpoint $synth_dcp
    report_utilization -file [file join $reports_dir artix7_utilization.rpt]
    report_timing_summary -file [file join $reports_dir artix7_timing_summary.rpt]
    close_design
} else {
    puts "Skipping synth reports; missing $synth_dcp"
}

if {[file exists $impl_dcp]} {
    puts "Regenerating implementation reports from $impl_dcp"
    open_checkpoint $impl_dcp
    update_timing
    report_utilization -file [file join $reports_dir artix7_impl_utilization.rpt]
    report_timing_summary -file [file join $reports_dir artix7_impl_timing_summary.rpt]
    close_design
} else {
    puts "Skipping implementation reports; missing $impl_dcp"
}

collect_vivado_side_files $synthesis_dir $logs_dir
