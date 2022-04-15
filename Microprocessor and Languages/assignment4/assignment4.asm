;Multiplication of two 8-bit hexadecimal numbers by add and shift and successive addition
;	use of 64 bit reg
;8-bit no. means 0-255 or 0-ff
;max multiplication FFxFF = FE01
;The multiplicand is accepted and checked for validation-WORKING!
;The multiplier is accepted and checked for validation-WORKING!
;The multiplication by successive addition is working-WORKING!
;The multiplication by add and shift is partially working-WORKING!
%macro accept 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endm
%macro display 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endm
section .data
	msg1 db 0AH,"Enter Multiplicand : "
	msg1len equ $-msg1
	msg2 db 0AH,"Enter Multiplier : "
	msg2len equ $-msg2
	msg3 db "Enter valid input !",0AH
	msg3len equ $-msg3
	msg4 db 0AH,"Multiplication by successive addition is : "
	msg4len equ $-msg4
	msg5 db 0AH,"Multiplication by shift and add is : "
	msg5len equ $-msg5
	ctr2 db 8
section .bss
	multiplicand: resb 3
	multiplier: resb 3
	num1: resb 1
	num2: resb 1
	ans : resw 1
	ans1 : resw 1
	flag: resb 1		;multiplier/multiplicand
	ans_str:resb 5
	ans_str1:resb 5
section .text
global _start
_start:

;-----------------------------------------------Accept multiplicand (string)--------------------------------------------------.
again1:
	mov bh,0
	display msg1,msg1len
	accept multiplicand,3
;-----------------------------------------------Packing of multiplicand (Ascii to decimal)-------------------------------------------------
	mov esi,multiplicand
	call proc_pack
	mov [num1],al
;------------------------------------------------- Accept multiplier (string)--------------------------------------------------
again2:
	mov bh,1
	display msg2,msg2len
	accept multiplier,3
;-------------------------------------------- Packing of multiplier(Ascii to hexadecimal) ------------------------------------------
	mov esi,multiplier
	call proc_pack
	mov [num2],al
	jmp skip_invalid
;-------------------------------------------- invalid ------------------------------------------
invalid:
	display msg3,msg3len
	cmp bh,0
	je again1
	cmp bh,1
	je again2

skip_invalid:
	;num1 has multiplicand num2 has multiplier
	mov ax,0
	mov bx,word[num1]
	mov bh,0		;important as the bh portion might have garbage as the actual num1 in bl
	mov cl,byte[num2]
;-------------------------------------------- successive addition ------------------------------------------
loop_add:
	add ax,bx
	dec cl
	jnz loop_add
	mov word[ans],ax
;-------------------------------------------- unpack ------------------------------------------
	mov cl,12
	mov ch,04
	mov bx,0F000H
	mov esi,ans_str
loop3:
	mov ax,[ans]
	and ax,bx
	shr ax,cl
	cmp ax,09
	ja add37

	add ax,30H
	jmp store
add37:				;letters A-F i.e 10-15
	add ax,37H
store:
	mov [esi],al
	sub cl,04
	shr bx,04
	inc esi
	dec ch
	jnz loop3

	display msg4,msg4len
	display ans_str,4
;------------------------------------------- Multiplication by shift and add ---------------------------------------
	mov ax,0
	mov ch,0
	mov bx,word[num1]
	mov bh,0		;important as the bh portion might have garbage as the actual num1 in bl
	mov cl,byte[num2]

	mov dl,0          ;---- for temporary variable
	mov ax,0
	mov dl,byte[num2]  
	mov bl,byte[num2] ;--for multiplier
	mov bh,byte[num1]  ;--for multiplicand
	mov al,bl
repeat:
	SHR dl,1         ; to shift the temporary variable by one bit
	jnc shift        ; jump if carry flag is not set
	add ah,bh        ; A=A+multiplicand
shift:     
	RCR ax,1         ; to rotate A right through carry by 1 bit 
	dec byte[ctr2]   ; decrementing counter
	jnz repeat       ; till counter not zero

mov [ans1],dl

;-------------------------------------------- unpack ------------------------------------------
	mov cl,12
	mov ch,04
	mov bx,0F000H
	mov esi,ans_str1
loop3_:
	mov ax,[ans1]
	and ax,bx
	shr ax,cl
	cmp ax,09
	ja add37_

	add ax,30H
	jmp store_
add37_:				;letters A-F i.e 10-15
	add ax,37H
store_:
	mov [esi],al
	sub cl,04
	shr bx,04
	inc esi
	dec ch
	jnz loop3_

	display msg5,msg5len
	display ans_str1,4
;------------------------------------------------ Syscall ----------------------------------------------------------
	;Syscall
	mov rax,60
	mov rdi,0
	syscall
;------------------------------------------- Procedure Pack --------------------------------------------------------
proc_pack:
	mov cl,02
	mov al,0H
loop1:
	mov bl,[esi]
	cmp bl,30H			;below 30
	jb invalid	

	cmp bl,46H			;above 46
	ja invalid

	cmp bl,39H
	ja check41
	jmp sub30			;else packing code for 30-39

check41:
	cmp bl,41H			;between 39-41
	jb invalid
sub37:					;41-46
	sub bl,37H
	jmp skip
sub30:
	sub bl,30H
skip:
	shl al,4
	add al,bl
	inc esi
	dec cl
	cmp cl,0H
	jnz loop1
ret

;----------------------------------------------------------END-------------------------------------------------------------
