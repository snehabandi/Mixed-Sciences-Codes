section .data
        msg1 db "Enter first string : "
        msg1len equ $-msg1
        msg2 db "Enter second string : "
        msg2len equ $-msg2
        msg3 db "Enter offset : "
        msg3len equ $-msg3

section .bss
        str1: resb 25
        str1len: resb 1
        str2: resb 25
        str2len: resb 1
        str3: resb 50
        str3len: resb 1
        offset: resb 1
        temp: resb 3
        templen: resb 1

section .text
	global _start
	start:

	;display "Enter first string"
        mov rax,1
        mov rdi,1
        mov rsi,msg1
        mov rdx,msg1len
        syscall

	;accept first string
        mov rax,0
        mov rdi,0
        mov rsi,str1
        mov rdx,25
        syscall

        dec al
        mov [str1len],al

	;display first string 
        mov rax,1
        mov rdi,1
        mov rsi,str1
        mov rdx,25
        syscall

	;display "Enter second string"
        mov rax,1
        mov rdi,1
        mov rsi,msg2
        mov rdx,msg2len
        syscall

	;accept second string
        mov rax,0
        mov rdi,0
        mov rsi,str2
        mov rdx,25
        syscall

        dec al
        mov [str2len],al

	;display second string 
        mov rax,1
        mov rdi,1
        mov rsi,str2
        mov rdx,25
        syscall

	;display "Enter offset"
        mov rax,1
        mov rdi,1
        mov rsi,msg3
        mov rdx,msg3len
        syscall

;------------------------------------------------ACCEPT - DISPLAY ENDS ----------------------------------------------------
;------------------------------------------------OFFSET CONVERSION BEGINS ----------------------------------------------------
        ;offset conversion to digit
        ;Accept 'offset' in temp
        mov rax,0
        mov rdi,0
        mov rsi,temp
        mov rdx,3
        syscall

        dec al
        mov [templen],al

        cmp al,01
        jz onedigit

        mov al,[temp]
        sub al,30H
        mov bl,[temp+1]
        sub bl,30H
        mov cl,10
        mul cl
        add al,bl
        jmp next

onedigit:        
        mov al,[temp]
        sub al,30H
next:
        mov [offset],al
;------------------------------------------------OFFSET CONVERSION ENDS ----------------------------------------------------
;------------------------------------------------CREATION OF STRING 3 STARTS ----------------------------------------------

        mov esi,str1
        mov edi,str3
        mov cl,[offset]
        mov al,0

loop:
        mov al,[esi]
        mov [edi],al
        inc esi
        inc edi
        dec cl
        jnz loop

        mov esi,str2

loop1:
        mov al,[esi]
        cmp al,0AH
        jz skip
        mov [edi],al
        inc esi
        inc edi
        jmp loop1

skip:
	;display third string 
        mov rax,1
        mov rdi,1
        mov rsi,str3
        mov rdx,50
        syscall

	;syscall 
        mov rax,60
        mov rdi,0
        syscall
;------------------------------------------------CREATION OF STRING 3 ENDS ----------------------------------------------
;------------------------------------------------DISPLAY OF STRING 3 STARTS ----------------------------------------------
;------------------------------------------------PROGRAM ENDS----------------------------------------------
