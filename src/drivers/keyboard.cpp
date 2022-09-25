#include "./keyboard.hpp"
#include "./ioports.hpp"

#define KEYBOARD_PORT 0x60

unsigned char Chlorine::Keyboard::GetKeyboardInput()
{
    char ch = 0;
    while ((ch = Chlorine::IOPorts::ReadByte(KEYBOARD_PORT)) != 0)
    {
        if (ch > 0)
        {
            return ch;
        }
    }
    return ch;
}