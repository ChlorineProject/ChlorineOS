#include "./ioports.hpp"

void Chlorine::IOPorts::WriteByte(unsigned int port, unsigned char data)
{
    asm volatile("outb %b0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint8_t Chlorine::IOPorts::ReadByte(unsigned int port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}

void Chlorine::IOPorts::WriteWord(unsigned int port, unsigned short int data)
{
    asm volatile("outw %w0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint16_t Chlorine::IOPorts::ReadWord(unsigned int port)
{
    uint16_t data;
    asm volatile("inw %w1, %w0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}

void Chlorine::IOPorts::WriteInt(unsigned int port, unsigned int data)
{
    asm volatile("outl %0, %w1"
                 :
                 : "a"(data), "Nd"(port));
}

uint32_t Chlorine::IOPorts::ReadInt(unsigned int port)
{
    uint32_t data;
    asm volatile("inl %w1, %0"
                 : "=a"(data)
                 : "Nd"(port));
    return data;
}