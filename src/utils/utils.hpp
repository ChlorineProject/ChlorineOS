#pragma once

namespace Chlorine
{
    namespace Utilities
    {
        namespace String
        {
            unsigned int GetLengthOfString(const char *String);
            int ConCat(int x, int y);
        }
        namespace ASCII
        {
            char KeysToASCII(unsigned char KeyCode);
        }
    }
}