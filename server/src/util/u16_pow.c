#ifndef U16_POW_C
#define U16_POW_C

#define U16_MAX 65535

#include <assert.h>

typedef unsigned short u16;
typedef unsigned       u32;

u16 u16_pow(u16 n, u16 p)
{
    if (p == 0) {
        return 1;
    } else if (n <= 1 || p == 1) {
        return n;
    }
    
    assert(n < 256);
    assert(p < 16);

    u32 res = (u32)n;

    for (int i = 0; i < p - 1; ++i) {
        res *= (u32)n;
        assert(res <= U16_MAX);
    }

    return (u16)res;
}

#endif