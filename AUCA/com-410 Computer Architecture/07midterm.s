.section .data
input:
	.string "%ld %ld"
output:
	.string "%ld is greater\n"
equal:
	.string "Equal"
numbA:
	.int 0
numbB:
	.int 0

.section .text

.global main
main:
	lea input(%rip), %rdi
	lea numbA(%rip), %rsi
	lea numbB(%rip), %rdx
	xor %eax, %eax
	call scanf@plt

	mov numbA, %rsi
	mov numbB, %rdx
	cmp %rdx, %rsi
	jg a_greater
	jl b_greater
	
	lea equal(%rip), %rdi
	xor %eax, %eax
	call puts@plt
end:
	xor %eax, %eax
	ret
	
a_greater:
	lea output(%rip), %rdi
	xor %eax, %eax
	call printf@plt
	jmp end

b_greater:
	lea output(%rip), %rdi
	mov %rdx, %rsi
	xor %eax, %eax
	call printf@plt
	jmp end
