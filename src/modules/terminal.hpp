#pragma once

#define SERIAL_MODE 2
#define TEXT_MODE 1
#define NULL_MODE 0

namespace Chlorine
{
    class Terminal
    {
        /*
         *  TerminalType represents the type of terminal that is being used. Is the terminal running on text-mode, or is it running on a window in a graphical
         *  desktop?
         */
        unsigned char TerminalType = 0;
        public:
        Terminal(unsigned char TermType);
        /*
         *  Here, we can send a message to the terminal. Basically, this means sending input to a terminal.
         */
        void OutputToTerminal(int Color, const char* Message);
        /*
         *  Here, we can recieve from the terminal.
         */
        unsigned char InputKeycodeToTerminal();
        char InputCharacterToTerminal();
    };
}