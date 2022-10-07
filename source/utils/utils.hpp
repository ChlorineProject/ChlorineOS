#pragma once

namespace Chlorine
{
    namespace Utilities
    {
        namespace String
        {
            unsigned int GetLengthOfString(const char *String);
            void NumberToString(int num, char *number);
            int ConCat(int x, int y);
        }
        namespace Number
        {
            unsigned int DigitCount(int num);
        }
        namespace ASCII
        {
            char KeysToASCII(unsigned char KeyCode);
        }
        namespace Types
        {
            
        }
    }
}