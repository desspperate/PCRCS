#ifndef UNISTD_WRAPPER_C
#define UNISTD_WRAPPER_C

#include <assert.h>
#include <unistd.h>

int close_(int __fd)
{
    int res = close(__fd);
    assert(res >= 0);
    return res;
}

#endif