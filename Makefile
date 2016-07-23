CC = gcc

CFLAGS = -ffreestanding -c -m32

LINKER = ld 

LFLAGS = -o kernel.img -T linker/linker.ld -m elf_i386 --oformat binary  -e 0x7c00

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

yaoos: linker/linker.ld kernel.o keyboard.o timer.o console.o assembly/bootloader.img 
	@$(LINKER) $(LFLAGS) kernel.o timer.o keyboard.o console.o
	@printf "[$(GREEN)OK$(NC)] kernel.img\n"

 
	@cat assembly/bootloader.img kernel.img > yaoos/yaoos.img
	@printf "[$(GREEN)OK$(NC)] yaoos.img before truncate\n"
	
	@truncate yaoos/yaoos.img -s 5120
	@printf "[$(GREEN)OK$(NC)] yaoos.img\n"

kernel.o: c/kernel.c
	@$(CC) $(CFLAGS) c/kernel.c 
	@printf "[$(GREEN)OK$(NC)] Kernel.o\n"

timer.o: c/timer.c
	@$(CC) $(CFLAGS) c/timer.c
	@printf "[$(GREEN)OK$(NC)] timer.o\n"


keyboard.o: c/keyboard.c
	@$(CC) $(CFLAGS) c/keyboard.c
	@printf "[$(GREEN)OK$(NC)] keyboard.o\n"


assembly/bootloader.img: assembly/bootloader.asm
	@nasm assembly/bootloader.asm -f bin -o assembly/bootloader.img
	@printf "[$(GREEN)OK$(NC)] bootloader.img.o\n"

console.o: c/console.c
	@$(CC) $(CFLAGS) c/console.c
	@printf "[$(GREEN)OK$(NC)] console.o\n"


clean: 
	@rm -f *.o
	@rm -f *.img 
	@rm -f assembly/bootloader.img
	@printf "[$(GREEN)OK$(NC)] cleaned\n"


mrproper: 
	@rm -f *.o
	@rm -f *.img 
	@rm -f assembly/bootloader.img
	@rm -f yaoos/yaoos.img
	@printf "[$(GREEN)OK$(NC)] erased everything but code\n"
