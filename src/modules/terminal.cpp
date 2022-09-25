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

unsigned char Chlorine::Terminal::InputKeycodeToTerminal()
{
    return Chlorine::Keyboard::GetKeyboardInput();
}

char Chlorine::Terminal::InputCharacterToTerminal()
{
    return Chlorine::Utilities::ASCII::KeysToASCII(Chlorine::Keyboard::GetKeyboardInput());
}