section .text
	global _ft_isprint

_ft_isprint:
	mov rax, 1
	mov rcx, rdi

char_min:
	cmp rcx, 32
	jge char_max
	jmp no_find

char_max:
	cmp rcx, 127
	jle end
	jmp no_find

no_find:
	mov rax, 0

end:
	ret