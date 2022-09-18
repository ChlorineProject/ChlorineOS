#pragma once

namespace Chlorine
{
    namespace Serial
    {
        int InitializeSerial();
        int SerialRecieved();
        char ReadSerial();
        int IsTransmitEmpty();
        void WriteSerial(char);
    }
}