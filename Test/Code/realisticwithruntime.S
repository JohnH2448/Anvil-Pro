_start:
    jal     x0, setup

trap_vector:
    # Save clobbered temporaries
    sw      x5, 12(x22)
    sw      x6, 16(x22)
    sw      x31, 20(x22)

    # Verify machine timer interrupt
    csrrs   x31, mcause, x0
    srai    x5, x31, 31
    addi    x6, x0, -1
    bne     x5, x6, fail_trap

    andi    x5, x31, 0x0f
    addi    x6, x0, 7
    bne     x5, x6, fail_trap

    # Verify trap-entry mstatus: MIE=0, MPIE=1
    csrrs   x5, mstatus, x0
    andi    x5, x5, 0x88
    addi    x6, x0, 0x80
    bne     x5, x6, fail_trap

    # Verify mip still shows MTIP pending
    csrrs   x5, mip, x0
    andi    x5, x5, 0x80
    addi    x6, x0, 0x80
    bne     x5, x6, fail_trap

    # Count interrupts
    addi    x28, x28, 1

    # Re-arm timer: mtimecmp = mtime + interval
    lw      x5, 8(x20)
    add     x5, x5, x21
    addi    x6, x0, -1
    sw      x6, 4(x20)
    sw      x5, 0(x20)
    sw      x0, 4(x20)

    # Publish interrupt-seen token
    addi    x27, x0, 1

    # Restore temporaries and return
    lw      x5, 12(x22)
    lw      x6, 16(x22)
    lw      x31, 20(x22)
    mret

setup:
    # mtvec = trap_vector at 0x00000004
    addi    x5, x0, 4
    csrrw   x0, mtvec, x5

    # CLINT base and interval
    lui     x20, 0x80000       # x20 = 0x80000000
    addi    x21, x0, 100       # 100 tick interval

    # Scratch state
    addi    x27, x0, 0         # interrupt seen flag
    addi    x28, x0, 0         # interrupt count

    # Base RAM scratch
    addi    x22, x0, 0x40
    sw      x0, 0(x22)
    sw      x0, 4(x22)
    sw      x0, 8(x22)
    sw      x0, 12(x22)
    sw      x0, 16(x22)
    sw      x0, 20(x22)

    # Reset CLINT timer state
    sw      x0, 8(x20)
    sw      x0, 12(x20)

    # Program first interrupt safely
    addi    x5, x0, -1
    sw      x5, 4(x20)
    sw      x21, 0(x20)
    sw      x0, 4(x20)

    # Verify CLINT compare write stuck
    lw      x5, 0(x20)
    bne     x5, x21, fail
    lw      x5, 4(x20)
    bne     x5, x0, fail

    # Enable machine timer interrupts
    addi    x5, x0, 0x80
    csrrs   x0, mie, x5

    # Enable global machine interrupts
    addi    x5, x0, 0x8
    csrrs   x0, mstatus, x5

main:
    # Realistic mixed workload using registers the handler does not clobber
    addi    x11, x0, 7
    addi    x12, x0, 3
    addi    x13, x0, 16
    addi    x14, x0, 0
    addi    x15, x0, 1
    addi    x16, x0, 0x55

    sw      x16, 0(x22)
    lw      x17, 0(x22)
    bne     x17, x16, fail

work_loop:
    add     x11, x11, x12
    xor     x14, x14, x11

    sw      x11, 4(x22)
    lw      x18, 4(x22)
    bne     x18, x11, fail

    andi    x19, x12, 1
    beq     x19, x0, even_path
odd_path:
    addi    x14, x14, 5
    jal     x0, loop_continue
even_path:
    addi    x14, x14, -3

loop_continue:
    slli    x18, x12, 1
    add     x14, x14, x18
    addi    x12, x12, 1
    blt     x12, x13, work_loop

    # Require at least one interrupt during realistic code
    beq     x27, x0, fail

    # Verify post-interrupt execution still works
    addi    x23, x0, 9
    xor     x23, x23, x14
    sw      x23, 8(x22)
    lw      x24, 8(x22)
    bne     x24, x23, fail

    # At least one interrupt must have been counted
    addi    x25, x0, 1
    blt     x28, x25, fail

    # MIE should be restored after mret
    csrrs   x25, mstatus, x0
    andi    x25, x25, 0x8
    addi    x26, x0, 0x8
    bne     x25, x26, fail

    # Final signature for this exact workload
    addi    x25, x0, 124
    bne     x11, x25, fail

    addi    x25, x0, 299
    bne     x14, x25, fail

pass:
    addi    x10, x0, 1
    slli    x10, x10, 8
    addi    x10, x10, 1
pass_hang:
    jal     x0, pass_hang

fail_trap:
    # Restore temporaries before reporting failure
    lw      x5, 12(x22)
    lw      x6, 16(x22)
    lw      x31, 20(x22)

fail:
    addi    x10, x0, 1
    slli    x10, x10, 8
    addi    x10, x10, 2
fail_hang:
    jal     x0, fail_hang
