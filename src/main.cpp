/*
 *  First part of the ChlorineOS kernel. Once `boot.s` is ran, it will call the function `main()` which is below.
 */

#include "./drivers/ioports.hpp"
#include "./drivers/serial.hpp"
#include "./utils/utils.hpp"
#include "./drivers/screen.hpp"

void main()
{
    Chlorine::Serial::InitializeSerial();
    Chlorine::Screen::Text::WriteString(15, "Initialized Serial!");
}