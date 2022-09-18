#pragma once

#include <stdint.h>

namespace Chlorine
{
    namespace Serial
    {
        void WriteByte(unsigned int port, uint8_t data);
        uint8_t ReadByte(unsigned int port);
        void WriteWord(unsigned int port, uint16_t data);
        uint16_t ReadWord(unsigned int port);
        void WriteInt(unsigned int port, uint32_t data);
        uint32_t ReadInt(unsigned int port);
    }
}