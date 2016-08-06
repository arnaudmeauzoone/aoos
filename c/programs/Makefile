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

CC=gcc
CFLAGS = -ffreestanding -c -m32
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all:$(OBJ)

#We just say take all .c files and create .o file with the same name
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
