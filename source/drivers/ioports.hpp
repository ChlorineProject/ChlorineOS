#pragma once

#include <stdint.h>

namespace Chlorine
{
    namespace IOPorts
    {
        void WriteByte(unsigned int port, unsigned char data);
        unsigned char ReadByte(unsigned int port);
        void WriteWord(unsigned int port, unsigned short int data);
        unsigned short int ReadWord(unsigned int port);
        void WriteInt(unsigned int port, unsigned int data);
        unsigned int ReadInt(unsigned int port);
    }
}