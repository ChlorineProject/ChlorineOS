#include <stdint.h>

#include "./paging.h"

extern uint32_t read_cr0();
extern void write_cr0();
extern uint32_t read_cr3();
extern void write_cr3();

void init_paging()
{
    unsigned long *page_directory = (unsigned long *) 0x9C000;
    unsigned long *page_table = (unsigned long *) 0x9D000;

    unsigned long address = 0;
    unsigned int i;

    for(i = 0; i < 1024; i++)
    {
        page_table[i] = address | 3;
        address = address + 4096;
    }

    page_directory[0] = page_table;
    page_directory[0] = page_directory[0] | 3;

    for(i = 1; i < 1024; i++)
    {
        page_directory[i] = 0 | 2;
    };

    write_cr3(page_directory);
    write_cr0(read_cr0() | 0x80000000);
}