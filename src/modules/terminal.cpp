#include "./terminal.hpp"
#include "./../drivers/screen.hpp"
#include "./../drivers/serial.hpp"
#include "./../drivers/keyboard.hpp"
#include "./../utils/utils.hpp"

Chlorine::Terminal::Terminal(unsigned char TermType)
{
    Chlorine::Terminal::TerminalType = TermType;
}

void Chlorine::Terminal::OutputToTerminal(int Color, const char* Message)
{
    if(Chlorine::Terminal::TerminalType == TEXT_MODE)
    {
        for(int i = 0; i<= Chlorine::Utilities::String::GetLengthOfString(Message); i++)
        {
            Chlorine::Screen::Text::WriteCharacter(Color, Message[i]);
        }
    }
    else if(Chlorine::Terminal::TerminalType == SERIAL_MODE)
    {
        for(int i = 0; i <= Chlorine::Utilities::String::GetLengthOfString(Message); i++)
        {
            Chlorine::Serial::WriteSerial(Message[i]);
        }
    }
}

/*
 *  Returns the keycode of the key that is pressed in the terminal.
 */
unsigned char Chlorine::Terminal::InputKeycodeToTerminal()
{
    return Chlorine::Keyboard::GetKeyboardInput();
}

/*
 *  Reads a the key that is pressed on a terminal, then it returns it's character value, if the key
 *  even represents a character.
 */
char Chlorine::Terminal::InputCharacterToTerminal()
{
    return Chlorine::Utilities::ASCII::KeysToASCII(Chlorine::Keyboard::GetKeyboardInput());
}