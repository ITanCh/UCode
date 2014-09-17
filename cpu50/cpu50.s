	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_2 Depth 2
	movl	$0, -8(%rbp)
LBB0_2:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$13300000, -8(%rbp)     ## imm = 0xCAF120
	jge	LBB0_5
## BB#3:                                ##   in Loop: Header=BB0_2 Depth=2
	jmp	LBB0_4
LBB0_4:                                 ##   in Loop: Header=BB0_2 Depth=2
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_2
LBB0_5:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	$10, %edi
	callq	_usleep
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	jmp	LBB0_1
	.cfi_endproc


.subsections_via_symbols
