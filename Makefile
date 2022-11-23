menu:
	@echo "Not enough parameters! Try 'make kernel', 'make image' and then 'make test'..."
kernel:
ifeq ($(ARCHITECTURE), i386)
	nasm -f elf32 ./source/entry.asm -o ./object/f170bae7.o
	nasm -f elf32 ./source/arch/i386/dt.asm -o ./object/b15a50b3.o
	nasm -f elf32 ./source/arch/i386/int.asm -o ./object/b9dcbaa4.o
	gcc -m32 -c ./source/main.c -o ./object/3b17dcfb.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/modules/heap.c -o ./object/51983837.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/modules/physmm.c -o ./object/fccac3e9.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/arch/i386/ioports.c -o ./object/9709017e.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/arch/i386/monitor.c -o ./object/b162f378.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/arch/i386/dt.c -o ./object/8cf8fe6b.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/arch/i386/isr.c -o ./object/af1ad251.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	gcc -m32 -c ./source/drivers/serial.c -o ./object/4cd2bf5f.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	ld -m elf_i386 -T ./script/linker-i386.ld ./object/fccac3e9.o ./object/51983837.o ./object/b9dcbaa4.o ./object/b15a50b3.o ./object/af1ad251.o ./object/8cf8fe6b.o ./object/b162f378.o ./object/4cd2bf5f.o ./object/9709017e.o ./object/3b17dcfb.o ./object/f170bae7.o -o ./output/chl.bin -nostdlib
endif
image:
ifeq ($(ARCHITECTURE), i386)
	grub-file --is-x86-multiboot ./output/chl.bin
	mkdir -p iso/boot/grub
	cp ./output/chl.bin iso/boot/chl.bin
	cp ./script/grub-i386.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o ./output/chl.iso iso
	rm -r iso
endif
test:
ifeq ($(ARCHITECTURE), i386)
	qemu-system-x86_64 -cdrom ./output/chl.iso
endif