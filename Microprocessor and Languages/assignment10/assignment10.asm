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
	minus db '-'
	dec1 db '.'
	mult dd 10000
	arr dd 10.0,15.0,20.0,25.0,10.0
	n dd 5
	tval dd 0.0
	msg1 db "Following is the menu",0AH,"1.mean",0AH ,"2.variance",0AH,"Standard deviation",0AH,"Enter choice",0AH
	msglen1 equ $-msg1
	msg2 db 0AH
	msglen2 equ $-msg2
	msg3 db 0AH,"Wrong choice entered",0AH
	msglen3 equ $-msg3
	msg4 db "Do you want to continu",0AH,"yes-1  no-2",0AH
	msglen4 equ $-msg4
	
section .bss
	
	opstr:resb 20     ;same as resb 20
	temp: rest 1
	meanr:resd 1  
	meanb rest 1   
	varr: resd 1
	varb: rest 1   
	sdb: rest 1
	answer: resb 2
	choice:resb 2
	done:resb 1

section .text
global _start
_start:
	
go:	display msg1,msglen1
	accept choice,2

	cmp byte[choice],31H
	je meanval
	cmp byte[choice],32H
	je varval
	cmp byte[choice],33H
	je sdval
	display msg3,msglen3
	display msg4,msglen4
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp mexit
	
meanval:
	call mean
	mov byte[done],1
	mov edx,dword[meanb]
	mov dword[temp],edx
	mov edx,0
	call display1
	display opstr,20
	display msg2,msglen2
	cmp byte[choice],32H
	je varval
	cmp byte[choice],33H
	je sdval
	display msg4,msglen4
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp mexit
	


;cmp byte[choice],2
varval:
	cmp byte[done],1
	jne meanval
	call var
	mov byte[done],2
	mov edx,dword[varb]
	mov dword[temp],edx
	call display1
	display opstr,20
	display msg2,msglen2
	cmp byte[choice],33H
	je sdval
	display msg4,msglen4
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp mexit
	

sdval:
	cmp byte[done],2
	jne varval
	call sd
	mov byte[done],3
	mov edx,dword[sdb]
	mov dword[temp],edx
	mov edx,0
	call display1
	display opstr,20
	display msg2,msglen2
	display msg4,msglen4
	accept answer,2
	cmp byte[answer],31H
	je go
	jmp mexit
	
mexit:	mov rax,60
	mov rdi,0
	syscall

mean:	fldz
	mov ecx,[n]
	mov esi,arr
ag:	fadd dword[esi]
	add esi,4
	dec cl
	jnz ag
	fidiv dword[n]
	fst dword[meanr]   ;storing real value
	fimul dword[mult]
	fbstp [meanb]        ;storing bcd value
	ret

var:    finit
	mov ecx,[n]
	mov esi,arr
	fld dword[meanr]
again1:	fld dword[esi]
	fsub st0,st1
	fmul st0
	fadd dword[tval]
	fstp dword[tval]
	add esi,4
	dec cl
	jnz again1
	fld dword[tval]
	fidiv dword[n]
	fst dword[varr]
	fimul dword[mult]
	fbstp [varb]
	ret

sd:
	finit
	fld dword[varr]
	fsqrt 
	fimul dword[mult]
	fbstp [sdb]
	ret

display1:
	mov esi,temp
	mov edi,opstr
	mov cl,10
	add esi,9
	mov al,[esi]
	cmp al,0
	je nexb
	mov al,[minus]        ;putting minus sign 
	mov [edi],al
	inc edi	

nexb:   
	dec esi
	dec cl

again:  mov al,[esi]          ;logic to convert into bcd number
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
	jz exit
	cmp cl,02
	jne again
	mov al,[dec1]
	mov [edi],al
	inc edi
	jmp again

exit:   ret
	
;======================================================
;OUTPUT
;Following is the menu
;1.mean
;2.variance
;Standard deviation
;Enter choice
;1
;00000000000016.0000
;Do you want to continu
;yes-1  no-2
;1
;Following is the menu
;1.mean
;2.variance
;Standard deviation
;Enter choice
;2
;00000000000034.0000
;Do you want to continu
;yes-1  no-2
;1
;Following is the menu
;1.mean
;2.variance
;Standard deviation
;Enter choice
;3
;00000000000005.8310
;Do you want to continu
;yes-1  no-2
;2

;======================================================

