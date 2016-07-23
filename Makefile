CC = gcc

CFLAGS = -ffreestanding -c -m32

LINKER = ld 

LFLAGS = -o kernel.img -T linker/linker.ld -m elf_i386 --oformat binary  -e 0x7c00

all: yaoos

yaoos: linker/linker.ld kernel.o keyboard.o timer.o assembly/bootloader.img
	$(LINKER) $(LFLAGS) kernel.o timer.o keyboard.o 
	cat assembly/bootloader.img kernel.img > yaoos/yaoos.img
	truncate yaoos/yaoos.img -s 5120

kernel.o: c/kernel.c
	$(CC) $(CFLAGS) c/kernel.c 

timer.o: c/timer.c
	$(CC) $(CFLAGS) c/timer.c

keyboard.o: c/keyboard.c
	$(CC) $(CFLAGS) c/keyboard.c

assembly/bootloader.img: assembly/bootloader.asm
	nasm assembly/bootloader.asm -f bin -o assembly/bootloader.img

clean: 
	rm *.o
	rm *.img 
	rm assembly/bootloader.img

purge: 
	rm -f *.o
	rm -f *.img 
	rm -f assembly/bootloader.img
	rm -f yaoos/yaoos.img