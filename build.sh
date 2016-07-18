nasm bootloader.asm -f bin -o bootloader.img &&
gcc -ffreestanding -c kernel.c -o kernel.o -m32 &&
ld -o kernel.img -Ttext 0x7e00 kernel.o -m elf_i386 --oformat binary  -e 0x7c00 &&
cat bootloader.img kernel.img > os.img &&
truncate os.img -s 5120

