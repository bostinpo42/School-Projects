; This is the standard template for CSCI 150 Lab.
; Unless otherwise directed, start your programs with this template file. 
; Be sure to rename the file appropriately when used for a lab.
; Also you can/should remove this comment before use. 
; Leave the following comments and replace everything between and including
;  the angle brackets with your information.

; who: <Austin Ngo - ango26>
; what: <Adds all of the values of intArray and stores the sum into arraySum>
; why: <sum_array.asm>
; when: <03/27/2022>

section     .text

global      _start

_start:
    mov         eax, [intArray]                                       ; Move into eax the first value of intArray
    add         eax, [intArray + 4]                                 ; Add to eax the second value of intArray
    add         eax, [intArray + 8]                                 ; Add to eax the third value of intArray
    add         eax, [intArray + 12]                                ; Add to eax the fourth value of intArray
    add         eax, [intArray + 16]                                ; Add to eax the fifth value of intArray
    add         eax, [intArray + 20]                                ; Add to eax the sixth value of intArray
    add         eax, [intArray + 24]                                ; Add to eax the seventh value of intArray
    add         eax, [intArray + 28]                                ; Add to eax the eighth value of intArray
    add         eax, [intArray + 32]                                ; Add to eax the ninth value of intArray
    add         eax, [intArray + 36]                                ; Add to eax the tenth value of intArray
    mov         [arraySum], eax                                       ; Moves the value stored in eax to arraySum

exit:  
    mov         ebx, 0                                              ; return 0 status on exit - 'No Errors'
    mov         eax, 1                                              ; invoke SYS_EXIT (kernel opcode 1)
    int         80h

section     .bss
    arraySum    resd 2

section     .data
    intArray    dd  01h, 02h, 03h, 04h, 05h, 06h, 07h, 08h, 09h, 0Ah ; Initializes intArray with 10 consecutive values
