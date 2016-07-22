nasm assembly/bootloader.asm -f bin -o assembly/bootloader.img
gcc -ffreestanding -c c/kernel.c c/timer.c c/keyboard.c -m32
ld -o kernel.img -T linker/linker.ld kernel.o timer.o keyboard.o -m elf_i386 --oformat binary  -e 0x7c00
cat assembly/bootloader.img kernel.img > yaoos/yaoos.img
truncate yaoos/yaoos.img -s 5120

rm *.o
rm *.img 
rm assembly/bootloader.img

