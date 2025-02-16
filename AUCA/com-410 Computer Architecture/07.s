.section .data
input_format:
	.string "%d %d"
output_format:
	.string "%d\n"
puts_message:
	.string "equal"
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
	
	mov a(%rip), %esi
	mov b(%rip), %ecx
	cmp %ecx, %esi 		# sub: a and b 
	jg a_is_greater		# a>b
	jl b_is_greater		# b>a
	
	lea puts_message(%rip), %rdi
	call puts@plt
	
end:	
	xor %eax, %eax
	ret

a_is_greater:
	lea output_format(%rip), %rdi
	xor %eax, %eax
	call printf@plt
	jmp end

b_is_greater:	
	lea output_format(%rip), %rdi
	mov %ecx, %esi
	xor %eax, %eax
	call printf@plt
	jmp end
