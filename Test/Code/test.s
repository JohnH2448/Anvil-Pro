	.file	"Program1.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.type	main, @function
main:
	li	a7,0
	li	t6,15
	li	a3,13
	li	t5,11
	li	a6,9
	li	a0,7
	li	a1,5
	li	a5,3
	li	a4,1
	li	t4,39
	li	t0,89
	li	t3,60
	li	t1,73
.L10:
	xor	a2,a4,a1
	andi	a2,a2,1
	beq	a2,zero,.L2
	add	a5,a4,a5
	add	a5,a0,a5
	xor	a6,a6,a5
.L3:
	bgtu	a5,t4,.L4
	add	t5,t5,a5
.L5:
	andi	a2,t5,1
	beq	a2,zero,.L7
	add	a3,a3,a7
	add	a3,t5,a3
.L8:
	sub	a2,a3,a6
	add	t6,t6,a2
	addi	a2,a0,5
	addi	a4,a4,3
	xor	a1,a1,t6
	addi	a0,a0,-36
	bgtu	a2,t3,.L9
	mv	a0,a2
.L9:
	addi	a7,a7,1
	bne	a4,t1,.L10
	li	a4,-67
	beq	a5,a4,.L17
.L11:
 #APP
# 55 "Test/Code/Program1.c" 1
	addi x10, x0, 258
# 0 "" 2
 #NO_APP
.L15:
	j	.L15
.L7:
	add	a2,a7,t5
	xor	a3,a3,a2
	j	.L8
.L4:
	bgtu	a5,t0,.L6
	slli	a2,a5,1
	xor	t5,t5,a2
	j	.L5
.L2:
	add	a5,a5,a1
	sub	a5,a5,a0
	addi	a6,a6,7
	j	.L3
.L6:
	srli	a2,a5,1
	sub	t5,t5,a2
	j	.L5
.L17:
	li	a5,-319
	bne	a1,a5,.L11
	li	a5,48
	bne	a0,a5,.L11
	li	a5,-19
	bne	a6,a5,.L11
	li	a5,-247
	bne	t5,a5,.L11
	li	a5,-975
	bne	a3,a5,.L11
	li	a5,-4096
	addi	a5,a5,-216
	bne	t6,a5,.L11
 #APP
# 53 "Test/Code/Program1.c" 1
	addi x10, x0, 101
# 0 "" 2
 #NO_APP
	j	.L15
	.size	main, .-main
	.ident	"GCC: () 13.2.0"
