i686-elf-g++ -c ~/projects/os/temp/kernel.cpp -o ~/projects/os/temp/kernel.o -std=c++17 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
rm ~/projects/os/C++/iso/boot/kernel.elf
rm ~/projects/os/C++/betterthanpardus.iso
i686-elf-ld -m elf_i386 -T ~/projects/os/temp/linker.ld -o ~/projects/os/C++/iso/boot/kernel.elf ~/projects/os/temp/multiboot_header.o ~/projects/os/temp/kernel.o
grub-mkrescue -o ~/projects/os/C++/betterthanpardus.iso ~/projects/os/C++/iso
qemu-system-i386 -cdrom ~/projects/os/C++/betterthanpardus.iso
