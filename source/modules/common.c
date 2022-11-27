#include <stddef.h>
#include <stdint.h>

#include "./common.h"
#if ARCHITECTURE == 1
#include "./../arch/i386/monitor.h"
#endif

void *memcpy(void *dst, const void *src, uint32_t n)
{
    char *ret = dst;
    char *p = dst;
    const char *q = src;
    while (n--)
    {
        *p++ = *q++;
    }
    return ret;
}

void memset(void* str, char ch, size_t n)
{
	int i;
	char *s = (char*) str;
	for(i=0; i<n; i++)
    {
        s[i]=ch;
    }
}

void itoa(char *buf, int base, int d)
{
    char *p = buf;
    char *p1, *p2;
    unsigned long ud = d;
    int divisor = 10;
    if (base == 'd' && d < 0)
    {
        *p++ = '-';
        buf++;
        ud = -d;
    }
    else if (base == 'x')
    {
        divisor = 16;
    } 
    do
    {
        int remainder = ud % divisor;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    }
    while (ud /= divisor);
    *p = 0;
    p1 = buf;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
}

void printf(const char *format, ...)
{
    char **arg = (char **)&format;
    int c;
    char buf[32];
    arg++;
    memset(buf, 0, sizeof(buf));
    while ((c = *format++) != 0)
    {
        if (c != '%')
        {
            #if ARCHITECTURE == 1
            monitor_put(c);
            #endif
        }
        else
        {
            char *p, *p2;
            int pad0 = 0, pad = 0;
            c = *format++;
            if (c == '0')
            {
                pad0 = 1;
                c = *format++;
            }
            if (c >= '0' && c <= '9')
            {
                pad = c - '0';
                c = *format++;
            }
            switch (c)
            {
                case 'd':
                case 'u':
                case 'x':
                    itoa(buf, c, *((int *)arg++));
                    p = buf;
                    goto string;
                    break;

                case 's':
                    p = *arg++;
                    if (!p)
                        p = "(null)";

                string:
                    for (p2 = p; *p2; p2++)
                        ;
                    for (; p2 < p + pad; p2++)
                        #if ARCHITECTURE == 1
                        monitor_put(pad0 ? '0' : ' ');
                        #endif
                    while (*p)
                        #if ARCHITECTURE == 1
                        monitor_put(*p++);
                        #endif
                    break;

                default:
                    #if ARCHITECTURE == 1
                    monitor_put(*((int *)arg++));
                    #endif
                    break;
            }
        }
    }
}

char* strcpy(char* destination, const char* source)
{
    if (destination == 0)
    {
        return 0;
    }
    char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}