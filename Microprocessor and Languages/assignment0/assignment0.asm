section .data
var1 db 0H
var2 dw 0FH
var3 dd 0H
var4 dq 0

section .bss
val1:resb 1

section .text
global _start
_start:

mov al,02
mov bl,03
add al,bl
;al<=al+bl

mov rax,60
mov rdi,0
syscall

