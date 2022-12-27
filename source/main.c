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
 *  Let's include `8259pic.h` to be able to initialize 8259 PIC...
 */
#if ARCHITECTURE == 1
#include "./arch/i386/8259pic.h"
#endif

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
}