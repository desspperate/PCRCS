#ifndef STR_TO_U16_C
#define STR_TO_U16_C

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef unsigned short u16;

u16 str_to_u16(char *str, size_t len)
{   
    assert(str[len - 1] == '\0');
    assert(str != NULL);
    assert(len > 1 && len < 7);

    u16 res = 0;
    u16 multiplyer = 1;

    for (int i = len - 2; i >= 0; --i) {
        assert(str[i] >= '0' && str[i] <= '9');
        res += (str[i] - '0') * multiplyer;
        multiplyer *= 10;
    }

    return res;
}

#endif