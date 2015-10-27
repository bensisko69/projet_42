section .text
	global _ft_memset

_ft_memset:
	cmp rdi, 0
	je null
	cmp rdx, 0
	je null
	mov rcx, rdx
	mov rax, rsi
	mov r8, rdi

copy:
	cld
	rep stosb
	mov rax, r8
	jmp end

null:
	mov rax, 0

end:
	ret