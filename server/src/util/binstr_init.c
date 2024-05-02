#ifndef BINSTR_INIT_H
#define BINSTR_INIT_H

#include <assert.h>

#include <stddef.h>

#include "../wrappers/malloc.h"

char *binstr_init(size_t len)
{
    assert(len > 1);

    char *binstr = (char*)calloc_(len, sizeof(char));
    binstr[len - 1] = '\xff';

    return binstr;
}

#endif