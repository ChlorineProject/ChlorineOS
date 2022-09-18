#include <stdint.h>
#include "./serial.hpp"

void Chlorine::Serial::WriteByte(unsigned int port, uint8_t data)
{
    asm volatile("outb %b0, %w1" : : "a" (data), "Nd" (port));
}

uint8_t Chlorine::Serial::ReadByte(unsigned int port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0" : "=a" (data) : "Nd" (port));
    return data;
}

void Chlorine::Serial::WriteWord(unsigned int port, uint16_t data)
{
    asm volatile("outw %w0, %w1" : : "a" (data), "Nd" (port));
}

uint16_t Chlorine::Serial::ReadWord(unsigned int port)
{
    uint16_t data;
    asm volatile("inw %w1, %w0" : "=a" (data) : "Nd" (port));
    return data;
}

void Chlorine::Serial::WriteInt(unsigned int port, uint32_t data)
{
    asm volatile("outl %0, %w1" : : "a" (data), "Nd" (port));
}

uint32_t Chlorine::Serial::ReadInt(unsigned int port)
{
    uint32_t data;
    asm volatile("inl %w1, %0" : "=a" (data) : "Nd" (port));
    return data;
}