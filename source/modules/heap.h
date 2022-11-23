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
} __attribute__((packed)) KHEAP_BLOCK;

int kheap_init(void *start_addr, void *end_addr);

void *kbrk(int size);

void kheap_print_blocks();

void *kmalloc(int size);

void *kcalloc(int n, int size);

void *krealloc(void *ptr, int size);

void kfree(void *addr);

#endif