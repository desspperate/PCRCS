#ifndef BINSTR_TO_U8_C
#define BINSTR_TO_U8_C

#include <assert.h>
#include <stddef.h>

typedef unsigned char u8;

u8 binstr_to_u8(char *binstr, size_t len)
{
    assert(binstr[len - 1] == '\xff');
    assert(binstr != NULL);
    assert(len < 10 && len > 1);

    u8 res = 0;
    u8 multiplyer = 1;

    for (int i = len - 2; i >= 0; --i) {
        assert(binstr[i] == 0 || binstr[i] == 1);
        res += binstr[i] * multiplyer;
        multiplyer *= 2;
    }

    return res;
}

#endif