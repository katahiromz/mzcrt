#pragma once

#include "mzcrt.h"
#include "mzmem.h"
#include "mzctype.h"

mzcrt_inline size_t mzcrt_strlen(const char *s)
{
    size_t i;
    for (i = 0; s[i]; i++)
    {
        ;
    }
    return i;
}

mzcrt_inline char *mzcrt_strcpy(char *dst, const char *src)
{
    size_t i;
    for (i = 0; src[i]; i++)
        dst[i] = src[i];
    return dst;
}

mzcrt_inline char *mzcrt_strcat(char *dst, const char *src)
{
    size_t len;
    len = mzcrt_strlen(dst);
    mzcrt_strcpy(dst + len, src);
    return dst;
}

mzcrt_inline char *mzcrt_strstr(const char *s, const char *t)
{
    size_t tlen = mzcrt_strlen(t);
    for (; *s; ++s)
    {
        if (mzcrt_memcmp(s, t, tlen) == 0)
            return (char *)s;
    }
    return NULL;
}

mzcrt_inline char *mzcrt_strlwr(char *str)
{
    char *ret = str;
    for (; *str; str++)
    {
        if ('A' <= *str && *str <= 'Z')
            *str += 'a' - 'A';
    }
    return ret;
}

mzcrt_inline char *mzcrt_strupr(char *str)
{
    char *ret = str;
    for (; *str; ++str)
    {
        if ('a' <= *str && *str <= 'z')
            *str += 'A' - 'a';
    }
    return ret;
}

mzcrt_inline char *mzcrt_strrev(char *str)
{
    char ch, *ptr1, *ptr2;
    size_t len = mzcrt_strlen(str);
    if (len <= 1)
        return str;

    ptr1 = str;
    ptr2 = str + len - 1;
    while (ptr1 < ptr2)
    {
        ch = *ptr2;
        *ptr2 = *ptr1;
        *ptr1 = ch;
    }
    return str;
}

mzcrt_inline char *mzcrt_strset(char *str, char c)
{
    char *ret = str;
    for (; *str; ++str)
    {
        *str = c;
    }
    return ret;
}

mzcrt_inline char *mzcrt_strnset(char *str, char c, size_t n)
{
    char *ret = str;
    for (; *str; ++str)
    {
        if (!n--)
            break;
        *str = c;
    }
    return ret;
}

mzcrt_inline char *mzcrt_strchr(const char *str, char ch)
{
    for (; *str; ++str)
    {
        if (*str == ch)
            return (char *)str;
    }
    return NULL;
}

mzcrt_inline char *mzcrt_strrchr(const char *str, char ch)
{
    const char *ret = NULL;
    for (; *str; ++str)
    {
        if (*str == ch)
        {
            ret = str;
        }
    }
    return (char *)ret;
}

mzcrt_inline int mzcrt_strcmp(const char *str1, const char *str2)
{
    const unsigned char *a = str1, *b = str2;
    for (; *a || *b; ++a, ++b)
    {
        if (*a != *b)
            return *a - *b;
    }
    return 0;
}

mzcrt_inline int mzcrt__stricmp(const char *str1, const char *str2)
{
    const char *a = str1, *b = str2;
    char p, q;
    for (; *a || *b; ++a, ++b)
    {
        p = mzcrt_toupper(*a);
        q = mzcrt_toupper(*b);
        if (p != q)
            return p - q;
    }
    return 0;
}

mzcrt_inline int mzcrt_strncmp(const char *str1, const char *str2, size_t n)
{
    const unsigned char *a = str1, *b = str2;
    size_t i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
            break;
        if (a[i] != b[i])
            return a[i] - b[i];
    }
    return 0;
}

#undef strcat
#undef strchr
#undef strcmp
#undef strcpy
#undef _stricmp
#undef strlen
#undef strlwr
#undef strncmp
#undef strnset
#undef strrchr
#undef strrev
#undef strset
#undef strstr
#undef strupr

#define strcat mzcrt_strcat
#define strchr mzcrt_strchr
#define strcmp mzcrt_strcmp
#define strcpy mzcrt_strcpy
#define _stricmp mzcrt__stricmp
#define strlen mzcrt_strlen
#define strlwr mzcrt_strlwr
#define strncmp mzcrt_strncmp
#define strnset mzcrt_strnset
#define strrchr mzcrt_strrchr
#define strrev mzcrt_strrev
#define strset mzcrt_strset
#define strstr mzcrt_strstr
#define strupr mzcrt_strupr
