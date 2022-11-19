#include "./serial.h"

#if ARCHITECTURE == 1
#include "./../arch/i386/ioports.h"
#endif

int init_serial()
{
    #if ARCHITECTURE == 1
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x80);
    outb(COM1_PORT + 0, 0x03);
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x03);
    outb(COM1_PORT + 2, 0xC7);
    outb(COM1_PORT + 4, 0x0B);
    outb(COM1_PORT + 4, 0x1E);
    outb(COM1_PORT + 0, 0xAE);

    if(inb(COM1_PORT + 0) != 0xAE)
    {
        return 1;
    }

    outb(COM1_PORT + 4, 0x0F);
    return 0;
    #endif
}

int serial_received()
{
    #if ARCHITECTURE == 1
    return inb(COM1_PORT + 5) & 1;
    #endif
}
 
char read_serial()
{
    #if ARCHITECTURE == 1
    while (serial_received() == 0);
    return inb(COM1_PORT);
    #endif
}

int is_transmit_empty()
{
    #if ARCHITECTURE == 1
    return inb(COM1_PORT + 5) & 0x20;
    #endif
}
 
void write_serial(char a)
{
    #if ARCHITECTURE == 1
    while (is_transmit_empty() == 0);
    outb(COM1_PORT, a);
    #endif
}