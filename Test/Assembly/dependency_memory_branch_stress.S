.section .text
.globl _start

# Dependency-heavy mixed stress test.
# The core idea is that x4 is kept on a very tight dependency chain for most
# of the program, while branches and memory operations are interleaved close
# to those chains. Expected final signature: 0x270c85c8 (655132104 decimal).
# The program then writes 0x101 to x10 on pass or 0x102 on fail.

_start:
    addi x1,  x0, 512         # memory base
    addi x2,  x0, 24          # trip count
    lui  x4,  0x2468a
    addi x4,  x4,  291        # main accumulator / dependency register
    lui  x7,  0x13579
    addi x7,  x7,  -1217      # mixer
    addi x8,  x0,  0x5d
    addi x9,  x0,  0          # loop index
    addi x18, x0,  7
    addi x19, x0,  11

fill_loop:
    slli x5,  x9,  2
    add  x6,  x1,  x5

    add  x4,  x4,  x7
    xor  x4,  x4,  x8
    add  x4,  x4,  x9
    slli x11, x4,  1
    srli x12, x4,  3
    xor  x4,  x11, x12

    sw   x4,  0(x6)
    lb   x13, 0(x6)
    add  x4,  x4,  x13
    lbu  x14, 1(x6)
    xor  x4,  x4,  x14

    sh   x4,  2(x6)
    lh   x15, 2(x6)
    add  x4,  x4,  x15
    lhu  x16, 2(x6)
    xor  x4,  x4,  x16

    andi x17, x4,  1
    bne  x17, x0,  odd_path_0
    add  x4,  x4,  x18
    sb   x4,  1(x6)
    lbu  x17, 1(x6)
    xor  x4,  x4,  x17
    jal  x0,  merge_path_0

odd_path_0:
    sub  x4,  x4,  x19
    sb   x4,  3(x6)
    lb   x17, 3(x6)
    add  x4,  x4,  x17

merge_path_0:
    lw   x20, 0(x6)
    xor  x4,  x4,  x20

    addi x9,  x9,  1
    blt  x9,  x2,  fill_loop

    addi x9,  x0,  0

mix_loop:
    slli x5,  x9,  2
    add  x6,  x1,  x5

    lw   x11, 0(x6)
    add  x4,  x4,  x11
    xor  x4,  x4,  x7
    add  x4,  x4,  x8
    sub  x4,  x4,  x9

    sw   x4,  128(x6)
    lw   x12, 128(x6)
    xor  x4,  x4,  x12
    sh   x4,  130(x6)
    lh   x13, 130(x6)
    add  x4,  x4,  x13

    andi x14, x12, 3
    beq  x14, x0,  branch_eq_1
    addi x15, x0,  2
    blt  x14, x15, branch_lt_1
    bge  x14, x15, branch_ge_1

branch_eq_1:
    add  x4,  x4,  x18
    sb   x4,  129(x6)
    lbu  x16, 129(x6)
    xor  x4,  x4,  x16
    jal  x0,  merge_1

branch_lt_1:
    xor  x4,  x4,  x19
    sb   x4,  131(x6)
    lb   x16, 131(x6)
    add  x4,  x4,  x16
    jal  x0,  merge_1

branch_ge_1:
    sub  x4,  x4,  x18
    sw   x4,  256(x6)
    lw   x16, 256(x6)
    xor  x4,  x4,  x16

merge_1:
    addi x9,  x9,  1
    bltu x9,  x2,  mix_loop

    addi x9,  x2,  -1

reverse_loop:
    slli x5,  x9,  2
    add  x6,  x1,  x5

    lw   x11, 0(x6)
    lw   x12, 128(x6)
    lw   x13, 256(x6)

    add  x4,  x4,  x11
    xor  x4,  x4,  x12
    add  x4,  x4,  x13
    slli x4,  x4,  1
    srli x14, x4,  7
    xor  x4,  x4,  x14

    sb   x4,  385(x6)
    lbu  x15, 385(x6)
    add  x4,  x4,  x15
    sh   x4,  386(x6)
    lhu  x16, 386(x6)
    xor  x4,  x4,  x16

    blt  x11, x12, less_2
    bgeu x13, x12, geu_2
    add  x4,  x4,  x7
    jal  x0,  merge_2

less_2:
    sub  x4,  x4,  x8
    lw   x17, 384(x6)
    xor  x4,  x4,  x17
    jal  x0,  merge_2

geu_2:
    add  x4,  x4,  x19
    lb   x17, 387(x6)
    add  x4,  x4,  x17

merge_2:
    addi x9,  x9,  -1
    bge  x9,  x0,  reverse_loop

    addi x9,  x0,  0

reduce_loop:
    slli x5,  x9,  2
    add  x6,  x1,  x5

    lw   x11, 0(x6)
    lw   x12, 128(x6)
    lw   x13, 256(x6)
    lw   x14, 384(x6)

    add  x4,  x4,  x11
    xor  x4,  x4,  x12
    add  x4,  x4,  x13
    xor  x4,  x4,  x14
    add  x4,  x4,  x7
    xor  x4,  x4,  x8
    add  x4,  x4,  x18
    sub  x4,  x4,  x19

    andi x15, x4,  0xf
    bne  x15, x0,  branch_nz_3
    add  x4,  x4,  x9
    jal  x0,  merge_3

branch_nz_3:
    xor  x4,  x4,  x9
    sw   x4,  512(x6)
    lw   x16, 512(x6)
    add  x4,  x4,  x16

merge_3:
    addi x9,  x9,  1
    blt  x9,  x2,  reduce_loop

    add  x10, x4,  x0

    lui  x11, 0x270c8
    addi x11, x11, 1480       # x11 = 0x270c85c8
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
