#ifndef BINSTR_TO_U16_C
#define BINSTR_TO_U16_C

#include <assert.h>
#include <stddef.h>

#include "u16_pow.h"

typedef unsigned short u16;

u16 binstr_to_u16(char *binstr, size_t len)
{
    assert(binstr[len - 1] == '\xff');
    assert(binstr != NULL);
    assert(len > 1 && len < 18);

    u16 res = 0;

    for (int i = 0; i < len - 1; ++i) {
        assert(binstr[i] == 0 || binstr[i] == 1);
        if (binstr[i] == 1) {
            res += u16_pow(2, len - 2 - i);
        }
    }

    return res;
}

#endif