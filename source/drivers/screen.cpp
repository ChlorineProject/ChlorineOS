#include "./screen.hpp"
#include "./../utils/utils.hpp"
#include "./ioports.hpp"
#include "./../modules/issues.hpp"
#include "./../main.hpp"

/*
 *  Section for text-mode related stuff
 *  Quotes from OSDev.org that may help:
 *      "For standard VGA video modes the video memory will be at address 0xA0000 for EGA/VGA video modes and 0xB8000 for CGA and text modes. To find out which one look at the following table: "
 */

volatile char *Video = (volatile char *)0xB8000;

void Chlorine::Screen::Text::WriteCharacter(int Color, char Character)
{
    /*
     *  Working on this function ngl idk how to turn WriteString() into WriteCharacter(), so
     *  I guess we will use serial as a terminal for now...
     */
    *Video++ = Chlorine::Utilities::String::ConCat(Color, Character);
}

void Chlorine::Screen::Text::WriteString(int Color, const char *String)
{
    /*
     *  For some reason, I can't have `volatile char* Video = (volatile char*)0xB8000;` outside of this function...
     */
    while (*String != 0)
    {
        *Video++ = *String++;
        *Video++ = Color;
    }
}

void Chlorine::Screen::Text::EnableCursor(unsigned char CursorStart, unsigned char CursorEnd)
{
    Chlorine::IOPorts::WriteByte(0x3D4, 0x0A);
	Chlorine::IOPorts::WriteByte(0x3D5, (Chlorine::IOPorts::ReadByte(0x3D5) & 0xC0) | CursorStart);
	Chlorine::IOPorts::WriteByte(0x3D4, 0x0B);
	Chlorine::IOPorts::WriteByte(0x3D5, (Chlorine::IOPorts::ReadByte(0x3D5) & 0xE0) | CursorEnd);
}

void Chlorine::Screen::Text::DisableCursor()
{
	Chlorine::IOPorts::WriteByte(0x3D4, 0x0A);
	Chlorine::IOPorts::WriteByte(0x3D5, 0x20);
}

void Chlorine::Screen::Text::UpdateCursor(int x, int y)
{
    if(VGA_WIDTH == 0)
    {
        //Chlorine::Issues::Error("There has been an error; the variable VGA_WIDTH cannot be set to 0. Shouldn't it be set to the corresponding width of the VGA text mode screen?", term);
    }
    else
    {
        unsigned short int pos = y * VGA_WIDTH + x;
        Chlorine::IOPorts::WriteByte(0x3D4, 0x0F);
        Chlorine::IOPorts::WriteByte(0x3D5, (unsigned char) (pos & 0xFF));
        Chlorine::IOPorts::WriteByte(0x3D4, 0x0E);
        Chlorine::IOPorts::WriteByte(0x3D5, (unsigned char) ((pos >> 8) & 0xFF));
    }
	
}

unsigned short int Chlorine::Screen::Text::GetCursorPosition()
{
    unsigned short int pos = 0;
    Chlorine::IOPorts::WriteByte(0x3D4, 0x0F);
    pos |= Chlorine::IOPorts::ReadByte(0x3D5);
    Chlorine::IOPorts::WriteByte(0x3D4, 0x0E);
    pos |= ((unsigned short int)Chlorine::IOPorts::ReadByte(0x3D5)) << 8;
    return pos;
}

void Chlorine::Screen::Gui::PutPixel(int x, int y, unsigned char VgaColor)
{
    unsigned char* location = (unsigned char*)0xA0000 + 320 * y + x;
    *location = VgaColor;
}