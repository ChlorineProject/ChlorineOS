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

#ifndef HEADER_f8552ff7
#define HEADER_f8552ff7

#include <stdint.h>
#include <stddef.h>

typedef struct _kheap_block {
    struct {
        uint32_t size;
        uint8_t is_free;
    } metadata;
    struct _kheap_block *next; 
    void *data;
} __attribute__((packed)) kheap_block_t;

int init_heap(void *start_addr, void *end_addr);

void *kbrk(int size);

void kheap_print_blocks();

void *kmalloc(int size);

void *kcalloc(int n, int size);

void *krealloc(void *ptr, int size);

void kfree(void *addr);

#endif