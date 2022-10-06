#include "./gdt.hpp"
#include "./../modules/terminal.hpp"


/*void Chlorine::DescriptorTables::GlobalDescriptorTables::EncodeEntry(unsigned char *target, struct GDT source)
{
    if (source.limit > 0xFFFFF)
    {
        term.OutputToTerminal(5, "GlobalDescriptorTable cannot encode limits larger than 0xFFFFF\n\r");
    }
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0x0F;
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
    target[5] = source.access_byte;
    target[6] |= (source.flags << 4);
}*/