section .text
	global _ft_bzero

_ft_bzero:

str_zero:
	cmp rsi, 0
	je end
	mov byte[rdi], 0
	inc rdi
	dec rsi
	jmp str_zero

end:
	ret
