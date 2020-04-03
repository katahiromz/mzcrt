#pragma once

#include "mzcrt.h"
#include "mzctype.h"

mzcrt_inline const char *mzcrt_skip_space(const char *s)
{
    while (mzcrt_isspace(*s))
    {
        ++s;
    }
    return s;
}

mzcrt_inline long mzcrt_strtol_8(const char *s, char **endptr)
{
    long n;
    for (n = 0; '0' <= *s && *s <= '7'; ++s)
    {
        n *= 8;
        n += (*s - '0');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline long mzcrt_strtol_10(const char *s, char **endptr)
{
    long n;
    for (n = 0; '0' <= *s && *s <= '9'; ++s)
    {
        n *= 10;
        n += (*s - '0');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline long mzcrt_strtol_16(const char *s, char **endptr)
{
    long n;
    for (n = 0; mzcrt_isxdigit(*s); ++s)
    {
        n *= 10;
        if (mzcrt_isdigit(*s))
            n += *s - '0';
        else if ('A' <= *s && *s <= 'F')
            n += *s + (10 - 'A');
        else if ('a' <= *s && *s <= 'f')
            n += *s + (10 - 'a');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline unsigned long mzcrt_strtoul_8(const char *s, char **endptr)
{
    unsigned long n;
    for (n = 0; '0' <= *s && *s <= '7'; ++s)
    {
        n *= 8;
        n += (*s - '0');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline unsigned long mzcrt_strtoul_10(const char *s, char **endptr)
{
    unsigned long n;
    for (n = 0; '0' <= *s && *s <= '9'; ++s)
    {
        n *= 10;
        n += (*s - '0');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline unsigned long mzcrt_strtoul_16(const char *s, char **endptr)
{
    unsigned long n;
    for (n = 0; mzcrt_isxdigit(*s); ++s)
    {
        n *= 10;
        if (mzcrt_isdigit(*s))
            n += *s - '0';
        else if ('A' <= *s && *s <= 'F')
            n += *s + (10 - 'A');
        else if ('a' <= *s && *s <= 'f')
            n += *s + (10 - 'a');
    }
    if (endptr)
        *endptr = (char *)s;
    return n;
}

mzcrt_inline long mzcrt_strtol(const char *s, char **endptr, int base)
{
    s = mzcrt_skip_space(s);

    if (*s == '0')
    {
        if (s[1] == 'x' || s[1] == 'X')
        {
            if (base == 0)
                base = 16;
            s += 2;
        }
        else
        {
            if (base == 0)
                base = 8;
            s += 1;
        }
    }

    if (base == 0)
    {
        base = 10;
    }

    if (base == 8)
    {
        return mzcrt_strtol_8(s, endptr);
    }

    if (base == 10)
    {
        return mzcrt_strtol_10(s, endptr);
    }

    if (base == 16)
    {
        return mzcrt_strtol_16(s, endptr);
    }

    return 0;
}

mzcrt_inline unsigned long mzcrt_strtoul(const char *s, char **endptr, int base)
{
    s = mzcrt_skip_space(s);

    if (*s == '0')
    {
        if (s[1] == 'x' || s[1] == 'X')
        {
            if (base == 0)
                base = 16;
            s += 2;
        }
        else
        {
            if (base == 0)
                base = 8;
            s += 1;
        }
    }

    if (base == 0)
    {
        base = 10;
    }

    if (base == 8)
    {
        return mzcrt_strtoul_8(s, endptr);
    }

    if (base == 10)
    {
        return mzcrt_strtoul_10(s, endptr);
    }

    if (base == 16)
    {
        return mzcrt_strtoul_16(s, endptr);
    }

    return 0;
}

mzcrt_inline int mzcrt_atoi(const char *s)
{
    return (int)mzcrt_strtol(s, NULL, 10);
}

mzcrt_inline long mzcrt_atol(const char *s)
{
    return mzcrt_strtol(s, NULL, 10);
}

#undef strtol
#undef strtoul
#undef atoi
#undef atol

#define strtol mzcrt_strtol
#define strtoul mzcrt_strtoul
#define atoi mzcrt_atoi
#define atol mzcrt_atol
