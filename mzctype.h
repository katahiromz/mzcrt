#pragma once

#include "mzcrt.h"

mzcrt_inline char *mzcrt_strchr(const char *str, char ch);

mzcrt_inline int mzcrt_islower(char c)
{
    return 'a' <= c && c <= 'z';
}

mzcrt_inline int mzcrt_isupper(char c)
{
    return 'A' <= c && c <= 'Z';
}

mzcrt_inline int mzcrt_isdigit(char c)
{
    return '0' <= c && c <= '9';
}

mzcrt_inline int mzcrt_isalpha(char c)
{
    return mzcrt_islower(c) || mzcrt_isupper(c);
}

mzcrt_inline int mzcrt_isalnum(char c)
{
    return mzcrt_isalpha(c) || mzcrt_isdigit(c);
}

mzcrt_inline int mzcrt_isspace(char c)
{
    return mzcrt_strchr(" \t\n\r\f\v", c) != NULL;
}

mzcrt_inline int mzcrt_isblank(char c)
{
    return c == ' ' || c == '\t';
}

mzcrt_inline int mzcrt_iscntrl(char c)
{
    return (unsigned char)c <= 0x1F || (unsigned char)c == 0x7F;
}

mzcrt_inline int mzcrt_isprint(char c)
{
    return 0x20 <= (unsigned char)c && (unsigned char)c <= 0x7E;
}

mzcrt_inline int mzcrt_ispunct(char c)
{
    return mzcrt_strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}", c) != NULL;
}

mzcrt_inline int mzcrt_isgraph(char c)
{
    return !mzcrt_isspace(c) && mzcrt_isprint(c);
}

mzcrt_inline int mzcrt_isxdigit(char c)
{
    return mzcrt_isdigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
}

mzcrt_inline int mzcrt_isascii(char c)
{
    return (unsigned char)c <= 0x7F;
}

mzcrt_inline int mzcrt_iscsymf(char c)
{
    return mzcrt_isalpha(c) || c == '_';
}

mzcrt_inline int mzcrt_iscsym(char c)
{
    return mzcrt_isalnum(c) || c == '_';
}

mzcrt_inline char mzcrt_toupper(char ch)
{
    if ('a' <= ch && ch <= 'z')
        ch += 'A' - 'a';
    return ch;
}

mzcrt_inline char mzcrt_tolower(char ch)
{
    if ('A' <= ch && ch <= 'Z')
        ch += 'a' - 'A';
    return ch;
}

#undef isalnum
#undef isalpha
#undef isblank
#undef iscntrl
#undef isdigit
#undef islower
#undef isprint
#undef ispunct
#undef isspace
#undef isupper
#undef tolower
#undef toupper

#define isalnum mzcrt_isalnum
#define isalpha mzcrt_isalpha
#define isblank mzcrt_isblank
#define iscntrl mzcrt_iscntrl
#define isdigit mzcrt_isdigit
#define islower mzcrt_islower
#define isprint mzcrt_isprint
#define ispunct mzcrt_ispunct
#define isspace mzcrt_isspace
#define isupper mzcrt_isupper
#define tolower mzcrt_tolower
#define toupper mzcrt_toupper
