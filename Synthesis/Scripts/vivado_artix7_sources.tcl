# Shared non-project source list for the Artix-7 synthesis/implementation runs.
# The including script must define core_dir before sourcing this file.

set anvil_artix7_sources [list \
    $core_dir/Package/SynthConfiguration.sv \
    $core_dir/Package/Enumerations.sv \
    $core_dir/Package/Payloads.sv \
    $core_dir/Blocks/Decoder.sv \
    $core_dir/Control/BranchPredictor.sv \
    $core_dir/Control/BusArbitrator.sv \
    $core_dir/Control/CSRFile.sv \
    $core_dir/Control/InterruptController.sv \
    $core_dir/Control/RegisterFile.sv \
    $core_dir/Control/RegisterStatusTable.sv \
    $core_dir/Control/StoreBuffer.sv \
    $core_dir/Memory/SynthTinyIMEM.sv \
    $core_dir/Pipeline/DecodeIssue.sv \
    $core_dir/Pipeline/Execute.sv \
    $core_dir/Pipeline/MemoryQueue.sv \
    $core_dir/Pipeline/OperandSelect.sv \
    $core_dir/Pipeline/ReorderBuffer.sv \
    $core_dir/Pipeline/WalkingWindow.sv \
    $core_dir/SynthTop.sv \
]
