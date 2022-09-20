#include "./screen.hpp"
#include "./../utils/utils.hpp"

/*
 *  Section for text-mode related stuff
 */

void Chlorine::Screen::Text::WriteString(int Color, const char* String)
{
    /*
     *  For some reason, I can't have `volatile char* Video = (volatile char*)0xB8000;` outside of this function...
     *
     */
    volatile char* Video = (volatile char*)0xB8000;
    while(*String != 0)
    {
        *Video++ = *String++;
        *Video++ = Color;
    }
}