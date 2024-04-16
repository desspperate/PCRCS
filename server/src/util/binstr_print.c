#ifndef BINSTR_PRINT_C
#define BINSTR_PRINT_C

#include <stdio.h>
#include <assert.h>
#include <stddef.h>

void binstr_print(char *binstr, size_t len, char sep, int sep_every)
{
    assert(binstr != NULL);
    assert(len > 1);
    assert(binstr[len - 1] == '\xff');
    assert(sep > 31 && sep < 127);
    assert(sep_every != 0 && (int)len > sep_every);

    if (sep_every < 0) {
        sep = 0;
    }

    for (int i = 0; i < len - 1; ++i) {
        assert(binstr[i] == 0 || binstr[i] == 1);
        if (i % sep_every == 0 && i != 0) {
            putchar(sep);
        }
        putchar('0' + binstr [i]);
    }
}

#endif