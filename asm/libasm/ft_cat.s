;void	ft_cat(int fd)
;				  rdi

%define sys_read 0x2000003
%define sys_write 0x2000004

section .data
	buffer times 4096 db 0
	buff_size equ $ - buffer

string:
	db "bad file descriptor", 10
	len_string equ $ - string

failed:
	db "write failed", 10

section .text
	global _ft_cat

_ft_cat:
	mov rbx, rdi

read:
	mov rax, sys_read
	mov rdi, rbx
	lea rsi, [rel buffer]
	mov rdx, buff_size
	syscall
	jc read_false
	cmp rax, 0
	jle end

write:
	mov rdx, rax
	mov rax, sys_write
	mov rdi, 1
	syscall
	jc failed_write
	jmp read

read_false:
	mov rax, sys_write
	mov rdi, 1
	mov rsi, string
	mov rdx, len_string
	syscall
	jmp end

failed_write:
	mov rax, sys_write
	mov rdi, 1
	mov rsi, failed
	mov rdx, 13
	syscall
	jc end

end:
	ret