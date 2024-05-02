#ifndef U16_TO_BINSTR_C
#define U16_TO_BINSTR_C

#include "binstr_init.h"

typedef unsigned short u16;

char *u16_to_binstr(u16 num)
{
    char *res = binstr_init(17);

    int i = 0;
    while (num > 0) {
        res[15 - i] = num % 2;
        i++;
        num /= 2;
    }

    return res;
}

#endif