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

diskload:                   ;This function will load the 9 first blocks of data from
                            ;the floppy drive to the adress kernel_entry in the RAM

    push bp                 ;save base pointer and change stack pointer adress
    mov  bp, sp             ; to keep the running environment safe as does gcc :)


    mov AH, 0x02            ;this function is to read from the drive 
    mov AL, 0x09			;this means wee want to read 9 sectors
    mov DL, 0x00			;Here wee choose the drive 0x00 for floppy disk and 0x80 for hard drive :)
    mov CH, 0x00			;here wee choose the cylinder
    mov DH, 0x00			;here wee choose the head
    mov CL, 0x02			;and here it is the sector
    mov BX, kernel_entry	;there wee choose where to put the data
    int 0x13				;That is the BIOS interrupt
    
    leave                  ;restore base pointer and stack pointer
    ret                    ; return to call function 