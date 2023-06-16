	.syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.syntax unified
	.file	"main.c"
	.text
	.align	2
	.global	main
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	ldr	r2, .L5
	ldr	r3, .L5
	ldr	r3, [r3]
	orr	r3, r3, #1
	str	r3, [r2]
	ldr	r2, .L5
	ldr	r3, .L5
	ldr	r3, [r3]
	orr	r3, r3, #4
	str	r3, [r2]
	ldr	r2, .L5+4
	ldr	r3, .L5+4
	ldr	r3, [r3]
	orr	r3, r3, #1024
	str	r3, [r2]
	ldr	r2, .L5+4
	ldr	r3, .L5+4
	ldr	r3, [r3]
	bic	r3, r3, #2048
	str	r3, [r2]
	ldr	r2, .L5+8
	ldr	r3, .L5+8
	ldr	r3, [r3]
	orr	r3, r3, #67108864
	str	r3, [r2]
	ldr	r2, .L5+8
	ldr	r3, .L5+8
	ldr	r3, [r3]
	bic	r3, r3, #134217728
	str	r3, [r2]
.L4:
	ldr	r2, .L5+12
	ldr	r3, .L5+12
	ldr	r3, [r3]
	eor	r3, r3, #8192
	str	r3, [r2]
	movs	r3, #0
	str	r3, [r7, #4]
	b	.L2
.L3:
	ldr	r3, [r7, #4]
	adds	r3, r3, #1
	str	r3, [r7, #4]
.L2:
	ldr	r3, [r7, #4]
	ldr	r2, .L5+16
	cmp	r3, r2
	ble	.L3
	b	.L4
.L6:
	.align	2
.L5:
	.word	1073887280
	.word	1073872896
	.word	1073874944
	.word	1073874964
	.word	899999
	.size	main, .-main
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 5.4.1 20160919 (release) [ARM/embedded-5-branch revision 240496]"
