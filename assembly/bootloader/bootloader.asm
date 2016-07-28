;    This program is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
;    Written by Arnaud Meauzoone




[BITS 16]   ;Tells the assembler that its a 16 bit code
[ORG 0x7C00]    ;Origin, tell the assembler that where the code will
                ;be in memory after it is been loaded


    mov bp,0xffff
    mov sp,bp

    call diskload

    call gdt

    jmp CODE_SEG:b32

    %include"assembly/bootloader/gdt.asm"
    %include"assembly/bootloader/diskload.asm"

[bits 32]

b32:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x7e00


    TIMES 510 - ($ - $$) db 0   ;Fill the rest of sector with 0
    DW 0xAA55           ;Add boot signature at the end of bootloader

kernel_entry:
; where the kernel in c will be :)) 