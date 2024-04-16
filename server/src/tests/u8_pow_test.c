#ifndef U8_POW_TEST_C
#define u8_POW_TEST_C

#include <stdio.h>

#include "../util/u8_pow.c"

void u8_pow_test()
{
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d %d %d\n", i, j, u8_pow(i, j));
        }
    }
}

#endif