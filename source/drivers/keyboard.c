#include "./keyboard.h"

#if ARCHITECTURE == 1
#include "./../arch/i386/ioports.h"
#endif


/*
 *  This function will NOT return the character that is pressed on a keyboard. What this function returns, is the
 *  keycode of the key that is pressed...
 */
char input_keycode()
{
    char keycode = 0;
    #if ARCHITECTURE == 1
    while((keycode = inb(KEYBOARD_PORT)) != 0)
    {
        if(keycode > 0)
        {
            return keycode;
        }
    }
    #endif
    return keycode;
}
