_start:
    # mtvec = 0x20
    addi    x5, x0, 32
    csrrw   x0, mtvec, x5

    # Disable machine timer interrupts
    addi    x5, x0, 0x80
    csrrc   x0, mie, x5

    # Disable global machine interrupts
    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5

    # trap count / stage = 0
    addi    x28, x0, 0

    # start tests
    jal     x0, start


trap_vector:
    csrr    x31, mcause
    bne     x31, x30, fail

    # count this trap
    addi    x28, x28, 1

    # resume at next instruction
    csrr    x29, mepc
    addi    x29, x29, 4
    csrw    mepc, x29
    mret


start:
    # Normal aligned memory ops first
    addi    x6, x0, 4
    addi    x7, x0, 0x33
    sw      x7, 0(x6)
    lw      x8, 0(x6)

    # 1) ECALL -> mcause = 11
    addi    x30, x0, 11
    ecall
    addi    x5, x0, 1
    bne     x28, x5, fail

    # Normal branch path
    addi    x9, x0, 5
    addi    x10, x0, 5
    beq     x9, x10, after_branch_1
    jal     x0, fail
after_branch_1:
    addi    x11, x0, 1

    # 2) Illegal instruction -> mcause = 2
    addi    x30, x0, 2
    .word   0x00000000
    addi    x5, x0, 2
    bne     x28, x5, fail

    # 3) EBREAK -> mcause = 3
    addi    x30, x0, 3
    ebreak
    addi    x5, x0, 3
    bne     x28, x5, fail

    # 4) Misaligned load -> mcause = 4
    addi    x30, x0, 4
    addi    x6, x0, 2
    lw      x7, 0(x6)
    addi    x5, x0, 4
    bne     x28, x5, fail

    # More normal code
    addi    x12, x0, 0
    bne     x12, x0, fail
    addi    x12, x12, 1

    # 5) ECALL again -> mcause = 11
    addi    x30, x0, 11
    ecall
    addi    x5, x0, 5
    bne     x28, x5, fail

    # 6) Load access fault -> mcause = 5
    addi    x30, x0, 5
    lui     x6, 0x1
    lw      x7, 0(x6)
    addi    x5, x0, 6
    bne     x28, x5, fail

    # 7) Illegal again -> mcause = 2
    addi    x30, x0, 2
    .word   0x00000000
    addi    x5, x0, 7
    bne     x28, x5, fail

    # 8) Misaligned store -> mcause = 6
    addi    x30, x0, 6
    addi    x6, x0, 2
    addi    x7, x0, 0x55
    sw      x7, 0(x6)
    addi    x5, x0, 8
    bne     x28, x5, fail

    # Branch into another trap site
    addi    x13, x0, 9
    addi    x14, x0, 9
    beq     x13, x14, do_ebreak_2
    jal     x0, fail
do_ebreak_2:

    # 9) EBREAK again -> mcause = 3
    addi    x30, x0, 3
    ebreak
    addi    x5, x0, 9
    bne     x28, x5, fail

    # 10) Store access fault -> mcause = 7
    addi    x30, x0, 7
    lui     x6, 0x1
    addi    x7, x0, 0x2A
    sw      x7, 0(x6)
    addi    x5, x0, 10
    bne     x28, x5, fail

    # Final normal code after lots of returns
    addi    x15, x0, 1
    addi    x16, x15, 1
    beq     x16, x15, fail

pass:
    addi    x10, x0, 1
    slli    x10, x10, 8
    addi    x10, x10, 1
pass_hang:
    jal     x0, pass_hang

fail:
    addi    x10, x0, 1
    slli    x10, x10, 8
    addi    x10, x10, 2
fail_hang:
    jal     x0, fail_hang
