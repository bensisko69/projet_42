extern _ft_isalpha
extern _ft_isdigit

section .text
	global _ft_isalnum

_ft_isalnum:
	mov rax, 0

search:
	push rdi
	call _ft_isalpha
	pop rdi
	cmp rax, 1
	jz end
	call _ft_isdigit
	cmp rax, 1
	jz end

no_search:
	mov rax, 0

end:
	ret