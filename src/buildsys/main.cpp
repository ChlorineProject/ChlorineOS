#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if(argv[1] == "--compile-buildsys")
    {
        std::cout << "Detecting platform...\n";
        #if defined(_WIN32) || defined(_WIN64)
        std::cout << "Detected Windows...\n";
        int ret = system("gcc -o ./buildsys.exe ./src/buildsys/main.cpp");
        #elif defined(__unix__)
        std::cout << "Detected a UNIX-derivative...\n";
        int ret = system("gcc -o ./buildsys ./src/buildsys/main.cpp");
        #endif
        if(ret == 0)
        {
            std::cout << "Compilation successful!\n";
        }
        else
        {
            std::cerr << "Compilation failed, returned code " << ret << "\n";
        }
    }
    else if(argv[1] == "--compile-full-x86")
    {
        system("as --32 ./src/boot.s -o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o"
        "g++ -m32 -c ./src/main.cpp -o ./tmp/76bd44161dfc527e683557b9611d9d66.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/drivers/ioports.cpp -o ./tmp/70c90fcd5712e5e32be5a993916994c5.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/drivers/serial.cpp -o ./tmp/7d5fc34168bb269a88ba84255f8352d0.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/utils/utils.cpp -o ./tmp/6d135c372090dca6ec96115f159b4036.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/drivers/screen.cpp -o ./tmp/6d135c372090dca6ec96115f159b2048.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/modules/process.cpp -o ./tmp/6d135c372090dca6ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/modules/memory.cpp -o ./tmp/6d135c372090dca7ec24115f159b2048.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/modules/issues.cpp -o ./tmp/6d135c372090dca7ec24115f159b2049.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/modules/terminal.cpp -o ./tmp/6d135c372090dca7ec24115f189b2049.o -ffreestanding -O2 -Wall -Wextra"
        "g++ -m32 -c ./src/drivers/keyboard.cpp -o ./tmp/6d135c256090dca7ec24115f189b2049.o -ffreestanding -O2 -Wall -Wextra"
        "ld -m elf_i386 -T ./scr/linker-x86.ld ./tmp/6d135c256090dca7ec24115f189b2049.o ./tmp/6d135c372090dca7ec24115f189b2049.o ./tmp/6d135c372090dca7ec24115f159b2049.o ./tmp/6d135c372090dca7ec24115f159b2048.o ./tmp/6d135c372090dca6ec96115f159b2048.o ./tmp/6d135c372090dca6ec24115f159b2048.o ./tmp/76bd44161dfc527e683557b9611d9d66.o ./tmp/6d135c372090dca6ec96115f159b4036.o ./tmp/7d5fc34168bb269a88ba84255f8352d0.o ./tmp/70c90fcd5712e5e32be5a993916994c5.o ./tmp/f992ec0de305adc5e40d477ce2e6c2a5.o -o ./bin/chl.bin -nostdlib"
        "grub-file --is-x86-multiboot ./bin/chl.bin"
        "mkdir -p iso/boot/grub"
        "cp ./bin/chl.bin iso/boot/chl.bin"
        "cp ./scr/grub-x86.cfg iso/boot/grub/grub.cfg"
        "grub-mkrescue -o ./bin/chl.iso iso");
    }
    else if(argv[1] == "--test-full-x86")
    {
        system("qemu-system-x86_64 -cdrom ./bin/chl.iso");
    }
}