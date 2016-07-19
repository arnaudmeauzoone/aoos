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