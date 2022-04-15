;Open a file and read its contents
;then copy the contents of that file into new file 
;delete the file 
%macro display 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm display
section .data
	msg1 db "	MENU",0AH 
	msg1len equ $-msg1
	msg2 db "1. To open a file",0AH 
	msg2len equ $-msg2
	msg3 db "2. To copy a file",0AH 
	msg3len equ $-msg3
	msg4 db "3. To Delete a file",0AH 
	msg4len equ $-msg4
	msg5 db "Your entered choice is : "
	msg5len equ $-msg5
	msg6 db "4. Exit ",0AH
	msg6len equ $-msg6
	msg7 db "The file contents are : ",0AH
	msg7len equ $-msg7
	msgerr db "Invalid input",0AH
	msgerrlen equ $-msgerr

section .bss
	command:resb 13
	command_len:resb 1
	command1:resb 20
	command_len1:resb 1
	command2:resb 15
	command_len2:resb 1
	temp:resb 2
	templen:resb 1

	choice_string:resb 1
	buff:resb 512			;contains contents of first file
	bufflen:resb 4	
	buff1:resb 512			;contains contents of second file
	bufflen1:resb 4	
	fname:resb 12
	fhandle:resq 1
	fname1:resb 12
	fhandle1:resq 1
	fname2:resb 12
	fhandle2:resq 1
section .text
global _start
_start:
;========================================================================>MENU
menu:
	display msg1,msg1len
	display msg2,msg2len
	display msg3,msg3len
	display msg4,msg4len
	display msg6,msg6len
	mov al,0
	mov byte[temp],0
;--------- accept choice ---------	
	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,2
	syscall
	dec al
	mov [templen],al
;--------- Packing of choice ---------
	mov cl,[templen]
	mov esi,temp
	mov ax,0
;display choice	
	display msg5,msg5len
;========================================================================>Switch case_
	cmp byte[temp],31H
	je display_1
	cmp byte[temp],32H
	je display_2
	cmp byte[temp],33H
	je display_3
	cmp byte[temp],34H
	je display_exit
	jmp invalid_choice
;========================================================================>OPEN FILE
display_1:
display msg2,msg2len
mov al,0
;--------- Accept command line args ---------
	mov rax,0
	mov rdi,0
	mov rsi,command
	mov rdx,13
	syscall
	dec al	
	mov [command_len],al	
	display command,13
;--------- Check syntax of "type" ---------
	mov esi,command
	mov cl,07
	cmp byte[esi],'t'
	jne no_match
	inc esi

	cmp byte[esi],'y'
	jne no_match
	inc esi

	cmp byte[esi],'p'
	jne no_match
	inc esi

	cmp byte[esi],'e'
	jne no_match
	inc esi
	inc esi			;to skip blank space
	jmp match
no_match:
	display msgerr,msgerrlen 
	jmp menu
match:	
;--------- MOVE abc.txt TO fname ---------

	mov edi,fname
ag1:	mov bl,[esi]
	mov [edi],bl
	inc esi
	inc edi
	dec cl
	jnz ag1
	mov byte[edi],00H
	display fname,8			;to check if fname is recieving correct value
;--------- OPEN FILE abc.txt ---------
	;open the file	
	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,0777o
	syscall

	mov [fhandle],rax

	;Read the file
	mov rax,00
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall

	;dec rax
	mov [bufflen],rax

	;Displaying the contents of the file
	display buff,[bufflen]
	
;--------- Close the file 1 ---------	
	mov rax,03H
	mov rdi,[fhandle]
	syscall
jmp menu

;=======================================================>COPY FILE
display_2:
display msg3,msg3len
;--------- Accept command line args ---------
	mov rax,0
	mov rdi,0
	mov rsi,command1
	mov rdx,21
	syscall
	;dec al
	;mov [command_len1],al

	display command1,21
;--------- Check syntax of "copy" ---------
	mov esi,command1
	cmp byte[esi],'c'
	jne no_match1
	inc esi

	cmp byte[esi],'o'
	jne no_match1
	inc esi

	cmp byte[esi],'p'
	jne no_match1
	inc esi

	cmp byte[esi],'y'
	jne no_match1
	inc esi
	inc esi			;to skip blank space
	jmp match1
no_match1:
	display msgerr,msgerrlen 
	jmp menu
match1:	
;--------- MOVE xyz.txt TO fname1 ---------
	mov cl,07
	mov edi,fname1
ag2:	mov bl,[esi]
	mov [edi],bl
	inc esi
	inc edi
	dec cl
	jnz ag2
	mov byte[edi],00H
	display fname1,8			;to check if fname is recieving correct value

;--------- OPEN FILE xyz.txt ---------
	mov rax,02
	mov rdi,fname1
	mov rsi,02
	mov rdx,0777o
	syscall

	mov [fhandle1],rax

	;Write to file
	mov rax,1
	mov rdi,[fhandle1]
	mov rsi,buff
	mov rdx,[bufflen]
	syscall

	;Read the file
	mov rax,00
	mov rdi,[fhandle1]
	mov rsi,buff1
	mov rdx,512
	syscall

	;dec rax
	mov [bufflen1],rax

	;Displaying the contents of the file 1
	;display buff,byte[bufflen]

;---------Close the file 2 ---------	
	mov rax,03H
	mov rdi,[fhandle1]
	syscall
jmp menu
;=======================================================>DELETE FILE
display_3:
	display msg4,msg4len
	mov al,0
;--------- Accept command line args -------------
	mov rax,0
	mov rdi,0
	mov rsi,command2
	mov rdx,15
	syscall
	dec al	
	mov [command_len2],al	
	display command,15
;------- Check syntax of "delete" -------------
	mov esi,command2
	mov cl,07
	cmp byte[esi],'d'
	jne no_match2
	inc esi

	cmp byte[esi],'e'
	jne no_match2
	inc esi

	cmp byte[esi],'l'
	jne no_match2
	inc esi

	cmp byte[esi],'e'
	jne no_match2
	inc esi

	cmp byte[esi],'t'
	jne no_match2
	inc esi

	cmp byte[esi],'e'
	jne no_match2
	inc esi
	inc esi			;to skip blank space
	jmp match2
no_match2:
	display msgerr,msgerrlen 
	jmp menu
match2:	
;--------- MOVE xyz.txt TO fname1 ---------
	mov cl,07
	mov edi,fname2
ag3:	mov bl,[esi]
	mov [edi],bl
	inc esi
	inc edi
	dec cl
	jnz ag3
	mov byte[edi],00H
	display fname2,8			;to check if fname is recieving correct value

	mov rax,87
	mov rdi,fname2
	syscall
jmp menu
invalid_choice:
	display msgerr,msgerrlen 
display_exit:
	display msg6,msg6len

;--------- Syscall -----------
;Syscall	
mov rax,60
mov rdi,0
syscall

;--------- Program Ends -----------
