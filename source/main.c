/*
 *  ChlorineOS - A work-in-progress operating system working to be
 *               UNIX-like...
 *
 *  Copyright (C) 2022 Nexuss (https://github.com/Dashbloxx)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 *  We'll need the serial driver here, because we will initialize the serial module.
 */
#include "./drivers/serial.h"
/*
 *  Let's include `common.h` for the `printf` function!
 */
#include "./modules/common.h"
/*
 *  Let's include `fs.h` to create the root of our filesystem...
 */
#include "./modules/fs.h"
/*
 *  Let's now include all of the i386-compatible code, if we will even compile for i386 or i386-related architectures.
 */
#if ARCHITECTURE == 1
#include "./arch/i386/dt.h"
#endif

/*
 *  This is the function that is called by `entry.asm`. The file `entry.asm` gets loaded by the GRUB bootloader, and
 *  that's how ChlorineOS gets loaded...
 */
void main()
{
    /*
     *  Let's define some pointers that will map out the heap for ChlorineOS's kernel...
     */
    void *heap_start = (uint32_t)0x00E00000;
    void *heap_end = heap_start + 0x00100000;
    /*
     *  Let's initialize the serial driver (`drivers/serial.c` & `drivers/serial.h`)
     */
    printf("Initializing the serial module...\n");
    init_serial();
    /*
     *  If we're using a i386-compatible operating system, then we shall initialize descriptor tables...
     */
    #if ARCHITECTURE == 1
    printf("Initializing descriptor tables...\n");
    init_descriptor_tables();
    #endif
    printf("Initializing the heap...\n");
    /*
     *  Let's initialize the heap!
     */
    init_heap(heap_start, heap_end);
    /*
     *  Now that the heap is initialized, we can allocate memory, free it, etc. This allows us to create a memory-efficient
     *  kernel:
     *      | void *ptr = kmalloc(1024);
     *      | printf("Let's allocate 1024 bytes...\nThis is the pointer to the allocated memory: %d\n", ptr);
     *      | void *ptr2 = kmalloc(1024);
     *      | printf("Let's allocate 1024 more bytes...\nThis is the pointer to the allocated memory: %d\n", ptr2);
     */
    /*
     *  Let's setup the 8259 PIC (Programmable Interrupt Controller)
     */
    #if ARCHITECTURE == 1
    printf("Initializing 8259 PIC...\n");
    init_8259pic();
    #endif
}