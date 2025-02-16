.section .data
input_format:
	.string "%d"
increment:
	.string "after increment: %d\n"
decrement:
	.string "after decrement: %d\n"
number:
	.int 0

.section .text
.global main
main:
	lea input_format(%rip), %rdi
	lea number(%rip), %rsi
	xor %eax, %eax
	call scanf@plt
	
	lea increment(%rip), %rdi
	mov number(%rip), %rsi
	inc %rsi
	xor %eax, %eax
	call printf@plt
	
	lea decrement(%rip), %rdi
	mov number(%rip), %rsi
	dec %rsi
	xor %eax, %eax
	call printf@plt
	
	
	/*
	mov number(%rip), %rsi
	inc %rsi
	mov %rsi, number(%rip)

	lea increment(%rip), %rdi
	mov number(%rip), %rsi
	xor %eax, %eax
	call printf@plt
	
	mov number(%rip), %rsi
	dec %rsi
	dec %rsi
	mov %rsi, number(%rip)
	
	lea decrement(%rip), %rdi
	mov number(%rip), %rsi
	xor %eax, %eax
	call printf@plt
	*/
