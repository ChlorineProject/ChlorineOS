/*
 *  First part of the ChlorineOS kernel. Once `boot.s` is ran, it will call the function `main()` which is below.
 */

#include "./main.hpp"
#include "./drivers/serial.hpp"
#include "./modules/terminal.hpp"
#include "./drivers/screen.hpp"

void main()
{
    Chlorine::Serial::InitializeSerial();
    Chlorine::Terminal term = Chlorine::Terminal(SERIAL_MODE);
    term.OutputToTerminal(5, "When you're sitting on the toilet and the credit card declines... sdfsadfafgasdkjhgfsakjhdfadshgfkfdsagkjhfdsakgjfdsagjhfdsakjhgfdsahgjkdsf");
}