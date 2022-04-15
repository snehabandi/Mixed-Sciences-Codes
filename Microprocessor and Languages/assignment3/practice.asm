section .data
	msg1 db 0AH,"Enter Hexadecimal no : "
	msg1len equ $-msg1
	msg2 db 0AH,"BCD no. is : "
	msg2len equ $-msg2
	msg3 db 0AH,0AH
	msg3len equ $-msg3
	num dw 0
	base dw 10

section .bss
	temp:resb 5
	templen:resb 1
	bcdno: resw 1
	bcdstr:resb 4
	hexno:resw 1

section .text
global _start
_start:

	;"Display Enter hex No."
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,msg1len
	syscall
;-------------------------------------------hex No. accepted--------------------------------------------
	;Accept hex No. as a string in temp
	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,05
	syscall

	dec al
	mov [templen],al

;--------------------------------hex string(ASCII) to number conversion (binary internally)-----------------------------
	mov cl,[templen]
	mov esi,temp
	mov ax,0
loop1:
	mov bl,[esi]
	cmp bl,41H
;	ja letter
	sub bl,30H
;	jmp next
;letter:
;	sub bl,37H
;next:
	shl ax,4		;mul dx
	mov bh,0		;movzx bx,bl
	add ax,bx
	inc esi
	dec cl
	jnz loop1
	mov [hexno],ax	
;------------------------------------------hex to decimal packing-------------------------------------------

	mov bx,0F000H
	mov ch,04
	mov cl,12
loop2:
	mov ax,[num]			;these two statements should be before dx statements
	mul WORD[base]
	mov dx,[hexno]
	and dx,bx
	shr dx,cl
	add ax,dx
	mov [num],ax
	shr bx,04
	sub cl,04
	dec ch
	jnz loop2
	mov [bcdno],ax
;----------------------------------------Convert Hexadecimal No. to string (ASCII)------------------------------------

	mov cl,12
	mov ch,04
	mov bx,0F000H
	mov esi,bcdstr
loop3:
	mov ax,[bcdno]
	and ax,bx
	shr ax,cl
	add al,30H
store:
	mov [esi],al
	sub cl,04
	shr bx,04
	inc esi
	dec ch
	jnz loop3
;----------------------------------------Display Hexadecimal No.-------------------------------------------------

	;"Display msg2"
	mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,msg2len
	syscall

	mov rax,1
	mov rdi,1
	mov rsi,bcdstr
	mov rdx,04
	syscall

	;"Display msg3"
	mov rax,1
	mov rdi,1
	mov rsi,msg3
	mov rdx,msg3len
	syscall
;----------------------------------------Display Hexadecimal No. ends--------------------------------------------
	;syscall
	mov rax,60
	mov rdx,0
	syscall












