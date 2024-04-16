#ifndef U8_POW_C
#define U8_POW_C

#define U8_MAX 255

#include <assert.h>

typedef unsigned char  u8;
typedef unsigned short u16;

u8 u8_pow(u8 n, u8 p)
{
    if (p == 0) {
        return 1;
    } else if (n <= 1 || p == 1) {
        return n;
    }
    
    assert(n < 16);
    assert(p < 8);

    u16 res = (u16)n;

    for (int i = 0; i < p - 1; ++i) {
        res *= (u16)n;
        assert(res <= U8_MAX);
    }

    return (u8)res;
}

#endif