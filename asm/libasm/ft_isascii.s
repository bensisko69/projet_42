section .text
	global _ft_isascii

_ft_isascii:
	mov rax, 1
	mov rcx, rdi

cmp_min:
	cmp rcx, 0
	jge cmp_max
	jmp no_find

cmp_max:
	cmp rcx, 127
	jle end
	jmp no_find

no_find:
	mov rax, 0

end:
	ret
