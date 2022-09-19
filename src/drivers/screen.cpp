#include "./screen.hpp"

void Chlorine::Screen::Text::WriteString(int color, const char *string)
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}