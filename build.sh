nasm bootloader.asm -f bin -o bootloader.img
gcc -ffreestanding -c *.c -m32
ld -o kernel.img -T linker.ld kernel.o keyboard.o -m elf_i386 --oformat binary  -e 0x7c00
cat bootloader.img kernel.img > os.img
truncate os.img -s 5120

