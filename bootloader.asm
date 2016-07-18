[BITS 16]   ;Tells the assembler that its a 16 bit code
[ORG 0x7C00]    ;Origin, tell the assembler that where the code will
                ;be in memory after it is been loaded


    mov bp,0xffff
    mov sp,bp
    mov AH, 0x02
    mov AL, 0x09
    mov DL, 0x00
    mov CH, 0x00
    mov DH, 0x00
    mov CL, 0x02
    mov BX, kernel_entry
    int 0x13

    call gdt
    jmp CODE_SEG:b32

    %include"gdt.asm"

[bits 32]

b32:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp kernel_entry


    TIMES 510 - ($ - $$) db 0   ;Fill the rest of sector with 0
    DW 0xAA55           ;Add boot signature at the end of bootloader

kernel_entry:
; where the kernel in c will be :)) 