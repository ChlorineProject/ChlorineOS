menu:
	@echo "Not enough parameters! Try 'make kernel', 'make image' and then 'make test'..."
kernel:
ifeq ($(ARCHITECTURE), i386)
	i386-elf-as ./source/arch/i386/bootstrap.S -o ./object/3b17dcfg.o
	i386-elf-gcc -c ./source/main.c -o ./object/3b17dcfb.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/modules/common.c -o ./object/680cf526.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/modules/fs.c -o ./object/f0cba9bf.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/modules/heap.c -o ./object/51983837.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/arch/i386/ioports.c -o ./object/9709017e.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/arch/i386/8259pic.c -o ./object/131ce24b.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/arch/i386/monitor.c -o ./object/b162f378.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/drivers/serial.c -o ./object/4cd2bf5f.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -c ./source/drivers/keyboard.c -o ./object/4cd5bf5f.o -ffreestanding -O2 -Wall -Wextra -DARCHITECTURE=1
	i386-elf-gcc -T ./script/linker-i386.ld -o ./output/chl.bin -ffreestanding -O2 -nostdlib ./object/3b17dcfg.o ./object/4cd5bf5f.o ./object/3b17dcfb.o ./object/4cd2bf5f.o ./object/680cf526.o ./object/f0cba9bf.o ./object/51983837.o ./object/9709017e.o ./object/131ce24b.o ./object/b162f378.o -lgcc
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