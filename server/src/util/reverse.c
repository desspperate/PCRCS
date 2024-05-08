#ifndef REVERSE_C
#define REVERSE_C

#include <assert.h>

#include <stddef.h>

void reverse(char *str, size_t len)
{
    assert(str != NULL);
    if (len < 3) {
        return;
    }

    int i = 0;
    int j = len - 2;
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++; j--;
    }
}

#endif