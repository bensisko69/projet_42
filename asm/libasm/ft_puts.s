section .data

string:
	db "(null)"

new_line:
	db 0xa

section .text
	global _ft_puts

_ft_puts:

isnull:
	cmp rdi, 0
	je null
	mov rsi, rdi
	mov r12, 0

len:
	cmp byte[rdi], 0
	je read
	inc r12
	inc rdi
	jmp len

read:
	mov rax, 0x2000004
	mov rdi, 1
	mov rdx, r12
	syscall
	cmp rax, r12
	je end
	jmp false

null:
	mov rax, 0x2000004
	mov rsi, string
	mov rdi, 1
	mov rdx, 6
	syscall
	cmp rax, 6
	jne false

end:
	mov rax, 0x2000004
	mov rsi, new_line
	mov rdi, 1
	mov rdx, 1
	syscall
	cmp rax, 1
	je true

false:
	mov rax, 0
	jmp return

true:
	mov rax, 10

return:
	ret