;Only open read close the file

section .data
	global buff
	global bufflen
	extern begin
	fname db "file.txt",00H
section .bss
	bufflen:resb 4
	buff:resb 512
	fhandle:resq 1


section .text
global _start
_start:
;------------------------------------------------------ OPEN FILE -----------------------------------------------------
	;Opening the file
	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,0777O
	syscall

	mov [fhandle],ax

	;reading the file
	mov rax,00
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall

	dec rax
	mov [bufflen],rax
;-------------------------------------------------------------------------------------------------	
	;Displaying the contents of the file
	mov rax,1
	mov rdi,1
	mov rsi,buff
	mov rdx,[bufflen]
	syscall
	call begin
	
;------------------------------------------Close the file------------------------------------------	
mov rax,03H
mov rdi,[fhandle]
syscall

;Syscall	
mov rax,60
mov rdi,0
syscall
