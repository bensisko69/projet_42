extern _malloc
extern _ft_memcpy
extern _ft_strlen
extern _ft_bzero

section .text
	global _ft_strdup

_ft_strdup:
	mov rax, 0
	cmp rdi, 0
	je end
	push rdi

len:
	call _ft_strlen
	pop rdi
	push r12
	inc rax
	mov r12, rax

dup:
	push rdi
	mov rdi, r12
	call _malloc
	pop rdi
	cmp rax, 0
	je restore
	push rdi
	push rax
	mov rdi, rax
	mov rsi, r12
	call _ft_bzero
	pop rdi
	pop rsi
	mov rdx, r12
	dec rdx
	call _ft_memcpy

restore:
	pop r12

end:
	ret