gdt:

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

    cli                    ;disable interupt to enter in protected mode
    lgdt[gdt_descriptor]   ;load the global descriptor table
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:b32

gdt_start:

gdt_null:
    dd 0x0
    dd 0x0

gdt_code:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start
    dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start