;Open read close only in this file
%macro display 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov edx,%2
	syscall
%endm display

section .data
	msg1 db 0AH,"The no. of blank spaces are : "
	msg1len equ $-msg1
	msg2 db 0AH,"The no. of lines are : "
	msg2len equ $-msg2
	msg3 db 0AH,"The no. of 'A' are : "
	msg3len equ $-msg3
	msg4 db 0AH
	msg4len equ $-msg4


section .bss
	ctr1:resb 1
	ctr2:resb 1
	ctr3:resb 1

	extern buff
	extern bufflen
	global begin       ;procedure name

section .text

begin:
	mov byte[ctr1],0			;initialize counters to zero
	mov byte[ctr2],0
	mov byte[ctr3],0

;--------------------------------------------- Occurance of blank spaces --------------------------------------------- 
	mov esi,buff
	mov cl,[bufflen]
blank:
	mov dl,byte[esi]
	cmp dl,20H		;20H is ASCII of blank space
	jne skip

	inc byte[ctr1]
skip:
	inc esi
	dec cl
	jnz blank
;----------------------------------------------------- Unpack ctr1 --------------------------------------------------
	mov ah,0
	mov bh,0
	mov cl,0
	mov esi,ctr1
	mov bx,10
	mov ax,[esi]

	call procedure_unpack
;--------------------------------------------- Occurance of lines --------------------------------------------
	mov esi,buff
	mov cl,[bufflen]
blank2:
	mov dl,byte[esi]
	cmp dl,0AH		;0AH is ASCII of Enter 
	jne skip2

	inc byte[ctr2]
skip2:
	inc esi
	dec cl
	jnz blank2
;----------------------------------------------------- Unpack ctr2 --------------------------------------------------
	mov ah,0
	mov bh,0
	mov cl,0
	mov esi,ctr2
	mov bx,10
	mov ax,[esi]

	call procedure_unpack
;--------------------------------------------- Occurance of character --------------------------------------------
	mov esi,buff
	mov cl,[bufflen]
blank3:
	mov dl,byte[esi]
	cmp dl,41H		;41H is ASCII of A 
	jne skip3

	inc byte[ctr3]
skip3:
	inc esi
	dec cl
	jnz blank3
;----------------------------------------------------- Unpack ctr3 --------------------------------------------------
	mov ah,0
	mov bh,0
	mov cl,0
	mov esi,ctr3
	mov bx,10
	mov ax,[esi]

	call procedure_unpack
;----------------------------------------------------- Display Counters --------------------------------------------------

;display msg1
	display msg1,msg1len
;display ctr1
	display ctr1,1
;display msg2
	display msg2,msg2len
;display ctr2
	display ctr2,1
;display msg3
	display msg3,msg3len
;display ctr3
	display ctr3,1
;display 0AH
	display msg4,msg4len
;----------------------------------------------------- Syscall --------------------------------------------------
endprog:
	mov rax,60
	mov rdi,0
	syscall
;--------------------------------------------------------- Procedure ----------------------------------------------
procedure_unpack:

loop_push1:
	mov dx,0
	div bx		;(quotient)Q-Ax and (remainder)R-dl
	push dx			;pushed remainder on stack
	inc cl
	cmp ax,0
	jnz loop_push1
loop_pop1:
	pop dx
	add dl,30H
	mov [esi],dl
	inc esi
	dec cl
	jnz loop_pop1
ret

;----------------------------------------------------- End --------------------------------------------------



;----------------------------------------------------------------- >> OUTPUT
;This is my First line
;C A D
;A V G
;
;The no. of blank spaces are : 8
;The no. of lines are : 3
;The no. of 'A' are : 2


