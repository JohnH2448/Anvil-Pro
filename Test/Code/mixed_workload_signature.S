_start:
    addi x1,  x0, 256         # input base
    addi x2,  x0, 384         # output base
    addi x3,  x0, 640         # flag byte base
    addi x4,  x0, 32          # element count

    lui  x20, 0x123
    addi x20, x20, 1110       # seed = 0x00123456
    lui  x21, 0x13
    addi x21, x21, 1401       # mix = 0x00013579
    lui  x22, 0x1
    addi x22, x22, -1451      # mix2 = 0x00000a55

    addi x23, x0, 0           # loop index

init_loop:
    slli x5,  x23, 2
    add  x6,  x1,  x5
    add  x7,  x3,  x23

    slli x8,  x23, 4
    slli x9,  x23, 1
    add  x10, x20, x8
    add  x10, x10, x9
    xor  x10, x10, x21
    add  x10, x10, x23

    sw   x10, 0(x6)
    andi x11, x10, 3
    sb   x11, 0(x7)

    addi x23, x23, 1
    blt  x23, x4,  init_loop

    lui  x24, 0x2468b
    addi x24, x24, -799       # checksum = 0x2468ace1
    addi x25, x0, 0           # prev input value
    addi x23, x0, 0           # loop index

transform_loop:
    slli x5,  x23, 2
    add  x6,  x1,  x5
    add  x7,  x2,  x5
    add  x8,  x3,  x23

    lw   x9,  0(x6)           # current input
    lbu  x10, 0(x8)           # metadata / flag

    add  x11, x9,  x25
    xor  x11, x11, x24

    beq  x10, x0,  flag_zero
    addi x12, x0, 2
    bltu x10, x12, flag_one
    xor  x11, x11, x22
    jal  x0,  flag_merge

flag_zero:
    addi x11, x11, 11
    jal  x0,  flag_merge

flag_one:
    addi x11, x11, -7

flag_merge:
    blt  x11, x0,  neg_path
    sub  x11, x11, x25
    jal  x0,  sign_merge

neg_path:
    add  x11, x11, x9

sign_merge:
    sw   x11, 0(x7)

    add  x24, x24, x11
    srli x12, x24, 5
    xor  x24, x24, x12

    add  x25, x0,  x9
    addi x23, x23, 1
    blt  x23, x4,  transform_loop

    addi x23, x0, 0

reduce_loop:
    slli x5,  x23, 2
    add  x6,  x1,  x5
    add  x7,  x2,  x5
    add  x8,  x3,  x23

    lw   x9,  0(x6)
    lw   x10, 0(x7)
    lbu  x11, 0(x8)

    add  x24, x24, x10
    xor  x24, x24, x9

    andi x12, x11, 1
    beq  x12, x0,  even_flag
    add  x24, x24, x11
    jal  x0,  reduce_merge

even_flag:
    xor  x24, x24, x11

reduce_merge:
    slli x13, x24, 3
    srli x14, x24, 7
    xor  x24, x13, x14

    addi x23, x23, 1
    blt  x23, x4,  reduce_loop

    add  x10, x24, x0

    lui  x11, 0x9a5df
    addi x11, x11, 391        # x11 = 0x9a5df187
    bne  x10, x11, fail

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
