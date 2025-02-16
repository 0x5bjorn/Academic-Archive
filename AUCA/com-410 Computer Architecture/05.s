.section .data
input_format:
	.string "%d %d"
output_format:
	.string "sum: %d\n"
numberA:
	.int 0
numberB:
	.int 0
result:
	.int 0

.section .text
.global main
main:
	lea input_format(%rip), %rdi
	lea numberA(%rip), %rsi
	lea numberB(%rip), %rdx
	xor %eax, %eax
	call scanf@plt
	
	mov numberA(%rip), %rdi
	mov numberB(%rip), %rsi
	add %rdi, %rsi
	mov %rsi, result(%rip)
		
	lea output_format(%rip), %rdi
	mov result(%rip), %rsi
	xor %eax, %eax
	call printf@plt
	
	xor %eax, %eax
	ret
