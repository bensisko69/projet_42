section .text
	global _ft_toupper

_ft_toupper:
	mov rax, rdi
	mov rcx, rdi

cmp_maj:
	cmp rcx, 97
	jl end
	cmp rcx, 122
	jge end
	sub rcx, 32
	mov rax, rcx
	jmp end

end:
	ret