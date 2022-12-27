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

#include <stdint.h>

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
 *  Let's include `8259pic.h` to be able to initialize 8259 PIC...
 */
#if ARCHITECTURE == 1
#include "./arch/i386/8259pic.h"
#endif
/*
 *  Let's include `heap.h` to include the heap module...
 */
#include "./modules/heap.h"

/*
 *  Here are the markers that state the start and the end of the kernel...
 */
extern char _start;
extern char _end;

/*
 *  This is the function that is called by `bootstrap.S`. The file `bootstrap.S` gets loaded by the GRUB bootloader, and
 *  that's how ChlorineOS gets loaded...
 */
void main()
{
    /*
     *  Let's initialize the serial driver...
     */
    printf("Initializing the serial module...\n");
    init_serial();

    /*
     *  Let's setup the 8259 PIC (Programmable Interrupt Controller)
     */
    #if ARCHITECTURE == 1
    printf("Initializing 8259 PIC...\n");
    init_8259pic();
    #endif

    /*
     *  Let's initialize the allocator...
     *
     *  Later, we'll find a way to get the address of the end of physical memory so that we can be able
     *  to allocate as much memory as possible. For now, only 1GB of RAM is accessible...
     */
    init_heap(&_end, &_end + 1073741824);
    void * pointer0 = kmalloc(1024);
    void * pointer1 = kmalloc(1024);
    printf("Allocated 1024 bytes of memory. The start address of this memory is: %d\nAllocated 1024 more bytes of memory.\nThe start address of this new allocated memory is: %d\n", &pointer0, &pointer1);
}