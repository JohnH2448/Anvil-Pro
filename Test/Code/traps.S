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

    # stage counter = 0
    addi    x28, x0, 0

    # start first test
    jal     x0, test1

    # pad so trap_vector starts at 0x20
    addi    x0, x0, 0

trap_vector:
    csrr    x31, mcause
    bne     x31, x30, fail

    # advance stage
    addi    x28, x28, 1

    addi    x5, x0, 1
    beq     x28, x5, test2

    addi    x5, x0, 2
    beq     x28, x5, test3

    addi    x5, x0, 3
    beq     x28, x5, test4

    addi    x5, x0, 4
    beq     x28, x5, test5

    addi    x5, x0, 5
    beq     x28, x5, test6

    addi    x5, x0, 6
    beq     x28, x5, test7

    addi    x5, x0, 7
    beq     x28, x5, test8

    addi    x5, x0, 8
    beq     x28, x5, pass

    jal     x0, fail


test1:
    # ECALL -> mcause = 11
    addi    x30, x0, 11
    ecall
    jal     x0, fail

test2:
    # EBREAK -> mcause = 3
    addi    x30, x0, 3
    ebreak
    jal     x0, fail

test3:
    # Misaligned load -> mcause = 4
    addi    x30, x0, 4
    addi    x6, x0, 2
    lw      x7, 0(x6)
    jal     x0, fail

test4:
    # Load access fault -> mcause = 5
    addi    x30, x0, 5
    lui     x6, 0x1
    lw      x7, 0(x6)
    jal     x0, fail

test5:
    # Misaligned store -> mcause = 6
    addi    x30, x0, 6
    addi    x6, x0, 2
    addi    x7, x0, 0x55
    sw      x7, 0(x6)
    jal     x0, fail

test6:
    # Store access fault -> mcause = 7
    addi    x30, x0, 7
    lui     x6, 0x1
    addi    x7, x0, 0x2A
    sw      x7, 0(x6)
    jal     x0, fail

test7:
    # Instruction address misaligned -> mcause = 0
    addi    x30, x0, 0
    addi    x6, x0, 2
    jalr    x0, x6, 0
    jal     x0, fail

test8:
    # Instruction access fault -> mcause = 1
    addi    x30, x0, 1
    lui     x6, 0x1
    jalr    x0, x6, 0
    jal     x0, fail


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
