#include <stdint.h>

#include "./ioports.h"

void outb(unsigned int port, unsigned char data)
{
    asm volatile("outb %b0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint8_t inb(unsigned int port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}

void outw(unsigned int port, unsigned short int data)
{
    asm volatile("outw %w0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint16_t inw(unsigned int port)
{
    uint16_t data;
    asm volatile("inw %w1, %w0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}

void outl(unsigned int port, unsigned int data)
{
    asm volatile("outl %0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint32_t inl(unsigned int port)
{
    uint32_t data;
    asm volatile("inl %w1, %0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}