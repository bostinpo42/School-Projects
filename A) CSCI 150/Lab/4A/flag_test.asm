; This is the standard template for CSCI 150 Lab.
; Unless otherwise directed, start your programs with this template file. 
; Be sure to rename the file appropriately when used for a lab.
; Also you can/should remove this comment before use. 
; Leave the following comments and replace everything between and including
;  the angle brackets with your information.

; who: <Austin Ngo - ango26>
; what: <test various flags>
; why: <flag_test.asm>
; when: <03/27/2022>

section     .text

global      _start

_start:
    mov     al, -128        ; Move -128 into al
    neg     al              ; Negate al (bit flip) CF, SF, OF
    mov     ax, 8000h       ; Adds 8000(hex) to ax 
    add     ax, 2           ; Adds 2 to ax SF
    mov     ax, 0           ; Moves 0 to ax 
    sub     ax, 2           ; Subtracts 2 from ax CF SF
    mov     al, -5          ; Moves -5 to al
    sub     al, +125        ; Adds 125 to al OF

exit:  
    mov     ebx, 0          ; return 0 status on exit - 'No Errors'
    mov     eax, 1          ; invoke SYS_EXIT (kernel opcode 1)
    int     80h

section     .bss

section     .data

