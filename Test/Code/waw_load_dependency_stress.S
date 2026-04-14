.section .text
.globl _start

# Directed hazard stress test.
# Focus areas:
# - same-cycle WAW where slot 1 depends on slot 0's freshly produced Rd
# - same-cycle load-WAW where the younger writer must remain the visible owner
# - adjacent load-use that should serialize correctly
# - deep dependent chains that mix load-use and WAW behavior
#
# Expected final signature: 0x1122338f (287454095 decimal).
# The program writes 0x101 to x10 on pass or 0x102 on fail.

_start:
    addi x1,  x0, 512         # scratch memory base
    addi x2,  x0, 7
    addi x3,  x0, 5
    addi x20, x0, 0           # running signature

    lui  x21, 0x11223
    addi x21, x21, 836        # x21 = 0x11223344
    sw   x21, 0(x1)

    lui  x21, 0x55667
    addi x21, x21, 1928       # x21 = 0x55667788
    sw   x21, 4(x1)

    addi x21, x0, 0
    sw   x21, 8(x1)
    sw   x21, 12(x1)
    sw   x21, 16(x1)

    # Same-cycle WAW with slot 1 depending on slot 0.
    # add x4, x3, x2   => 12
    # add x4, x4, x3   => 17
    add  x4,  x3,  x2
    add  x4,  x4,  x3
    addi x21, x0, 17
    bne  x4,  x21, fail
    add  x20, x20, x4

    # Another same-cycle WAW dependency chain on a different register.
    # sub x5, x4, x2   => 10
    # addi x5, x5, 9   => 19
    sub  x5,  x4,  x2
    addi x5,  x5,  9
    addi x21, x0, 19
    bne  x5,  x21, fail

    add  x6,  x5,  x4         # 19 + 17 = 36
    addi x21, x0, 36
    bne  x6,  x21, fail

    xor  x20, x20, x5
    add  x20, x20, x6

    # Adjacent load-use on the same Rd. Slot 1 should not issue alongside the load.
    lw   x7,  0(x1)
    add  x7,  x7,  x2         # 0x11223344 + 7 = 0x1122334b
    lui  x21, 0x11223
    addi x21, x21, 843        # x21 = 0x1122334b
    bne  x7,  x21, fail
    xor  x20, x20, x7

    # Same-cycle load-WAW. The younger ALU writer must remain the visible owner.
    lw   x8,  4(x1)
    addi x8,  x3,  9          # 14, should stay visible after the older load completes

    # Burn a few cycles and inject more memory traffic so the load has time to return.
    addi x13, x0, 1
    slli x13, x13, 4
    xor  x13, x13, x4
    add  x13, x13, x6
    sw   x13, 16(x1)
    lw   x14, 16(x1)
    add  x14, x14, x3
    xor  x13, x13, x14

    addi x21, x0, 14
    bne  x8,  x21, fail
    add  x20, x20, x8

    # Deep dependent ALU chain with another same-Rd rewrite sequence inside it.
    add  x9,  x2,  x3         # 12
    add  x9,  x9,  x4         # 29
    xor  x9,  x9,  x6         # 57
    addi x9,  x9,  -10        # 47
    slli x9,  x9,  1          # 94
    srli x10, x9,  2          # 23
    add  x9,  x9,  x10        # 117
    addi x21, x0, 117
    bne  x9,  x21, fail
    xor  x20, x20, x9

    # Store/load followed by a same-cycle WAW dependency pair.
    # The load-use should serialize first, then the two adds can form the WAW pair.
    sw   x9,  12(x1)
    lw   x12, 12(x1)
    add  x12, x12, x2         # 124
    add  x12, x12, x3         # 129
    addi x21, x0, 129
    bne  x12, x21, fail
    add  x20, x20, x12

    lui  x21, 0x11223
    addi x21, x21, 911        # x21 = 0x1122338f
    bne  x20, x21, fail

pass:
    addi x10, x0, 1
    slli x10, x10, 8
    addi x10, x10, 1
    jal  x0,  done

fail:
    addi x10, x0, 1
    slli x10, x10, 8
    addi x10, x10, 2

done:
    jal  x0,  done
