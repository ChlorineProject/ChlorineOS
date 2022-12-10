;  ChlorineOS - A work-in-progress operating system working to be
;               UNIX-like...
;
;  Copyright (C) 2022 Nexuss (https://github.com/Dashbloxx)
;
;  This program is free software: you can redistribute it and/or modify
;  it under the terms of the GNU General Public License as published by
;  the Free Software Foundation, either version 3 of the License, or
;  (at your option) any later version.
;
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU General Public License for more details.
;
;  You should have received a copy of the GNU General Public License
;  along with this program.  If not, see <https://www.gnu.org/licenses/>.

[GLOBAL gdt_flush] ; let's make the `gdt_flush` function accessible by our C code...

gdt_flush:
    mov eax, [esp+4]
    lgdt [eax]

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush
.flush:
    ret

[GLOBAL idt_flush] ; let's make the `idt_flush` function accessible by our C code...

idt_flush:
    mov eax, [esp+4]
    lidt [eax] ; let's pass the IDT table to the CPU!
    ret