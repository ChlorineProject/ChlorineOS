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