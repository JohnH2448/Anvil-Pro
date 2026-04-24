_start:
    jal     x0, setup

trap_vector:
    # Check mcause is an interrupt
    csrrs   x31, mcause, x0
    srai    x5, x31, 31
    addi    x6, x0, -1
    bne     x5, x6, fail

    # Check interrupt cause = 7 (machine timer interrupt)
    andi    x5, x31, 0x0f
    addi    x6, x0, 7
    bne     x5, x6, fail

    # Pending timer interrupt must still be visible in mip
    csrrs   x5, mip, x0
    andi    x5, x5, 0x80
    addi    x6, x0, 0x80
    bne     x5, x6, fail

    # In handler: MIE must be 0 and MPIE must be 1
    csrrs   x5, mstatus, x0
    andi    x5, x5, 0x88
    addi    x6, x0, 0x80
    bne     x5, x6, fail

    # Re-arm CLINT for the next interrupt using mtime + delta
    lw      x5, 8(x20)
    add     x5, x5, x21
    addi    x6, x0, -1
    sw      x6, 4(x20)
    sw      x5, 0(x20)
    sw      x0, 4(x20)

    # Count interrupt and publish continue token
    addi    x28, x28, 1
    bne     x28, x26, fail
    add     x27, x28, x0

    mret


setup:
    # mtvec = trap_vector at 0x00000004
    addi    x5, x0, 4
    csrrw   x0, mtvec, x5

    # CLINT base and interrupt spacing
    lui     x20, 0x80000
    addi    x21, x0, 100

    # state
    addi    x28, x0, 0      # interrupt count
    addi    x27, x0, 0      # continue token

    # Reset CLINT timer state for this test
    sw      x0, 8(x20)
    sw      x0, 12(x20)

    # Program first timer interrupt
    addi    x5, x0, -1
    sw      x5, 4(x20)
    sw      x21, 0(x20)
    sw      x0, 4(x20)

    # Verify CLINT compare programming stuck
    lw      x5, 0(x20)
    bne     x5, x21, fail
    lw      x5, 4(x20)
    bne     x5, x0, fail

    # enable machine timer interrupt source in mie
    addi    x5, x0, 0x80
    csrrs   x0, mie, x5

    # keep global interrupts off until each wait window
    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


stage1:
    addi    x26, x0, 1
    addi    x27, x0, 0
    addi    x11, x0, 3
    addi    x11, x11, 4

    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5
wait1:
    bne     x27, x26, wait1

    csrrs   x6, mstatus, x0
    andi    x6, x6, 0x8
    addi    x5, x0, 0x8
    bne     x6, x5, fail

    addi    x5, x0, 7
    bne     x11, x5, fail

    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


stage2:
    addi    x26, x0, 2
    addi    x27, x0, 0
    slli    x12, x11, 2

    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5
wait2:
    bne     x27, x26, wait2

    csrrs   x6, mstatus, x0
    andi    x6, x6, 0x8
    addi    x5, x0, 0x8
    bne     x6, x5, fail

    addi    x5, x0, 28
    bne     x12, x5, fail

    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


stage3:
    addi    x26, x0, 3
    addi    x27, x0, 0
    addi    x13, x0, 9
    xor     x13, x12, x13

    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5
wait3:
    bne     x27, x26, wait3

    csrrs   x6, mstatus, x0
    andi    x6, x6, 0x8
    addi    x5, x0, 0x8
    bne     x6, x5, fail

    addi    x5, x0, 21
    bne     x13, x5, fail

    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


stage4:
    addi    x26, x0, 4
    addi    x27, x0, 0
    addi    x14, x13, -5

    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5
wait4:
    bne     x27, x26, wait4

    csrrs   x6, mstatus, x0
    andi    x6, x6, 0x8
    addi    x5, x0, 0x8
    bne     x6, x5, fail

    addi    x5, x0, 16
    bne     x14, x5, fail

    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


stage5:
    addi    x26, x0, 5
    addi    x27, x0, 0
    addi    x15, x0, 3
    or      x15, x14, x15

    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5
wait5:
    bne     x27, x26, wait5

    csrrs   x6, mstatus, x0
    andi    x6, x6, 0x8
    addi    x5, x0, 0x8
    bne     x6, x5, fail

    addi    x5, x0, 19
    bne     x15, x5, fail

    addi    x5, x0, 0x8
    csrrc   x0, mstatus, x5


final_check:
    addi    x5, x0, 5
    bne     x28, x5, fail

    addi    x5, x0, 7
    bne     x11, x5, fail

    addi    x5, x0, 28
    bne     x12, x5, fail

    addi    x5, x0, 21
    bne     x13, x5, fail

    addi    x5, x0, 16
    bne     x14, x5, fail

    addi    x5, x0, 19
    bne     x15, x5, fail

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
