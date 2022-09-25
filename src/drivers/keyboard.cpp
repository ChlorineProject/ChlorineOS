#include "./keyboard.hpp"
#include "./ioports.hpp"

#define KEYBOARD_PORT 0x60

/*
 *  Useful for returning the keycode of a key that is pressed. You can later combine this function with the
 *  function `Chlorine::Utilities::ASCII::KeysToASCII` to get the character that was pressed in the keyboard.
 */
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