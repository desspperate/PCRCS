#ifndef MALLOC_WRAPPER_C
#define MALLOC_WRAPPER_C

#include <stdlib.h>
#include <stddef.h>

static void null_check(void *p)
{
    if (p == NULL) {
        exit(EXIT_FAILURE);
    }
}

void *malloc_(size_t __size)
{
    void *res;
    null_check((res = malloc(__size)));
    return res;
}

void *calloc_(size_t __nmemb, size_t __size)
{
    void *res;
    null_check((res = calloc(__nmemb, __size)));
    return res;
}

void *realloc_(void *__ptr, size_t __size)
{
    void *res;
    null_check((res = realloc(__ptr, __size)));
    return res;
}

void free_(void *__ptr)
{
    free(__ptr);
}

#endif