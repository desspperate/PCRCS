#ifndef U16_TO_BINSTR_C
#define U16_TO_BINSTR_C

#include "../wrappers/malloc.h"

typedef unsigned short u16;

char *u16_to_binstr(u16 num)
{
    char *res = (char*)calloc_(17, sizeof(char));
    res[16] = '\xff';

    int i = 0;
    while (num > 0) {
        res[15 - i] = num % 2;
        i++;
        num /= 2;
    }

    return res;
}

#endif