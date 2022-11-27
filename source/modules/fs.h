#ifndef HEADER_dbbeeaa6
#define HEADER_dbbeeaa6

#include "./../main.h"

/*
 *  Our filesystem will contain a pointer to the exact start of the file's contents, a number that contains the size of the file (to
 *  know the pointer to the end of the file's contents), and a variable that tells us if the file is stored in RAM, or in a specific
 *  storage device.
 */

typedef struct fs_node
{
    char path[512]; /* Contains the path to the file, aswell as the name of the file... */
#if BITS == 32
    uint32_t file_content_ptr; /* If file_content_ptr is set to 0/NULL, then we consider it as a directory... */
    uint32_t file_size; /* Make sure to set file_size to 0 if you're making a directory aswell... */
    int32_t device; /* If device is equal to 0, the file's contents are stored in RAM. Set device to -1 if you're making a directory. */
#else-if BITS == 64
    uint64_t file_content_ptr; /* If file_content_ptr is set to 0/NULL, then we consider it as a directory... */
    uint64_t file_size; /* Make sure to set file_size to 0 if you're making a directory aswell... */
    int64_t device; /* If device is equal to 0, the file's contents are stored in RAM. Set device to -1 if you're making a directory. */
#endif
} fs_node_t;

#endif