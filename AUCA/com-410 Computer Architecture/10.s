.section .data
input:
	.string "%ld"
output:
	.string "%ld\n"

.section .text

rec_fact:
	cmp $0x1, %rdi
	jle .rec_fact_ret1

	dec %rdi
	call rec_fact
	inc %rdi
	imul %rdi, %rax
	ret 

.rec_fact_ret1:
	mov $0x1, %rax
	ret

.global main
main:
	sub $0x8, %rsp

	lea input(%rip), %rdi
	mov %rsp, %rsi
	xor %eax, %eax
	call scanf@plt
	
	mov $0x1, %rsi
	mov (%rsp), %rdi
	call rec_fact
	mov %rax, %rsi
	lea output(%rip), %rdi
	xor %eax, %eax
	call printf@plt
	
	add $0x8, %rsp

	xor %eax, %eax
	ret
