#ifndef U16_POW_TEST_C
#define u16_POW_TEST_C

#include <stdio.h>

#include "../util/u16_pow.c"

void u16_pow_test()
{
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d %d %d\n", i, j, u16_pow(i, j));
        }
    }
}

#endif