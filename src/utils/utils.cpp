#include "./utils.hpp"

unsigned int Chlorine::Utilities::String::GetLengthOfString(const char *String)
{
    unsigned int Count = 0;
    while (*String != '\0')
    {
        Count++;
        String++;
    }
    return Count;
}

int Chlorine::Utilities::String::ConCat(int x, int y)
{
    10 * x + y;
}