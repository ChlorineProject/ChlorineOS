#include "./serial.hpp"
#include "./ioports.hpp"

#define PORT 0x3f8

int Chlorine::Serial::InitializeSerial()
{
    Chlorine::IOPorts::WriteByte(PORT + 1, 0x00);
    Chlorine::IOPorts::WriteByte(PORT + 3, 0x80);
    Chlorine::IOPorts::WriteByte(PORT + 0, 0x03);
    Chlorine::IOPorts::WriteByte(PORT + 1, 0x00);
    Chlorine::IOPorts::WriteByte(PORT + 3, 0x03);
    Chlorine::IOPorts::WriteByte(PORT + 2, 0xC7);
    Chlorine::IOPorts::WriteByte(PORT + 4, 0x0B);
    Chlorine::IOPorts::WriteByte(PORT + 4, 0x1E);
    Chlorine::IOPorts::WriteByte(PORT + 0, 0xAE);

    if (Chlorine::IOPorts::ReadByte(PORT + 0) != 0xAE)
    {
        return 1;
    }

    Chlorine::IOPorts::WriteByte(PORT + 4, 0x0F);
    return 0;
}

int Chlorine::Serial::SerialRecieved()
{
    return Chlorine::IOPorts::ReadByte(PORT + 5) & 1;
}

char Chlorine::Serial::ReadSerial()
{
    while (Chlorine::Serial::SerialRecieved() == 0);
    return Chlorine::IOPorts::ReadByte(PORT);
}

int Chlorine::Serial::IsTransmitEmpty()
{
    return Chlorine::IOPorts::ReadByte(PORT + 5) & 0x20;
}

void Chlorine::Serial::WriteSerial(char b185464587a40809a3d4f823f93a5ae9)
{
    while (Chlorine::Serial::IsTransmitEmpty() == 0);
    Chlorine::IOPorts::WriteByte(PORT, b185464587a40809a3d4f823f93a5ae9);
}