#pragma once

#include "mzcrt.h"
#include "mzstr.h"

mzcrt_inline size_t mzcrt_wcslen(const wchar_t *s)
{
    size_t i;
    for (i = 0; s[i]; i++)
    {
        ;
    }
    return i;
}

mzcrt_inline wchar_t *mzcrt_wcscpy(wchar_t *dst, const wchar_t *src)
{
    size_t i;
    for (i = 0; src[i]; i++)
        dst[i] = src[i];
    return dst;
}

mzcrt_inline wchar_t *mzcrt_wcscat(wchar_t *dst, const wchar_t *src)
{
    size_t len;
    len = mzcrt_wcslen(dst);
    mzcrt_wcscpy(dst + len, src);
    return dst;
}

mzcrt_inline wchar_t *mzcrt_wcsstr(const wchar_t *s, const wchar_t *t)
{
    size_t tlen = mzcrt_wcslen(t);
    for (; *s; ++s)
    {
        if (mzcrt_memcmp(s, t, tlen * sizeof(wchar_t)) == 0)
            return (wchar_t *)s;
    }
    return NULL;
}

mzcrt_inline wchar_t *mzcrt_wcslwr(wchar_t *str)
{
    wchar_t *ret = str;
    for (; *str; str++)
    {
        if (L'A' <= *str && *str <= L'Z')
            *str += L'a' - L'A';
    }
    return ret;
}

mzcrt_inline wchar_t *mzcrt_wcsupr(wchar_t *str)
{
    wchar_t *ret = str;
    for (; *str; ++str)
    {
        if (L'a' <= *str && *str <= L'z')
            *str += L'A' - L'a';
    }
    return ret;
}

mzcrt_inline wchar_t *mzcrt_wcsrev(wchar_t *str)
{
    wchar_t ch, *ptr1, *ptr2;
    size_t len = mzcrt_wcslen(str);
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

mzcrt_inline wchar_t *mzcrt_wcsset(wchar_t *str, wchar_t c)
{
    wchar_t *ret = str;
    for (; *str; ++str)
    {
        *str = c;
    }
    return ret;
}

mzcrt_inline wchar_t *mzcrt_wcsnset(wchar_t*str, wchar_t c, size_t n)
{
    wchar_t *ret = str;
    for (; *str; ++str)
    {
        if (!n--)
            break;
        *str = c;
    }
    return ret;
}

mzcrt_inline wchar_t *mzcrt_wcschr(const wchar_t *str, wchar_t ch)
{
    for (; *str; ++str)
    {
        if (*str == ch)
            return (wchar_t *)str;
    }
    return NULL;
}

mzcrt_inline wchar_t *mzcrt_wcsrchr(const wchar_t *str, wchar_t ch)
{
    const wchar_t *ret = NULL;
    for (; *str; ++str)
    {
        if (*str == ch)
        {
            ret = str;
        }
    }
    return (wchar_t *)ret;
}

mzcrt_inline int mzcrt_wcscmp(const wchar_t *str1, const wchar_t *str2)
{
    const wchar_t *a = p1, *b = p2;
    for (; *a || *b; ++a, ++b)
    {
        if (*a != *b)
            return *a - *b;
    }
    return 0;
}

mzcrt_inline int mzcrt__wcsicmp(const wchar_t *str1, const wchar_t *str2)
{
    const wchar_t *a = p1, *b = p2;
    char p, q;
    for (; *a || *b; ++a, ++b)
    {
        p = mzcrt_towupper(*a);
        q = mzcrt_towupper(*b);
        if (p != q)
            return p - q;
    }
    return 0;
}

mzcrt_inline int mzcrt_wcsncmp(const wchar_t *str1, const wchar_t *str2, size_t n)
{
    return mzcrt_memcmp(str1, str2, n * sizeof(wchar_t));
}

#undef wcscat
#undef wcschr
#undef wcscmp
#undef wcscpy
#undef _wcsicmp
#undef wcslen
#undef wcslwr
#undef wcsncmp
#undef wcsnset
#undef wcsrchr
#undef wcsrev
#undef wcsset
#undef wcsstr
#undef wcsupr

#define wcscat mzcrt_wcscat
#define wcschr mzcrt_wcschr
#define wcscmp mzcrt_wcscmp
#define wcscpy mzcrt_wcscpy
#define _wcsicmp mzcrt__wcsicmp
#define wcslen mzcrt_wcslen
#define wcslwr mzcrt_wcslwr
#define wcsncmp mzcrt_wcsncmp
#define wcsnset mzcrt_wcsnset
#define wcsrchr mzcrt_wcsrchr
#define wcsrev mzcrt_wcsrev
#define wcsset mzcrt_wcsset
#define wcsstr mzcrt_wcsstr
#define wcsupr mzcrt_wcsupr
