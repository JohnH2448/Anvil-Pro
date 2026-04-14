_start:
    addi x1,  x0, 512         # base address for bank 0
    addi x2,  x0, 128         # entries per bank
    addi x3,  x0, 24          # outer iterations
    addi x14, x0, 256         # inner iterations

    lui  x20, 0x1357a
    addi x20, x20, -1057      # x20 = 0x13579bdf, running signature seed
    add  x22, x20, x0         # keep a copy of the seed for init

    addi x23, x0, 1
    slli x23, x23, 12
    addi x23, x23, 33         # x23 = 0x1021

    addi x4,  x0, 0

init_loop:
    slli x5,  x4,  2
    add  x6,  x1,  x5

    slli x7,  x4,  3          # x4 * 8
    slli x8,  x4,  2          # x4 * 4
    add  x7,  x7,  x8         # x4 * 12
    add  x7,  x7,  x4         # x4 * 13

    xor  x8,  x7,  x22
    sw   x8,  0(x6)
    add  x9,  x8,  x23
    sw   x9,  512(x6)

    addi x4,  x4,  1
    blt  x4,  x2,  init_loop

    addi x4,  x0,  0

outer_loop:
    addi x5,  x0,  0

inner_loop:
    andi x6,  x5,  127
    slli x7,  x6,  2
    add  x8,  x1,  x7

    lw   x9,  0(x8)
    lw   x10, 512(x8)

    add  x20, x20, x9
    xor  x20, x20, x10

    add  x11, x9,  x4
    xor  x11, x11, x5
    sw   x11, 0(x8)

    andi x12, x5,  7
    bne  x12, x0,  inner_else

    add  x13, x10, x20
    sw   x13, 512(x8)
    xor  x20, x20, x13
    jal  x0,  inner_cont

inner_else:
    sub  x13, x10, x4
    sw   x13, 512(x8)
    add  x20, x20, x13

inner_cont:
    addi x5,  x5,  1
    blt  x5,  x14, inner_loop

    addi x4,  x4,  1
    blt  x4,  x3,  outer_loop

    addi x4,  x0,  0

reduce_loop:
    slli x5,  x4,  2
    add  x6,  x1,  x5

    lw   x7,  0(x6)
    lw   x8,  512(x6)
    add  x20, x20, x7
    xor  x20, x20, x8

    addi x4,  x4,  1
    blt  x4,  x2,  reduce_loop

    lui  x21, 0x2d40b
    addi x21, x21, -1927      # x21 = 0x2d40a879
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
