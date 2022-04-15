;Conversion of hexadecimal to BCD
%macro display 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm
section .data
	msg1 db "Enter hexadecimal No. : "
	msg1len equ $-msg1
	msgerr db "Enter valid input!",0AH
	msgerrlen equ $-msgerr
	msg2 db 0AH,"The Hexadecimal no. is : "
	msg2len equ $-msg2
	msg3 db 0Ah,"The BCD no. is : "
	msg3len equ $-msg3
	num dw 0
	;base dw 16

section .bss
	temp:resb 5
	templen:resb 1
	bcdno: resw 1
	hexno:resw 1
	;bcdstr:resw 4

section .text
global _start
_start:

re_enter:
	;Display "Enter hexadecimal No."
	display msg1,msg1len
;-------------------------------------------Hexadecimal No. accepted--------------------------------------------
	;Accept BCD No. as a string in temp
	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,5
	syscall

	dec al
	mov byte[templen],al

	;Display entered Hex no.
	display msg2,msg2len
	display temp,5

;-------------------------------------------Hex string to number conversion (packing)-----------------------------
	
	mov cl,byte[templen]
	mov esi,temp
	mov rax,0
loop1:
	mov bl,[esi]
	cmp bl,30H			;condition 1 : <30H
	jb invalid
	cmp bl,47H			;condition 2 : >47H
	ja invalid

	cmp bl,39H			;condition 3 : >39H
	ja check41
	jmp sub30
	
check41:
	cmp bl,41H			;>39H && <41H
	jb invalid
	cmp bl,41H			;>41H	
	ja sub37
sub30:
	sub bl,30H			;digit 0-9
	jmp next

sub37:					;letter A-F
	sub bl,37H
	
next:				
	shl ax,04			;mul word[base]
	mov bh,0
	add ax,bx	
	inc esi
	dec cl
	jnz loop1
	jmp skip

invalid:				;invalid input
	;Display "Invalid input"
	display msgerr,msgerrlen
	jmp re_enter
skip:
	mov [hexno],ax
		;ax contains the number (converted from string)

;----------------------------------------BCD No. to string for display (unpack)--------------------------------------------
	mov cl,0
	mov esi,hexno
	mov bx,10
	mov ax,[esi]
;mov esi,bcdstr

loop2:
	mov dx,0
	div bx		;(quotient)Q-Ax and (remainder)R-dl
	push dx			;pushed remainder on stack
	inc cl
	cmp ax,0
	jnz loop2
loop3:
	;mov bx,0
	pop dx
	add dl,30H
	mov [esi],dl
	inc esi
	dec cl
	jnz loop3
;----------------------------------------Display Hexadecimal No.-------------------------------------------
	display msg3,msg3len
	display hexno,4
;----------------------------------------Display Hexno ends------------------------------------------------
	;syscall
	mov rax,60
	mov rdx,0
	syscall
;---------------------------------------------------END-----------------------------------------------------

