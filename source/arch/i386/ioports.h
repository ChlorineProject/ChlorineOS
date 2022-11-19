#ifndef HEADER_00a455f1
#define HEADER_00a455f1

#include <stdint.h>

void outb(unsigned int port, unsigned char data);
uint8_t inb(unsigned int port);
void outw(unsigned int port, unsigned short int data);
uint16_t inw(unsigned int port);
void outl(unsigned int port, unsigned int data);
uint32_t inl(unsigned int port);

#endif