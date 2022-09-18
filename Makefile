build-x86:
	as --32 ./src/boot.s -o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o
	g++ -m32 -c ./src/main.cpp -o ./tmp/76bd44161dfc527e683557b9611d9d66.o -ffreestanding -O2 -Wall -Wextra
	g++ -m32 -c ./src/drivers/serial.cpp -o ./tmp/70c90fcd5712e5e32be5a993916994c5.o -ffreestanding -O2 -Wall -Wextra
	ld -m elf_i386 -T ./scr/linker-x86.ld ./tmp/76bd44161dfc527e683557b9611d9d66.o ./tmp/70c90fcd5712e5e32be5a993916994c5.o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o -o ./bin/chl.bin -nostdlib