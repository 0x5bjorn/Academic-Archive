.section .data
input_format:
	.string "%d %d"
output_format:
	.string "%d + %d = %d\n"
a:
	.int 0
b:
	.int 0

.section .text
.global main
main:
	lea input_format(%rip), %rdi
	lea a(%rip), %rsi
	lea b(%rip), %rdx
	xor %eax, %eax
	call scanf@plt
	
	lea output_format(%rip), %rdi
	mov a(%rip), %rsi
	mov b(%rip), %rdx
	mov %rsi, %rcx
	add %rdx, %rcx
	xor %eax, %eax			 #vararg function
	call printf@plt
	
	xor %eax, %eax
	ret
