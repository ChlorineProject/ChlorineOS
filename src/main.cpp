/*
 *  First part of the ChlorineOS kernel. Once `boot.s` is ran, it will call the function `main()` which is below.
 */

#include <string.h>

#include "./main.hpp"
#include "./drivers/serial.hpp"
#include "./modules/terminal.hpp"
#include "./drivers/screen.hpp"
#include "./utils/utils.hpp"
#include "./drivers/keyboard.hpp"

void main()
{
    Chlorine::Serial::InitializeSerial();
    Chlorine::Terminal term = Chlorine::Terminal(SERIAL_MODE);
    /*
     *  Let's go ahead, and print out our disclaimer regarding the license. Then, we can initialize a basic CLI (this will be
     *  a temporary CLI since its not shell-executable based).
     */
    term.OutputToTerminal(5, "ChlorineOS Copyright (C) 2022 ChlorineProject This program comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome to redistribute it under certain conditions.\n\r");
}