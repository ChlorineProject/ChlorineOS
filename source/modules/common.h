#ifndef HEADER_9bf9d71e
#define HEADER_9bf9d71e

#include <stdint.h>
#include <stddef.h>

void *memcpy(void *dst, const void *src, uint32_t n);
void memset(void* str, char ch, size_t n);
void itoa(char *buf, int base, int d);
void printf(const char *format, ...);
char* strcpy(char* destination, const char* source);

#endif