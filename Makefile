build-x86:
	as --32 ./src/boot.s -o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o
	g++ -m32 -c ./src/main.cpp -o ./tmp/76bd44161dfc527e683557b9611d9d66.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/drivers/ioports.cpp -o ./tmp/70c90fcd5712e5e32be5a993916994c5.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/drivers/serial.cpp -o ./tmp/7d5fc34168bb269a88ba84255f8352d0.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/utils/utils.cpp -o ./tmp/6d135c372090dca6ec96115f159b4036.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/drivers/screen.cpp -o ./tmp/6d135c372090dca6ec96115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/modules/process.cpp -o ./tmp/6d135c372090dca6ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/modules/memory.cpp -o ./tmp/6d135c372090dca7ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra
	ld -m elf_i386 -T ./scr/linker-x86.ld ./tmp/6d135c372090dca7ec24115f159b2048.o ./tmp/6d135c372090dca6ec96115f159b2048.o ./tmp/6d135c372090dca6ec24115f159b2048.o ./tmp/76bd44161dfc527e683557b9611d9d66.o ./tmp/6d135c372090dca6ec96115f159b4036.o ./tmp/7d5fc34168bb269a88ba84255f8352d0.o ./tmp/70c90fcd5712e5e32be5a993916994c5.o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o -o ./bin/chl.bin -nostdlib
	grub-file --is-x86-multiboot ./bin/chl.bin
	mkdir -p iso/boot/grub
	cp ./bin/chl.bin iso/boot/chl.bin
	cp ./scr/grub-x86.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o ./bin/chl.iso iso
test-x86:
	qemu-system-x86_64 -cdrom ./bin/chl.iso