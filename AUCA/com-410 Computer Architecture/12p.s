.section .data

input_format: .string "%lu %lu"

output_format: .string "%lu\n"

days_lookup_table:
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
    
get_day_in_month_case:

#default cases
    cmpq $0xC, %rsi 
    ja .get_day_in_month_case_wrong
    cmpq $0x1, %rsi
    jb .get_day_in_month_case_wrong

.section .data
#switch    
switch_table:

.quad   .get_day_in_month_case_wrong
.quad   .get_day_in_month_case_first   
.quad   .get_day_in_month_case_third
.quad   .get_day_in_month_case_first
.quad   .get_day_in_month_case_second
.quad   .get_day_in_month_case_first
.quad   .get_day_in_month_case_second
.quad   .get_day_in_month_case_first
.quad   .get_day_in_month_case_first
.quad   .get_day_in_month_case_second
.quad   .get_day_in_month_case_first
.quad   .get_day_in_month_case_second  
.quad   .get_day_in_month_case_first

.section .text
    
    xor %rcx, %rcx
    lea switch_table(%rip), %rcx
    jmpq *(%rcx, %rsi, 8)
   
    
.get_day_in_month_case_first: #31 days
    movq $0x1F, %rax
    jmp .get_day_in_month_case_end
    
.get_day_in_month_case_second: #30 days
    movq $0x1E, %rax
    jmp .get_day_in_month_case_end
    
.get_day_in_month_case_third: #29 days
    movq %rdi, %rax
    test $0x3, %eax
    jnz .get_day_in_month_case_thirdB
    
    cqo
    mov $0x64, %rcx
    div %rcx
    test %rdx, %rdx
    jnz .get_day_in_month_case_thirdA
     
    test $0x3, %rdx
    jnz .get_day_in_month_case_thirdB
    jz .get_day_in_month_case_thirdA

.get_day_in_month_case_thirdA:    
    movq $0x1D, %rax
    jmp .get_day_in_month_case_end
    
.get_day_in_month_case_thirdB: #28 days
    movq $0x1C, %rax
    jmp .get_day_in_month_case_end    

.get_day_in_month_case_wrong: #wrong input
    movq $0xffffffffffffffff, %rax
          
.get_day_in_month_case_end:
    ret

get_day_in_month_array:   
    movq $0xffffffffffffffff, %rax
    cmpq $0xC, %rsi 
    ja .get_day_in_month_array_end
    cmpq $0x1, %rsi
    jb .get_day_in_month_array_end
    
    cmpq $0x2, %rsi
    je .get_day_in_month_array_third


    movq %rsi, %rcx
    dec %rcx
    
    lea days_lookup_table(%rip), %rdx 
    movq (%rdx, %rcx, 8), %rax
    jmp .get_day_in_month_array_end
    
.get_day_in_month_array_third: #29 days
    movq %rdi, %rax
    test $0x3, %eax
    jnz .get_day_in_month_array_thirdB
    
    cqo
    mov $0x64, %rcx
    div %rcx
    test %rdx, %rdx
    jnz .get_day_in_month_array_thirdA
     
    test $0x3, %rdx
    jnz .get_day_in_month_array_thirdB
    jz .get_day_in_month_array_thirdA

.get_day_in_month_array_thirdA:    
    movq $0x1D, %rax
    jmp .get_day_in_month_array_end
    
.get_day_in_month_array_thirdB: #28 days
    movq $0x1C, %rax
    jmp .get_day_in_month_array_end    
    
.get_day_in_month_array_end:
    ret
    
.global main
main:
    subq $0x10, %rsp #year, month
    lea input_format(%rip), %rdi
    lea 0x8(%rsp), %rsi #year
    lea (%rsp), %rdx #month
    xor %eax, %eax
    call scanf@plt

#get_day_in_month_if(year, month)
    movq 0x8(%rsp), %rdi
    movq (%rsp), %rsi
    call get_day_in_month_if
    lea output_format(%rip), %rdi
    movq %rax, %rsi
    xor %eax, %eax
    call printf@plt

#get_day_in_month_case(year, month)
    movq 0x8(%rsp), %rdi
    movq (%rsp), %rsi
    call get_day_in_month_case
    lea output_format(%rip), %rdi
    movq %rax, %rsi
    xor %eax, %eax
    call printf@plt

#get_day_in_month_array(year, month)
    movq 0x8(%rsp), %rdi
    movq (%rsp), %rsi
    call get_day_in_month_array
    lea output_format(%rip), %rdi
    movq %rax, %rsi
    xor %eax, %eax
    call printf@plt
        
.main_end:
 
    addq $0x10, %rsp
    
	xor %eax, %eax
	ret
