section .text
	global _ft_strcmp

_ft_strcmp:
	push	rcx
	mov		rcx, -1

	start_loop:
		inc		rcx
		mov		al, BYTE [rdi+rcx]
		mov		bl, BYTE [rsi+rcx]
		cmp		al, 0x0
		je		ret_null
		cmp		bl, 0x0
		je		ret_null
		cmp		al, bl
		je		start_loop
		ja		above
		jb		below

ret_null:
	cmp		al, bl
	ja		above
	je		end
	jmp		below

above:
	pop		rcx
	mov		rax, 1
	ret

below:
	pop 	rcx
	mov		rax, -1
	ret

end:
	pop		rcx
	mov		rax, 0
	ret
