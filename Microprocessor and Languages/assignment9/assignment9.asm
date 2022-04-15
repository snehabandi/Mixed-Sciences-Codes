%macro display 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data

mult dd 10000
minus db '-'
dec1 db '.'
msg1 db "***** ENTER CHOICE *****",0AH,"1. ROOTS",0AH,"2. EXIT",0AH
msglen1 equ $-msg1
msg2 db 0AH
msglen2 equ $-msg2
msg3 db "INVALID INPUT",0AH
msglen3 equ $-msg3
msg4 db "DO YOU WANT TO CONTINUE",0AH,"PRESS:",0AH,"1 FOR YES",0AH,"2 FOR NO",0AH
msglen4 equ $-msg4
a dd 3.0
b dd 7.0
c dd 2.0
t dd 1.0			;to load 1 to the stack

section .bss

choice:resb 2
answer:resb 2
ansp:rest 1			; POSITIVE ROOT VALUE
ansn:rest 1			; NEGATIVE ROOT VALUE
temp:rest 1
opstr:rest 2		

section .text
global _start
_start:

go:
	display msg1,msglen1
	accept choice,2
	cmp byte[choice],31H
	je discri
	display msg3,msglen3
	display msg4,msglen4
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp exit

discri:
	call discriminant
	mov edx,dword[ansp]
	mov dword[temp],edx
	mov edx,0
	call display1
	display opstr,20
	display msg2,msglen2	
	mov edx,dword[ansn]
	mov dword[temp],edx
	mov edx,0
	call display1
	display opstr,20
	display msg2,msglen2
	display msg4,msglen4		;user wants to continue or not?
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp exit			;if user wants to exit
exit:
	mov rax,60
	mov rdi,0
	syscall

discriminant:

	fld dword[t]
	fadd st0
	fld dword[a]
	fmul st0,st1
	fld dword[c]
	fmul st0,st1
	fmul st0,st2
	fld dword[b]
	fmul st0
	fsub st0,st1
	fsqrt
	fld dword[b]
	fchs
	fld st0	
	fsub st0,st2
	fdiv st0,st4
	fst dword[ansn]
	fimul dword[mult]
	fbstp [ansn]
	fadd st0,st1
	fdiv st0,st3
	fst dword[ansp]
	fimul dword[mult]
	fbstp [ansp]
	finit
ret

display1:				; procedure to convert the real number into string
	mov esi,temp
	mov edi,opstr
	mov cl,10
	add esi,9
	mov al,[esi]
	cmp al,30H			;checking the sign of output
	je nexb
	mov al,[minus]			;moving the minus sign to the start of output string
	mov [edi],al
	inc edi
nexb:		
	dec esi
	dec cl
again:
	mov al,[esi]
	and al,0F0H
	shr al,04
	add al,30H
	mov [edi],al
	inc edi
	mov al,[esi]
	and al,0FH
	add al,30H
	mov [edi],al
	inc edi
	dec esi
	dec cl
	jz mexit
	cmp cl,02
	jnz again
	mov al,[dec1]
	mov [edi],al
	inc edi
	jmp again

mexit:
ret	
;-======================================================
;OUTPUT
;***** ENTER CHOICE *****
;1. ROOTS
;2. EXIT
;1
;-00000000000000.3333
;-00000000000002.0000
;DO YOU WANT TO CONTINUE
;PRESS:
;1 FOR YES
;2 FOR NO
;2
;========================================================
