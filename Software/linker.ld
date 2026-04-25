OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
    IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 16K
    DMEM (rwx) : ORIGIN = 0x00004000, LENGTH = 16K
}

__stack_size = 0x800;
__debug_size = 0x400;
__debug_index_size = 0x4;

SECTIONS
{
    .text : ALIGN(4)
    {
        KEEP(*(.init))
        KEEP(*(.text.start))
        *(.text .text.*)
        KEEP(*(.fini))
        . = ALIGN(4);
    } > IMEM

    .rodata : ALIGN(4)
    {
        __global_pointer$ = . + 0x800;
        __rodata_start = .;
        *(.srodata .srodata.*)
        *(.rodata .rodata.*)
        . = ALIGN(4);
        __rodata_end = .;
    } > DMEM

    .data : ALIGN(4)
    {
        __data_start = .;
        *(.sdata .sdata.*)
        *(.data .data.*)
        . = ALIGN(4);
        __data_end = .;
    } > DMEM

    .bss (NOLOAD) : ALIGN(4)
    {
        __bss_start = .;
        *(.sbss .sbss.*)
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > DMEM

    .heap (NOLOAD) : ALIGN(4)
    {
        __heap_start = .;
        . = ORIGIN(DMEM) + LENGTH(DMEM) - __stack_size - __debug_size - __debug_index_size;
        __heap_end = .;
    } > DMEM

    .debug_log (NOLOAD) : ALIGN(4)
    {
        __debug_log_index = .;
        . += __debug_index_size;
        __debug_log_start = .;
        . += __debug_size;
        __debug_log_end = .;
    } > DMEM

    .stack (NOLOAD) : ALIGN(16)
    {
        __stack_bottom = .;
        . += __stack_size;
        . = ALIGN(16);
        __stack_top = .;
    } > DMEM

    /DISCARD/ :
    {
        *(.comment)
        *(.riscv.attributes)
        *(.eh_frame)
        *(.eh_frame_hdr)
    }

    ASSERT(__rodata_start == __rodata_end, "Anvil runtime does not support preinitialized .rodata; build constants manually in .bss or generated startup code")
    ASSERT(__data_start == __data_end, "Anvil runtime does not support preinitialized .data; build globals manually in .bss or generated startup code")
}
