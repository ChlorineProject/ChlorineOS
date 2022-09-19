#include "./screen.hpp"
#include "./../utils/utils.hpp"

/*
 *  Section for text-mode related stuff
 */

volatile char *Chlorine::Screen::Text::Video = (volatile char*)0xB8000;

void Chlorine::Screen::Text::WriteString(int color, const char *string)
{
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = color;
    }
}

/*
 *  Section for GUI related stuff (video-mode)
 *  Currently work-in-progress
 */

unsigned char *Chlorine::Screen::Gui::VGA = (unsigned char *)0xA0000000L;
unsigned char *Chlorine::Screen::Gui::DblBuffer;

void Chlorine::Screen::Gui::UpdateScreen()
{
    memcpy(Chlorine::Screen::Gui::VGA, Chlorine::Screen::Gui::DblBuffer, (unsigned int)(Chlorine::Screen::Gui::Width * Chlorine::Screen::Gui::Height));
}