%macro display 2
	mov rax,01
	mov rdi,01
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro
 
section .data

	fname db "file1.txt",0

	msg1 db "Output updated in file",0AH
	msg1len equ $-msg1
	msg2 db "File Opened",0AH
	msg2len equ $-msg2
	msg3 db "File Read",0AH
	msg3len equ $-msg3
	msg4 db "File Closed",0AH
	msg4len equ $-msg4


section .bss

	fhandle: resq 1
	buff: resb 512
	length resb 1	

section .text

global _start
_start: 

;------opening a file	----------
	mov rax,0
	
	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,0777o
	syscall
	
	mov [fhandle],rax
	display msg2,msg2len

;------reading a file	----------
	
	mov rax,0
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall
	dec ax
	mov [length],al
	display msg3,msg3len


;------writing a file	----------
	
	mov rax,1
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall

;-------closing a file----------

	mov rax,03
	mov rdi,fhandle
	syscall
	display msg4,msg4len

;------------bubble sort---------------

	call bubble_sort

;------opening a file	----------

	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,0777o
	syscall

	mov [fhandle],rax

;------writing a file	----------
	
	mov rax,1
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall

;-------closing a file----------

	mov rax,03
	mov rdi,fhandle
	syscall

;-----final msg-----------

	display msg1,msg1len

;----------EXIT CALL-------------

mov rax,60
mov rdi,0
syscall

;------definition of procedure----------
bubble_sort:	

	mov ch,[length]
nxt_itr:			
	mov esi,buff
	mov cl,[length-1]

above:
	mov bl,[esi]
	mov bh,[esi+1]
	cmp bl,bh
	ja swap
	jmp next
swap:
	mov ch,[esi]
	mov bh,[esi+1]
	mov [esi],bh
	mov [esi+1],ch
next:
	inc esi
	dec cl
	jnz above	

	dec ch
	jnz nxt_itr		

ret
