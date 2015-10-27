section .text
	global _ft_strcat

_ft_strcat:
	mov rax, rdi
	cmp byte [rdi], 0
	je end
	cmp byte [rsi], 0
	je end

end_str:
	inc rdi
	cmp byte [rdi], 0
	jne end_str

cat:
	mov cl, [rsi] 
	mov [rdi], cl
	inc rdi
	inc rsi
	cmp byte [rsi], 0
	jne cat

end:
	ret