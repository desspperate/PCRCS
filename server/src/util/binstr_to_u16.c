#ifndef BINSTR_TO_U16_C
#define BINSTR_TO_U16_C

#include <assert.h>
#include <stddef.h>

typedef unsigned short u16;

u16 binstr_to_u16(char *binstr, size_t len)
{
    assert(binstr[len - 1] == '\xff');
    assert(binstr != NULL);
    assert(len > 1 && len < 18);

    u16 res = 0;
    u16 multiplyer = 1;

    for (int i = len - 2; i >= 0; --i) {
        assert(binstr[i] == 0 || binstr[i] == 1);
        res += binstr[i] * multiplyer;
        multiplyer *= 2;
    }

    return res;
}

#endif