section .text
	global _ft_memcpy

_ft_memcpy:
	cmp rdi, 0
	je null
	cmp rcx, 0
	je null
	mov rcx, rdx
	mov r8, rdi

copy:
	cld
	rep movsb
	mov rax, r8
	jmp end

null:
	mov rax, 0

end:
	ret