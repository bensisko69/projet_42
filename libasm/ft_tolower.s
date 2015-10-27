section .text
	global _ft_tolower

_ft_tolower:
	mov rax, rdi
	mov rbx, rdi

cmp_maj:
	cmp rbx, 65
	jl end
	cmp rbx, 90
	jge end
	add rbx, 32
	mov rax, rbx
	jmp end

end:
	ret