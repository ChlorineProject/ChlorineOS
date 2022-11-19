#include "./drivers/serial.h"
#if ARCHITECTURE == 1
#include "./arch/i386/monitor.h"
#include "./arch/i386/dt.h"
#endif

void main()
{
    init_serial();
    #if ARCHITECTURE == 1
    monitor_write("Hello, world!\nLet's enable descriptor tables now...\n");
    init_descriptor_tables();
    monitor_write("Alright, we called `init_descriptor_tables`!\n");
    #endif
}