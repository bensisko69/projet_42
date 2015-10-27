section .text
	global _ft_strlen

_ft_strlen:
	mov al, 0
	mov rcx, -1
	push rdi

len:
	cld
	repne scasb
	pop rax
	sub rdi, rax
	mov rax, rdi
	dec rax

end:
	ret