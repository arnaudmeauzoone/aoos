#     This program is free software: you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation, either version 3 of the License, or
#     (at your option) any later version.

#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.

#     You should have received a copy of the GNU General Public License
#     along with this program.  If not, see <http://www.gnu.org/licenses/>.

#     Written by Arnaud Meauzoone

LINKER = ld 

LFLAGS = -o kernel.img -T linker/linker.ld -m elf_i386 --oformat binary  -e 0x7c00

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

SRC_C= $(wildcard c/*.c)
SRC_AS= $(wildcard assembly/*.asm)


OBJ_C= $(filter-out c/kernel.o , $(SRC_C:.c=.o))

#OK so why do we exclude kernel.o ? Because this one is the critical one it contains the 
#entry point of the C code. And so it will be called by the bootloader code witch expect it to 
#be at adress 0x7e00. In fact it expect the function entry() to be at this adress.

#If we don't do so it will be compiled like any C file and later be place somewhere by the linker
#and we don't want that because we want kernel.o to be placed at the very first place
#so entry function will be at 0x7e00

OBJ_AS= $(SRC_AS:.asm=.a.o)

all:sub_make yaoos

yaoos: linker/linker.ld assembly/bootloader/bootloader.img idt.a.o interupt.a.o
	@$(LINKER) $(LFLAGS) c/kernel.o $(OBJ_C) $(OBJ_AS)

    #This is what I explaine before. We simply tell the linker that "Ok compile all .o
    #files as you want and place them where you want BUT place kernel.o et the beginning"

	@printf "[$(GREEN)OK$(NC)] kernel.img\n"

 
	@cat assembly/bootloader/bootloader.img kernel.img > yaoos/yaoos.img
	@printf "[$(GREEN)OK$(NC)] yaoos.img before truncate\n"
	
	@truncate yaoos/yaoos.img -s 5120
	@printf "[$(GREEN)OK$(NC)] yaoos.img\n"


assembly/bootloader/bootloader.img: assembly/bootloader/bootloader.asm
	@nasm assembly/bootloader/bootloader.asm -f bin -o assembly/bootloader/bootloader.img
	@printf "[$(GREEN)OK$(NC)] bootloader.img.o\n"

#We just say take all .asm files and create .o file with the same name
%.a.o: assembly/%.asm
	@nasm $< -f elf -o assembly/$@ 
	@printf "[$(GREEN)OK$(NC)] $@\n"	

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

#that is to call the makefile in c/ directoy 
sub_make:
	$(MAKE) -C c/ all