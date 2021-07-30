section.text:
	global _ft_strlen

_ft_strlen:
	mov rax, 0x0
	start_loop:
		cmp byte [rdi + rax], 0x0
		jz end_loop
		inc rax
		jmp start_loop
	end_loop:
	ret
