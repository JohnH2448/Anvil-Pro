_start:
    addi x1,  x0, 17
    addi x2,  x0, 34
    addi x3,  x0, 51
    addi x4,  x0, 68
    addi x5,  x0, 85
    addi x6,  x0, 102
    addi x7,  x0, 119
    addi x8,  x0, 136
    addi x9,  x0, 153
    addi x11, x0, 187
    addi x12, x0, 204
    addi x13, x0, 221
    addi x14, x0, 238
    addi x15, x0, 255
    addi x16, x0, 272
    addi x17, x0, 289
    addi x18, x0, 306

    .rept 6
        addi x1,  x1,  3
        xori x2,  x2,  0x055
        addi x3,  x3,  -7
        ori  x4,  x4,  0x012
        xori x5,  x5,  0x01f
        addi x6,  x6,  9
        slli x7,  x7,  1
        srli x8,  x8,  1
        addi x9,  x9,  11
        xori x11, x11, 0x033
        addi x12, x12, -13
        ori  x13, x13, 0x044
        xori x14, x14, 0x077
        addi x15, x15, 5
        slli x16, x16, 1
        srli x17, x17, 1
        addi x18, x18, 7

        xori x1,  x1,  0x0a5
        addi x2,  x2,  6
        ori  x3,  x3,  0x021
        xori x4,  x4,  0x066
        addi x5,  x5,  -9
        slli x6,  x6,  1
        srli x7,  x7,  1
        addi x8,  x8,  13
        xori x9,  x9,  0x05a
        addi x11, x11, 8
        ori  x12, x12, 0x018
        xori x13, x13, 0x02c
        addi x14, x14, -11
        slli x15, x15, 1
        srli x16, x16, 1
        addi x17, x17, 15
        xori x18, x18, 0x041

        addi x1,  x1,  12
        ori  x2,  x2,  0x009
        xori x3,  x3,  0x07e
        addi x4,  x4,  -5
        slli x5,  x5,  1
        srli x6,  x6,  1
        addi x7,  x7,  4
        xori x8,  x8,  0x031
        ori  x9,  x9,  0x024
        addi x11, x11, -3
        slli x12, x12, 1
        srli x13, x13, 1
        addi x14, x14, 10
        xori x15, x15, 0x06b
        ori  x16, x16, 0x052
        addi x17, x17, -7
        slli x18, x18, 1

        xori x1,  x1,  0x011
        addi x2,  x2,  14
        srli x3,  x3,  1
        slli x4,  x4,  1
        addi x5,  x5,  2
        xori x6,  x6,  0x022
        ori  x7,  x7,  0x081
        addi x8,  x8,  -4
        slli x9,  x9,  1
        srli x11, x11, 1
        addi x12, x12, 16
        xori x13, x13, 0x01d
        ori  x14, x14, 0x0a0
        addi x15, x15, -6
        slli x16, x16, 1
        srli x17, x17, 1
        addi x18, x18, 18
    .endr

    xor  x1,  x1,  x9
    add  x2,  x2,  x11
    xor  x3,  x3,  x12
    add  x4,  x4,  x13
    xor  x5,  x5,  x14
    add  x6,  x6,  x15
    xor  x7,  x7,  x16
    add  x8,  x8,  x17

    xor  x18, x18, x1
    add  x2,  x2,  x3
    xor  x4,  x4,  x5
    add  x6,  x6,  x7
    xor  x8,  x8,  x18
    add  x2,  x2,  x4
    xor  x6,  x6,  x8
    add  x20, x2,  x6

    lui  x21, 0x0000e
    addi x21, x21, -1483      # x21 = 0x0000da35
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
