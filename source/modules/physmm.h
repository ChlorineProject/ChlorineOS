#ifndef HEADER_07b81840
#define HEADER_07b81840

#include <stdint.h>
#include <stddef.h>

typedef uint32_t PMM_PHYSICAL_ADDRESS;

#define PMM_BLOCK_SIZE 4096

typedef struct {
    uint32_t memory_size;
    uint32_t max_blocks;
    uint32_t *memory_map_array;
    uint32_t memory_map_end;
    uint32_t used_blocks;
} PMM_INFO;

uint32_t pmm_get_max_blocks();
uint32_t pmm_get_used_blocks();

int pmm_next_free_frame(int size);

void pmm_init(PMM_PHYSICAL_ADDRESS bitmap, uint32_t total_memory_size);

void pmm_init_region(PMM_PHYSICAL_ADDRESS base, uint32_t region_size);

void pmm_deinit_region(PMM_PHYSICAL_ADDRESS base, uint32_t region_size);

void* pmm_alloc_block();

void pmm_free_block(void* p);

void* pmm_alloc_blocks(uint32_t size);

void pmm_free_blocks(void* p, uint32_t size);

#endif