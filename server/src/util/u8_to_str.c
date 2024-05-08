#ifndef U8_TO_STR_C
#define U8_TO_STR_C

#include "../wrappers/malloc.h"
#include "reverse.h"

typedef unsigned char u8;

char *u8_to_str(u8 num)
{
    char *res = (char*)calloc_(4, sizeof(char));

    int i = 0;
    while (num > 0) {
        res[i] = num % 10 + '0';
        num /= 10;
        i++;
    }

    reverse(res, i + 1);
    res = (char*)realloc_(res, (i +1 ) * sizeof(char));

    return res;
}

#endif