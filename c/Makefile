CC=gcc
CFLAGS = -ffreestanding -c -m32
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all:$(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $< 
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

rebuild: mrproper all	