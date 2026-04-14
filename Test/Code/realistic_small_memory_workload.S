_start:
    addi x1,  x0, 256         # base of array A
    addi x2,  x0, 32          # element count
    addi x3,  x0, 96          # outer loop count

    lui  x20, 0x2468b
    addi x20, x20, -799       # x20 = 0x2468ace1, running signature
    add  x21, x20, x0         # preserve seed for init

    addi x22, x0, 49          # constant increment for array B

    # Build three tiny arrays.
    # A[i] = seed ^ (i * 9)
    # B[i] = A[i] + 49
    # C[i] = i & 7
    add  x4,  x1,  x0         # ptr A
    addi x5,  x1,  128        # ptr B
    addi x6,  x1,  256        # ptr C
    addi x7,  x0,  0          # i

init_loop:
    slli x8,  x7,  3
    add  x8,  x8,  x7         # i * 9
    xor  x9,  x8,  x21
    sw   x9,  0(x4)

    add  x10, x9,  x22
    sw   x10, 0(x5)

    andi x11, x7,  7
    sw   x11, 0(x6)

    addi x4,  x4,  4
    addi x5,  x5,  4
    addi x6,  x6,  4
    addi x7,  x7,  1
    blt  x7,  x2,  init_loop

    addi x23, x0,  0          # outer index

outer_loop:
    add  x4,  x1,  x0         # ptr A
    addi x5,  x1,  128        # ptr B
    addi x6,  x1,  256        # ptr C
    addi x7,  x0,  0          # i

inner_loop:
    lw   x8,  0(x4)           # a
    lw   x9,  0(x5)           # b
    lw   x10, 0(x6)           # c

    add  x11, x8,  x9         # t = a + b
    andi x12, x10, 1
    bne  x12, x0,  odd_state

even_state:
    add  x11, x11, x23
    jal  x0,  state_done

odd_state:
    xor  x11, x11, x20

state_done:
    bltu x11, x9,  less_path
    addi x12, x7,  3
    add  x11, x11, x12
    jal  x0,  merge_path

less_path:
    xor  x11, x11, x7

merge_path:
    xor  x13, x11, x10        # newA
    add  x14, x9,  x10        # newB
    add  x15, x10, x23
    add  x15, x15, x7
    andi x15, x15, 7          # newC

    sw   x13, 0(x4)
    sw   x14, 0(x5)
    sw   x15, 0(x6)

    add  x20, x20, x13
    xor  x20, x20, x14
    add  x20, x20, x15

    addi x4,  x4,  4
    addi x5,  x5,  4
    addi x6,  x6,  4
    addi x7,  x7,  1
    blt  x7,  x2,  inner_loop

    addi x23, x23, 1
    blt  x23, x3,  outer_loop

    # Final reduction over the same small arrays.
    add  x4,  x1,  x0
    addi x5,  x1,  128
    addi x6,  x1,  256
    addi x7,  x0,  0

reduce_loop:
    lw   x8,  0(x4)
    lw   x9,  0(x5)
    lw   x10, 0(x6)

    add  x20, x20, x8
    xor  x20, x20, x9
    add  x20, x20, x10

    addi x4,  x4,  4
    addi x5,  x5,  4
    addi x6,  x6,  4
    addi x7,  x7,  1
    blt  x7,  x2,  reduce_loop

    lui  x24, 0x57d63
    addi x24, x24, -874       # x24 = 0x57d62c96
    bne  x20, x24, fail

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
