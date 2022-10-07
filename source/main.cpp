/*
 *  First part of the ChlorineOS kernel. Once `boot.s` is ran, it will call the function `main()` which is below.
 */

#include "./main.hpp"
#include "./drivers/serial.hpp"
#include "./modules/terminal.hpp"
#include "./drivers/screen.hpp"
#include "./utils/utils.hpp"
#include "./drivers/keyboard.hpp"

extern unsigned int _start;
extern unsigned int _end;

void main()
{
    Chlorine::Serial::InitializeSerial();
    Chlorine::Terminal term = Chlorine::Terminal(SERIAL_MODE);
    /*
     *  Let's go ahead, and print out our disclaimer regarding the license. Then, we can initialize a basic CLI (this will be
     *  a temporary CLI since its not shell-executable based).
     */
    term.OutputToTerminal(5, "ChlorineOS Copyright (C) 2022 ChlorineProject This program comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome to redistribute it under certain conditions.\n\r");
    /*
     *  Here we print out the version of ChlorineOS, which is defined in `main.hpp`. Pretty useless, but also a little helpful
     *  for knowing the age and how much the code of ChlorineOS has progressed.
     */
    term.OutputToTerminal(5, "Version: "); term.OutputToTerminal(5, VERSION); term.OutputToTerminal(5, "\n\r");
}