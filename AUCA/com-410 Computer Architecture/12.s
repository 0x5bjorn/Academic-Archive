.section .data

input_format:
	.string "%ld %ld"
output_format:
	.string "%ld\n"
days_table:
	.quad 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31

.section .text

get_day_in_month_if:
    cmpq $0x1, %rsi
    je .get_day_in_month_if_first
    cmpq $0x3, %rsi
    je .get_day_in_month_if_first
    cmpq $0x5, %rsi
    je .get_day_in_month_if_first
    cmpq $0x7, %rsi
    je .get_day_in_month_if_first
    cmpq $0x8, %rsi
    je .get_day_in_month_if_first
    cmpq $0xA, %rsi
    je .get_day_in_month_if_first
    cmpq $0xC, %rsi
    je .get_day_in_month_if_first
    
    cmpq $0x4, %rsi
    je .get_day_in_month_if_second
    cmpq $0x6, %rsi
    je .get_day_in_month_if_second
    cmpq $0x9, %rsi
    je .get_day_in_month_if_second
    cmpq $0xB, %rsi
    je .get_day_in_month_if_second

    cmpq $0x2, %rsi
    jne .get_day_in_month_if_wrong
    
    movq %rdi, %rax
    test $0x3, %eax
    jnz .get_day_in_month_if_thirdB
    
    cqo
    mov $0x64, %rcx
    div %rcx
    test %rdx, %rdx
    jnz .get_day_in_month_if_thirdA
     
    test $0x3, %rdx
    jnz .get_day_in_month_if_thirdB
    jz .get_day_in_month_if_thirdA
    
.get_day_in_month_if_first: #31 days
    movq $0x1F, %rax
    jmp .get_day_in_month_if_end
    
.get_day_in_month_if_second: #30 days
    movq $0x1E, %rax

.get_day_in_month_if_first: #31 days
    movq $0x1F, %rax
    jmp .get_day_in_month_if_end
    
.get_day_in_month_if_second: #30 days
    movq $0x1E, %rax
    jmp .get_day_in_month_if_end
    
.get_day_in_month_if_thirdA: #29 days
    movq $0x1D, %rax
    jmp .get_day_in_month_if_end
    
.get_day_in_month_if_thirdB: #28 days
    movq $0x1C, %rax
    jmp .get_day_in_month_if_end
    
.get_day_in_month_if_wrong: #wrong input
    movq $0xffffffffffffffff, %rax
    
.get_day_in_month_if_end:
    ret

day_in_month:
	mov $-1, %rcx

	cmp $1, %rsi
	jl .end
	cmp $12, %rsi
	jg .end

	lea days_table(%rip), %rdx
	mov -0x8(%rdx, %rsi, 0x8), %rcx

	cmp $2, %rsi
	jne .end

	mov %rdi, %rax
	cqo
	mov $4, %r8
	div %r8
	test %rdx, %rdx
	jne .by_400

	mov %rdi, %rax
	cqo
	mov $100, %r8
	div %r8
	test %rdx, %rdx
	je .by_400

	jmp .leap

.divisable_by_400:
	mov %rdi, %rax
	cqo
	mov $400, %r8
	div %r8
	test %rdx, %rdx
	jne .end

.leap:
	mov $29, %rcx

.end:
	mov %rcx, %rax
	ret

.global main
main:
	sub $0x10, %rsp 

	lea input_format(%rip), %rdi
	lea 0x8(%rsp), %rsi
	lea (%rsp), %rdx
	xor %eax, %eax
	call scanf@plt

	mov 0x8(%rsp), %rdi
	mov (%rsp), %rsi
	call get_day_in_month_if
	mov %rax, %rsi
	lea output_format(%rip), %rdi
	xor %eax, %eax
	call printf@plt

	mov 0x8(%rsp), %rdi
	mov (%rsp), %rsi
	call day_in_month
	mov %rax, %rsi
	lea output_format(%rip), %rdi
	xor %eax, %eax
	call printf@plt

	add $0x10, %rsp

	xor %eax, %eax
	ret
