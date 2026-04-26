    .section .text.start, "ax", @progbits
    .globl _start
    .type _start, @function

_start:
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop

    la sp, __stack_top

    la t0, anvil_trap_handler
    csrw mtvec, t0

    la t0, __bss_start
    la t1, __bss_end
1:
    bgeu t0, t1, 2f
    sw zero, 0(t0)
    addi t0, t0, 4
    j 1b

2:
    la t0, __debug_log_index
    sw zero, 0(t0)

    call __anvil_init_data

    call main

    beqz a0, 3f
    li a0, 0x102
    j 4f
3:
    li a0, 0x101
4:
    j 4b

    .size _start, . - _start

    .globl anvil_trap_handler
    .type anvil_trap_handler, @function
anvil_trap_handler:
    addi sp, sp, -64
    sw ra, 60(sp)
    sw t0, 56(sp)
    sw t1, 52(sp)
    sw t2, 48(sp)
    sw t3, 44(sp)
    sw t4, 40(sp)
    sw t5, 36(sp)
    sw t6, 32(sp)
    sw a0, 28(sp)
    sw a1, 24(sp)

    csrr t0, mcause
    csrr t1, mepc

    la t2, anvil_last_trap_cause
    sw t0, 0(t2)
    la t2, anvil_last_trap_epc
    sw t1, 0(t2)

    srli t2, t0, 31
    beqz t2, anvil_sync_trap

    andi t2, t0, 0x0f
    li t3, 7
    beq t2, t3, anvil_timer_interrupt
    j anvil_sync_trap

anvil_timer_interrupt:
    la t2, anvil_timer_interrupt_count
    lw t3, 0(t2)
    addi t3, t3, 1
    sw t3, 0(t2)

    li t2, 0x80000000
    lw t3, 8(t2)
    li t4, 1000
    add t3, t3, t4
    li t4, -1
    sw t4, 4(t2)
    sw t3, 0(t2)
    sw zero, 4(t2)

    lw a1, 24(sp)
    lw a0, 28(sp)
    lw t6, 32(sp)
    lw t5, 36(sp)
    lw t4, 40(sp)
    lw t3, 44(sp)
    lw t2, 48(sp)
    lw t1, 52(sp)
    lw t0, 56(sp)
    lw ra, 60(sp)
    addi sp, sp, 64
    mret

anvil_sync_trap:
    la t2, anvil_sync_trap_count
    lw t3, 0(t2)
    addi t3, t3, 1
    sw t3, 0(t2)
1:
    j 1b

    .size anvil_trap_handler, . - anvil_trap_handler

    .section .bss, "aw", @nobits
    .globl anvil_timer_interrupt_count
    .globl anvil_sync_trap_count
    .globl anvil_last_trap_cause
    .globl anvil_last_trap_epc
    .align 2
anvil_timer_interrupt_count:
    .word 0
anvil_sync_trap_count:
    .word 0
anvil_last_trap_cause:
    .word 0
anvil_last_trap_epc:
    .word 0
