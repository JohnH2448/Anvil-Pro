    .section .text.start, "ax", @progbits
    .globl _start
    .type _start, @function

_start:
    li t0, 0x08
    csrc mstatus, t0
    li t0, 0x80
    csrc mie, t0

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

    # Enable timer interrupts only after runtime startup is complete.
    call anvil_start_timer_interrupts

    call main

1:
    j 1b

    .size _start, . - _start

    .globl anvil_start_timer_interrupts
    .type anvil_start_timer_interrupts, @function
anvil_start_timer_interrupts:
    li t0, 0x80000000
    lw t1, 8(t0)
    li t2, 50000
    add t1, t1, t2

    li t2, -1
    sw t2, 4(t0)
    sw t1, 0(t0)
    sw zero, 4(t0)

    li t0, 0x80
    csrs mie, t0
    li t0, 0x08
    csrs mstatus, t0
    ret

    .size anvil_start_timer_interrupts, . - anvil_start_timer_interrupts

    .globl anvil_trap_handler
    .type anvil_trap_handler, @function
anvil_trap_handler:
    addi sp, sp, -128
    sw ra, 124(sp)
    sw gp, 120(sp)
    sw tp, 116(sp)
    sw t0, 112(sp)
    sw t1, 108(sp)
    sw t2, 104(sp)
    sw s0, 100(sp)
    sw s1, 96(sp)
    sw a0, 92(sp)
    sw a1, 88(sp)
    sw a2, 84(sp)
    sw a3, 80(sp)
    sw a4, 76(sp)
    sw a5, 72(sp)
    sw a6, 68(sp)
    sw a7, 64(sp)
    sw s2, 60(sp)
    sw s3, 56(sp)
    sw s4, 52(sp)
    sw s5, 48(sp)
    sw s6, 44(sp)
    sw s7, 40(sp)
    sw s8, 36(sp)
    sw s9, 32(sp)
    sw s10, 28(sp)
    sw s11, 24(sp)
    sw t3, 20(sp)
    sw t4, 16(sp)
    sw t5, 12(sp)
    sw t6, 8(sp)

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
    li t4, 50000
    add t3, t3, t4
    li t4, -1
    sw t4, 4(t2)
    sw t3, 0(t2)
    sw zero, 4(t2)

    lw t6, 8(sp)
    lw t5, 12(sp)
    lw t4, 16(sp)
    lw t3, 20(sp)
    lw s11, 24(sp)
    lw s10, 28(sp)
    lw s9, 32(sp)
    lw s8, 36(sp)
    lw s7, 40(sp)
    lw s6, 44(sp)
    lw s5, 48(sp)
    lw s4, 52(sp)
    lw s3, 56(sp)
    lw s2, 60(sp)
    lw a7, 64(sp)
    lw a6, 68(sp)
    lw a5, 72(sp)
    lw a4, 76(sp)
    lw a3, 80(sp)
    lw a2, 84(sp)
    lw a1, 88(sp)
    lw a0, 92(sp)
    lw s1, 96(sp)
    lw s0, 100(sp)
    lw t2, 104(sp)
    lw t1, 108(sp)
    lw t0, 112(sp)
    lw tp, 116(sp)
    lw gp, 120(sp)
    lw ra, 124(sp)
    addi sp, sp, 128
    mret

anvil_sync_trap:
    la t2, anvil_sync_trap_count
    lw t3, 0(t2)
    addi t3, t3, 1
    sw t3, 0(t2)
    call anvil_print_hang
1:
    j 1b

    .size anvil_trap_handler, . - anvil_trap_handler

    .type anvil_print_hang, @function
anvil_print_hang:
    li t0, 0x000073fc
    li t1, 0x00007400
    lw t2, 0(t0)

    li t3, 'h'
    andi t4, t2, 0x3ff
    add t4, t4, t1
    sb t3, 0(t4)
    addi t2, t2, 1

    li t3, 'a'
    andi t4, t2, 0x3ff
    add t4, t4, t1
    sb t3, 0(t4)
    addi t2, t2, 1

    li t3, 'n'
    andi t4, t2, 0x3ff
    add t4, t4, t1
    sb t3, 0(t4)
    addi t2, t2, 1

    li t3, 'g'
    andi t4, t2, 0x3ff
    add t4, t4, t1
    sb t3, 0(t4)
    addi t2, t2, 1

    li t3, 10
    andi t4, t2, 0x3ff
    add t4, t4, t1
    sb t3, 0(t4)
    addi t2, t2, 1

    sw t2, 0(t0)
    ret

    .size anvil_print_hang, . - anvil_print_hang

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
    .align 4
__irq_stack_bottom:
    .space 256
__irq_stack_top:
