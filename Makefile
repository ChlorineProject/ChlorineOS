build-x86:
	as --32 ./source/boot.s -o ./object/f992ec0de305adc5e40d477ce2e6c2a5.o
	g++ -m32 -c ./source/main.cpp -o ./object/76bd44161dfc527e683557b9611d9d66.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/drivers/ioports.cpp -o ./object/70c90fcd5712e5e32be5a993916994c5.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/drivers/serial.cpp -o ./object/7d5fc34168bb269a88ba84255f8352d0.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/utils/utils.cpp -o ./object/6d135c372090dca6ec96115f159b4036.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/drivers/screen.cpp -o ./object/6d135c372090dca6ec96115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/modules/process.cpp -o ./object/6d135c372090dca6ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/modules/memory.cpp -o ./object/6d135c372090dca7ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/modules/issues.cpp -o ./object/6d135c372090dca7ec24115f159b2049.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/modules/terminal.cpp -o ./object/6d135c372090dca7ec24115f189b2049.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./source/drivers/keyboard.cpp -o ./object/6d135c256090dca7ec24115f189b2049.o -ffreestanding -O2 -Wall -Wextra
	ld -m elf_i386 -T ./script/linker-x86.ld ./object/6d135c256090dca7ec24115f189b2049.o ./object/6d135c372090dca7ec24115f189b2049.o ./object/6d135c372090dca7ec24115f159b2049.o ./object/6d135c372090dca7ec24115f159b2048.o ./object/6d135c372090dca6ec96115f159b2048.o ./object/6d135c372090dca6ec24115f159b2048.o ./object/76bd44161dfc527e683557b9611d9d66.o ./object/6d135c372090dca6ec96115f159b4036.o ./object/7d5fc34168bb269a88ba84255f8352d0.o ./object/70c90fcd5712e5e32be5a993916994c5.o ./object/f992ec0de305adc5e40d477ce2e6c2a5.o -o ./output/chl.bin -nostdlib
	grub-file --is-x86-multiboot ./output/chl.bin
	mkdir -p iso/boot/grub
	cp ./output/chl.bin iso/boot/chl.bin
	cp ./script/grub-x86.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o ./output/chl.iso iso
	rm -r iso
test-x86:
	qemu-system-x86_64 -cdrom ./output/chl.iso