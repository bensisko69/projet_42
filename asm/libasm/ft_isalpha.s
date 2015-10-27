section .text
	global _ft_isalpha

_ft_isalpha:
	mov rax, 1
	mov rcx, rdi

cmp_:
	cmp rcx, 65
	jge cmp_maj
	jmp no_find

cmp_maj:
	cmp rcx, 90
	jle end
	jmp cmp_min

cmp_min:
	cmp rcx, 97
	jge cmp_max_min 
	jmp no_find

cmp_max_min:
	cmp rcx, 122
	jle end
	jmp no_find

no_find:
	mov rax, 0

end:
	ret