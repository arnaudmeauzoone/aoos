LINKER = ld 

LFLAGS = -o kernel.img -T linker/linker.ld -m elf_i386 --oformat binary  -e 0x7c00

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all:sub_make yaoos

yaoos: linker/linker.ld assembly/bootloader.img idt.a.o interupt.a.o
	@$(LINKER) $(LFLAGS) c/kernel.o c/timer.o c/keyboard.o c/console.o c/test.o idt.a.o interupt.a.o c/idt.o
	@printf "[$(GREEN)OK$(NC)] kernel.img\n"

 
	@cat assembly/bootloader.img kernel.img > yaoos/yaoos.img
	@printf "[$(GREEN)OK$(NC)] yaoos.img before truncate\n"
	
	@truncate yaoos/yaoos.img -s 5120
	@printf "[$(GREEN)OK$(NC)] yaoos.img\n"


assembly/bootloader.img: assembly/bootloader.asm
	@nasm assembly/bootloader.asm -f bin -o assembly/bootloader.img
	@printf "[$(GREEN)OK$(NC)] bootloader.img.o\n"


idt.a.o: assembly/idt.asm
	@nasm assembly/idt.asm -f elf -o idt.a.o
	@printf "[$(GREEN)OK$(NC)] idt.a.o\n"

interupt.a.o: assembly/interupt.asm
	@nasm assembly/interupt.asm -f elf -o interupt.a.o
	@printf "[$(GREEN)OK$(NC)] interupt.img.o\n"

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
	$(MAKE) -C c/ mrproper

rebuild: mrproper all

sub_make:
	$(MAKE) -C c/ all