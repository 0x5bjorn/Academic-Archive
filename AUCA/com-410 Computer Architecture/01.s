.section .data
message:
	.string "hello, world 01.s"
.section .text
.global main
main:
	lea message(%rip), %rdi
	callq puts@plt
	mov $0, %rax
	ret
