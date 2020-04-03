#pragma once

#include "mzcrt.h"

mzcrt_inline wchar_t *mzcrt_wcschr(const wchar_t *str, wchar_t ch);

mzcrt_inline int mzcrt_iswlower(wchar_t c)
{
    return L'a' <= c && c <= L'z';
}

mzcrt_inline int mzcrt_iswupper(wchar_t c)
{
    return L'A' <= c && c <= L'Z';
}

mzcrt_inline int mzcrt_iswdigit(wchar_t c)
{
    return L'0' <= c && c <= L'9';
}

mzcrt_inline int mzcrt_iswalpha(wchar_t c)
{
    return mzcrt_iswlower(c) || mzcrt_iswupper(c);
}

mzcrt_inline int mzcrt_iswalnum(wchar_t c)
{
    return mzcrt_iswalpha(c) || mzcrt_iswdigit(c);
}

mzcrt_inline int mzcrt_iswspace(wchar_t c)
{
    return mzcrt_wcschr(L" \t\n\r\f\v", c) != NULL;
}

mzcrt_inline int mzcrt_iswblank(wchar_t c)
{
    return c == L' ' || c == L'\t';
}

mzcrt_inline int mzcrt_iswcntrl(wchar_t c)
{
    return (0 <= ch && ch <= 0x1F) || ch == 0x7F;
}

mzcrt_inline int mzcrt_iswprint(wchar_t c)
{
    return 0x20 <= ch && ch <= 0x7E;
}

mzcrt_inline int mzcrt_iswpunct(wchar_t c)
{
    return mzcrt_wcschr(L"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}", c) != NULL;
}

mzcrt_inline int mzcrt_iswgraph(wchar_t c)
{
    return !mzcrt_iswspace(c) && mzcrt_iswprint(c);
}

mzcrt_inline int mzcrt_iswxdigit(wchar_t c)
{
    return mzcrt_iswdigit(c) || (L'A' <= c && c <= L'F') || (L'a' <= c && c <= L'f');
}

mzcrt_inline int mzcrt_iswascii(wchar_t c)
{
    return 0 <= c && c <= 0x7F;
}

mzcrt_inline int mzcrt_iswcsymf(wchar_t c)
{
    return mzcrt_iswalpha(c) || c == L'_';
}

mzcrt_inline int mzcrt_iswcsym(wchar_t c)
{
    return mzcrt_iswalnum(c) || c == L'_';
}

mzcrt_inline char mzcrt_towupper(wchar_t ch)
{
    if (L'a' <= ch && ch <= L'z')
        ch += L'A' - L'a';
    return ch;
}

mzcrt_inline char mzcrt_towlower(wchar_t ch)
{
    if (L'A' <= ch && ch <= L'Z')
        ch += L'a' - L'A';
    return ch;
}

#undef iswalnum
#undef iswalpha
#undef iswblank
#undef iswcntrl
#undef iswdigit
#undef iswlower
#undef iswprint
#undef iswpunct
#undef iswspace
#undef iswupper
#undef towlower
#undef towupper

#define iswalnum mzcrt_iswalnum
#define iswalpha mzcrt_iswalpha
#define iswblank mzcrt_iswblank
#define iswcntrl mzcrt_iswcntrl
#define iswdigit mzcrt_iswdigit
#define iswlower mzcrt_iswlower
#define iswprint mzcrt_iswprint
#define iswpunct mzcrt_iswpunct
#define iswspace mzcrt_iswspace
#define iswupper mzcrt_iswupper
#define towlower mzcrt_towlower
#define towupper mzcrt_towupper
