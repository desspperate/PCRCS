#ifndef BINSTR_TO_U8_C
#define BINSTR_TO_U8_C

#include <assert.h>
#include <stddef.h>

#include "u8_pow.h"

typedef unsigned char u8;

u8 binstr_to_u8(char *binstr, size_t len)
{
    assert(binstr[len - 1] == '\xff');
    assert(binstr != NULL);
    assert(len < 10 && len > 1);

    u8 res = 0;

    for (int i = 0; i < len - 1; ++i) {
        assert(binstr[i] == 0 || binstr[i] == 1);
        if (binstr[i] == 1) {
            res += u8_pow(2, len - 2 - i);
        }
    }

    return res;
}

#endif