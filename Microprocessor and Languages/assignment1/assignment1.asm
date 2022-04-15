;=> This code is to find number of positive and negative elements in an array of 5 numbers
;	and display both the counters
;Range of positibe numbers is from 0 to 127 and beyound that 2's complement representation
%macro display 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm

section .data
	msg1 db "The no. of positive numbers in array are : "
	msg1len equ $-msg1
	msg2 db 0AH,"The no. of negative numbers in array are : "
	msg2len equ $-msg2
	msg3 db 0AH,0AH
	msg3len equ $-msg3
	arr db 250,0,75H,29H,20H

section .bss
	neg:resb 1
	pos:resb 1
	;array:resb 15
section .text
global _start
_start:

	mov cl,05
	mov esi,arr
	mov bx,0	;making bl and bh 0

again:
	mov al,byte[esi]
	add al,00	;Without this line ans is 5,0
	js negative
	inc bh		;sign bit is set thus positive counter is incremented
	jmp positive
negative:
	inc bl		;counter for negative numbers
positive:
	inc esi

	dec cl
	jnz again
;loop ends
	;Packing
	add bl,30H
	add bh,30H
	
	mov byte[pos],bh
	mov byte[neg],bl

	display msg3,msg3len
	display msg1,msg1len
	display pos,1
	display msg2,msg2len
	display neg,1
	display msg3,msg3len

;Syscall
	mov rax,60
	mov rdx,0
	syscall
;===================== Output ======================
;
;The no. of positive numbers in array are : 5
;The no. of negative numbers in array are : 0
;
;===================================================

