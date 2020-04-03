#pragma once

#include "mzcrt.h"

mzcrt_inline int mzcrt_memcmp(const void *p1, const void *p2, size_t size)
{
    const unsigned char *a = p1, *b = p2;
    size_t i;
    for (i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            return a[i] - b[i];
    }
    return 0;
}

mzcrt_inline void *mzcrt_memcpy(void *dst, const void *src, size_t size)
{
    char *d = dst;
    const char *s = src;
    size_t i;
    for (i = 0; i < size; i++)
    {
        d[i] = s[i];
    }
    return dst;
}

mzcrt_inline void *mzcrt_memset(void *ptr, int value, size_t size)
{
    char *p = ptr;
    size_t i;
    for (i = 0; i < size; i++)
        p[i] = (char)value;
    return ptr;
}

mzcrt_inline void *mzcrt_memchr(const void *addr, char byte, size_t n)
{
    const char *ptr;
    for (ptr = addr; n--; ++ptr)
    {
        if (*ptr == byte)
            return (void *)ptr;
    }
    return NULL;
}

#undef memchr
#undef memcmp
#undef memcpy
#undef memset

#define memchr mzcrt_memchr
#define memcmp mzcrt_memcmp
#define memcpy mzcrt_memcpy
#define memset mzcrt_memset
