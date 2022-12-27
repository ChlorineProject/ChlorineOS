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

#include <stddef.h>
#include <stdbool.h>

#include "./common.h"
#include "./heap.h"

void *g_kheap_start_addr = NULL, *g_kheap_end_addr = NULL;
unsigned long g_total_size = 0;
unsigned long g_total_used_size = 0;

kheap_block_t *g_head = NULL;

int init_heap(void *start_addr, void *end_addr)
{
    if (start_addr > end_addr)
    {
        printf("[CHL]: Failed to initialize heap...\n");
        return -1;
    }
    g_kheap_start_addr = start_addr;
    g_kheap_end_addr = end_addr;
    g_total_size = end_addr - start_addr;
    g_total_used_size = 0;
    return 0;
}

void *kbrk(int size)
{
    void *addr = NULL;
    if (size <= 0)
    {
        return NULL;
    }
    if ((int)(g_total_size - g_total_used_size) <= size)
    {
        return NULL;
    }
    addr = g_kheap_start_addr + g_total_used_size + size + sizeof(void *);
    g_total_used_size += size + sizeof(void *);
    return addr;
}

void kheap_print_blocks()
{
    kheap_block_t *temp = g_head;
    printf("Block Size: %d\n", sizeof(kheap_block_t));
    while (temp != NULL)
    {
        printf("size:%d, free:%d, data: 0x%x, curr: 0x%x, next: 0x%x\n", temp->metadata.size, temp->metadata.is_free, temp->data, temp, temp->next); temp = temp->next;
    }
}

bool is_block_free(kheap_block_t *block)
{
    if (!block)
    {
        return false;
    }   
    return (block->metadata.is_free == true);
}

kheap_block_t *worst_fit(int size)
{
    kheap_block_t *temp = g_head;
    while (temp != NULL)
    {
        if (is_block_free(temp))
        {
            if ((int)temp->metadata.size >= size)
            {
                return temp;
            }
        }
        temp = temp->next;
    }
    return NULL;
}

kheap_block_t *allocate_new_block(int size)
{
    kheap_block_t *temp = g_head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    kheap_block_t *new_block = (kheap_block_t *)kbrk(sizeof(kheap_block_t));
    new_block->metadata.is_free = false;
    new_block->metadata.size = size;
    new_block->data = kbrk(size);
    new_block->next = NULL;
    temp->next = new_block;
    return new_block;
}

void *kmalloc(int size)
{
    if (size <= 0)
    {
        return NULL;
    }
    if (g_head == NULL)
    {
        g_head = (kheap_block_t *)kbrk(sizeof(kheap_block_t));
        g_head->metadata.is_free = false;
        g_head->metadata.size = size;
        g_head->next = NULL;
        g_head->data = kbrk(size);
        return g_head->data;
    }
    else
    {
        kheap_block_t *worst = worst_fit(size);
        if (worst == NULL)
        {
            kheap_block_t *new_block = allocate_new_block(size);
            new_block->metadata.is_free = false;
            new_block->metadata.size = size;
            new_block->data = kbrk(size);
            return new_block->data;
        }
        else
        {
            worst->metadata.is_free = false;
            return worst->data;
        }
    }
    return NULL;
}

void *kcalloc(int n, int size)
{
    if (n < 0 || size < 0)
    {
        return NULL;
    }
    void *mem = kmalloc(n * size);
    memset(mem, 0, n * size);
    return mem;
}

void *krealloc(void *ptr, int size)
{
    kheap_block_t *temp = g_head;
    while (temp != NULL) 
    {
        if (temp->data == ptr)
        {
            kheap_block_t *new_block = allocate_new_block(size);
            if ((int)temp->metadata.size > size)
            {
                memcpy(new_block->data, ptr, size);
            }
            else
            {
                memcpy(new_block->data, ptr, temp->metadata.size);
            }
            temp->metadata.is_free = true;
            return new_block->data;
        }
        temp = temp->next;
    }
    return NULL;
}

void kfree(void *addr)
{
    kheap_block_t *temp = g_head;
    while (temp != NULL)
    {
        if (temp->data == addr)
        {
            temp->metadata.is_free = true;
            return;
        }
        temp = temp->next;
    }
}