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
#include <stddef.h>

#include "./8259pic.h"

void init_8259pic()
{
    uint8_t a1, a2;
    a1 = outb(PIC1_DATA);
    a2 = outb(PIC2_DATA);
    outb(PIC1_COMMAND, ICW1);
    outb(PIC2_COMMAND, ICW1);
    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 0x28);
    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);
    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);
    outb(PIC1_DATA, a1);
    outb(PIC2_DATA, a2);
}

void pic8259_eoi(uint8_t irq)
{
    if(irq >= 0x28)
    {
        outb(PIC2, PIC_EOI);
    } 
    outb(PIC1, PIC_EOI);
}
