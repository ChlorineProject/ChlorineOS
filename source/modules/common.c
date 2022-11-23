#include <stddef.h>

#include "./common.h"

void memset(void* str, char ch, size_t n)
{
	int i;
	char *s = (char*) str;
	for(i=0; i<n; i++)
    {
        s[i]=ch;
    }
}