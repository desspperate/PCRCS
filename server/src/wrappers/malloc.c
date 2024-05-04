#ifndef MALLOC_WRAPPER_C
#define MALLOC_WRAPPER_C

#include <assert.h>
#include <malloc.h>

void *malloc_(size_t __size)
{
    void *res = malloc(__size);
    assert(res != NULL);
    return res;
}

void *calloc_(size_t __nmemb, size_t __size)
{
    void *res = calloc(__nmemb, __size);
    assert(res != NULL);
    return res;
}

void *realloc_(void *__ptr, size_t __size)
{
    void *res = realloc(__ptr, __size);
    assert(res != NULL);
    return res;
}

void free_(void *__ptr)
{
    assert(__ptr != NULL);
    free(__ptr);
}

#endif