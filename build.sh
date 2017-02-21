nasm -f elf32 kernel.asm -o kernel.o # Assemlber and Disassembler for intel x86 architecture kernel
gcc -m32 -c kernel.c -o kc.o #Compile the C files which contains the functions use within assembeler
ld -m elf_i386 -T link.ld -o OSiso/boot/kernel.bin kasm.o kc.o #Output is kernel.bin(Excecuable File) with inputs kasm.o kc.o, and the link.ld file created which describes how to object/c files are to be run
qemu-system-i386 -kernel OSiso/boot/kernel.bin &#Run the kernel.bin excecutable using qemu
grub-mkrescue /usr/lib/grub/i386-pc -o OS.iso OSiso/

read a



