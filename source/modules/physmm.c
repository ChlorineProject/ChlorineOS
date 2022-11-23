#include <stdint.h>
#include <stddef.h>

#include "./physmm.h"
#include "./common.h"

static PMM_INFO g_pmm_info;

static inline void pmm_mmap_set(int bit)
{
    g_pmm_info.memory_map_array[bit / 32] |= (1 << (bit % 32));
}

static inline void pmm_mmap_unset(int bit)
{
    g_pmm_info.memory_map_array[bit / 32] &= ~(1 << (bit % 32));
}

static inline char pmm_mmap_test(int bit)
{
    return g_pmm_info.memory_map_array[bit / 32] & (1 << (bit % 32));
}

uint32_t pmm_get_max_blocks()
{
    return g_pmm_info.max_blocks;
}

uint32_t pmm_get_used_blocks()
{
    return g_pmm_info.used_blocks;
}

int pmm_mmap_first_free()
{
    uint32_t i, j;

    for (i = 0; i < g_pmm_info.max_blocks; i++) {
        if (g_pmm_info.memory_map_array[i] != 0xffffffff) {
            for (j = 0; j < 32; j++) {
                int bit = 1 << j;
                if (!(g_pmm_info.memory_map_array[i] & bit))
                    return i * 32 + j;
            }
        }
    }
    return -1;
}

int pmm_mmap_first_free_by_size(uint32_t size)
{
    uint32_t i, j, k, free = 0;
    int bit;

    if (size == 0)
        return -1;

    if (size == 1)
        return pmm_mmap_first_free();

    for (i = 0; i < g_pmm_info.max_blocks; i++)
    {
        if (g_pmm_info.memory_map_array[i] != 0xffffffff)
        {
            for (j = 0; j < 32; j++) {
                bit = 1 << j;
                if (!(g_pmm_info.memory_map_array[i] & bit))
                {
                    for (k = j; k < 32; k++)
                    {
                        bit = 1 << k;
                        if (!(g_pmm_info.memory_map_array[i] & bit))
                            free++;
                        
                        if (free == size)
                            return i * 32 + j;
                    }
                }
            }
        }
    }
    return -1;
}

int pmm_next_free_frame(int size)
{
    return pmm_mmap_first_free_by_size(size);
}

void pmm_init(PMM_PHYSICAL_ADDRESS bitmap, uint32_t total_memory_size)
{
    g_pmm_info.memory_size = total_memory_size;
    g_pmm_info.memory_map_array = (uint32_t *)bitmap;
    g_pmm_info.max_blocks = total_memory_size / PMM_BLOCK_SIZE;
    g_pmm_info.used_blocks = g_pmm_info.max_blocks;
    memset(g_pmm_info.memory_map_array, 0xff, g_pmm_info.max_blocks * sizeof(uint32_t));
    g_pmm_info.memory_map_end = (uint32_t)&g_pmm_info.memory_map_array[g_pmm_info.max_blocks];
}

void pmm_init_region(PMM_PHYSICAL_ADDRESS base, uint32_t region_size)
{
    int align = base / PMM_BLOCK_SIZE;
    int blocks = region_size / PMM_BLOCK_SIZE;
    while (blocks >= 0) {
        pmm_mmap_unset(align++);
        g_pmm_info.used_blocks--;
        blocks--;
    }
}

void pmm_deinit_region(PMM_PHYSICAL_ADDRESS base, uint32_t region_size)
{
    int align = base / PMM_BLOCK_SIZE;
    int blocks = region_size / PMM_BLOCK_SIZE;

    while (blocks >= 0) {
        pmm_mmap_set(align++);
        g_pmm_info.used_blocks++;
        blocks--;
    }
}


void* pmm_alloc_block()
{
    if ((g_pmm_info.max_blocks - g_pmm_info.used_blocks) <= 0)
        return NULL;

    int frame = pmm_mmap_first_free();
    if (frame == -1)
        return NULL;

    pmm_mmap_set(frame);

    PMM_PHYSICAL_ADDRESS addr = (frame * PMM_BLOCK_SIZE) + g_pmm_info.memory_map_end;
    g_pmm_info.used_blocks++;

    return (void *)addr;
}

void pmm_free_block(void* p)
{
    PMM_PHYSICAL_ADDRESS addr = (PMM_PHYSICAL_ADDRESS)p;
    addr -= g_pmm_info.memory_map_end;
    int frame = addr / PMM_BLOCK_SIZE;
    pmm_mmap_unset(frame);
    g_pmm_info.used_blocks--;
}

void* pmm_alloc_blocks(uint32_t size)
{
    uint32_t i;

    if ((g_pmm_info.max_blocks - g_pmm_info.used_blocks) <= size)
        return NULL;

    int frame = pmm_mmap_first_free_by_size(size);
    if (frame == -1)
        return NULL;
    for (i = 0; i < size; i++)
        pmm_mmap_set(frame + i);

    PMM_PHYSICAL_ADDRESS addr = (frame * PMM_BLOCK_SIZE) + g_pmm_info.memory_map_end;
    g_pmm_info.used_blocks += size;

    return (void *)addr;
}

void pmm_free_blocks(void* p, uint32_t size)
{
    uint32_t i;
    PMM_PHYSICAL_ADDRESS addr = (PMM_PHYSICAL_ADDRESS)p;
    addr -= g_pmm_info.memory_map_end;
    int frame = addr / PMM_BLOCK_SIZE;
    for (i = 0; i < size; i++)
        pmm_mmap_unset(frame + i);
    g_pmm_info.used_blocks -= size;
}