/*
 *  We'll need the serial driver here, because we will initialize the serial module.
 */
#include "./drivers/serial.h"
/*
 *  Let's now include all of the i386-compatible code, if we will even compile for i386 or i386-related architectures.
 */
#if ARCHITECTURE == 1
#include "./arch/i386/monitor.h"
#include "./arch/i386/dt.h"
#endif

/*
 *  This is the function that is called by `entry.asm`. The file `entry.asm` gets loaded by the GRUB bootloader, and
 *  that's how ChlorineOS gets loaded...
 */
void main()
{
    /*
     *  Let's initialize the serial driver (`drivers/serial.c` & `drivers/serial.h`)
     */
    init_serial();
    /*
     *  If we're using a i386-compatible operating system, then we shall initialize descriptor tables...
     */
    #if ARCHITECTURE == 1
    monitor_write("Hello, world!\nLet's enable descriptor tables now...\n");
    init_descriptor_tables();
    monitor_write("Alright, we called `init_descriptor_tables`!\n");
    #endif
}