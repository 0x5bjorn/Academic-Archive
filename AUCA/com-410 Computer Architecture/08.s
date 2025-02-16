.section .data
input:
	.string "%d"
output:
	.string "%d\n"

.section .text

rec_fib:
	dec %rdi
	test %rdi, %rdi
	jle .rec_fib_ret_a
	mov %rsi, %rcx
	mov %rdx, %rsi
	add %rcx, %rdx
	call rec_fib
	jmp .rec_fib_end

.rec_fib_ret_a:
	mov %rsi, %rax
.rec_fib_end:
	ret

loop_fib:
	dec %rdi
	test %rdi, %rdi
	jle .rec_fib_ret_a
	mov %rsi, %rcx
	mov %rdx, %rsi
	add %rcx, %rdx
	jmp loop_fib

.loop_fib_ret_a:
	mov %rsi, %rax
	ret

.global main
main:
	sub $0x8, %rsp

	lea input(%rip), %rdi
	mov %rsp, %rsi
	xor %eax, %eax
	call scanf@plt

	mov (%rsp), %rdi
	xor %rsi, %rsi
	mov $0x1, %rdx
	call rec_fib
	mov %rax, %rsi
	lea output(%rip), %rdi
	xor %eax, %eax
	call printf@plt

	mov (%rsp), %rdi
	xor %rsi, %rsi
	mov $0x1, %rdx
	call loop_fib
	mov %rax, %rsi
	lea output(%rip), %rdi
	xor %eax, %eax
	call printf@plt
	
	add $0x8, %rsp
	
	xor %eax, %eax
	ret
