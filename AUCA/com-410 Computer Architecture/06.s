.section .data
output_format:
	.string "%ld\n"

.section .text	

.global main
add1:
	#xor %rax, %rax
	mov %edi, %eax
	cltq
	ret
add2:
	#  200000000000000 + 20000000000000
	#  mov %edi. %eax
	#  add %, %eax
	#  cltq
	#  ret

	# long res = (long) 20000000000 + (long) 2000000000000
	
	mov %edi, %eax
	cltq
	mov %rax, %rdi

	mov %esi, %eax
	cltq

	add %rdi, %rax
	cltq
	ret 
add3:
	ret
add4:
	ret
add5:
	ret
add6:
	mov %edi, %eax
	cltq
	mov %rax, %rdi

	mov %esi, %eax
	cltq
	mov %rax, %rsi

	mov %edx, %eax
	cltq
	mov %rax, %rdx

	mov %ecx, %eax
	cltq
	mov %rax, %rcx

	mov %r8d, %eax
	cltq
	mov %rax, %r8

	mov %r9d, %eax
	cltq

	add %rdi, %rax
	add %rsi, %rax
	add %rdx, %rax
	add %rcx, %rax
	add %r8, %rax
	ret 
add7:

	mov %edi, %eax
	cltq
	mov %rax, %rdi

	mov %esi, %eax
	cltq
	mov %rax, %rsi

	mov %edx, %eax
	cltq
	mov %rax, %rdx

	mov %ecx, %eax
	cltq
	mov %rax, %rcx

	mov %r8d, %eax
	cltq
	mov %rax, %r8

	mov %r9d, %eax
	cltq
	mov %rax, %r9	

	add %rdi, %rax
	add %rsi, %rax
	add %rdx, %rax
	add %rcx, %rax
	add %r8, %rax
	add %r9, %rax
	
	pop %rdx		 #return address
	pop %rdi		 #7
	add %rdi, %rax
	push %rdx

	ret 			 #pop return address to rip
main:
	mov $1, %edi				# pass parameters	
	call add1
	lea output_format(%rip), %rdi
	mov %rax, %rsi
	xor %eax, %eax
	call printf@plt

	mov $1, %edi
	mov $2, %esi	
	call add2
	lea output_format(%rip), %rdi
	mov %rax, %rsi
	xor %eax, %eax
	call printf@plt

	mov $1, %edi
	mov $2, %esi
	mov $3, %edx
	mov $4, %ecx
	mov $5, %r8d
	mov $6, %r9d					
	call add6
	lea output_format(%rip), %rdi
	mov %rax, %rsi
	xor %eax, %eax
	call printf@plt

	mov $1, %edi
	mov $2, %esi
	mov $3, %edx
	mov $4, %ecx
	mov $5, %r8d
	mov $6, %r9d
	push $7					
	call add7 			#push $return_address
			#push %rip
			#jmp add7 	mov add7, %rip
	lea output_format(%rip), %rdi
	mov %rax, %rsi
	xor %eax, %eax
	call printf@plt

	xor %eax, %eax
	ret
