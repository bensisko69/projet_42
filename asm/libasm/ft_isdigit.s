section .text
	global _ft_isdigit

_ft_isdigit:
	mov rax, 1
	mov rcx, rdi

search_max:
	cmp rcx, 57
	jle search_min
	jmp no_find

search_min:
	cmp rcx, 48
	jge end
	jmp no_find

no_find:
	mov rax, 0

end:
	ret