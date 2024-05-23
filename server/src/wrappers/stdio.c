#ifndef STDIO_WRAPPER_C
#define STDIO_WRAPPER_C

#include <assert.h>
#include <stdio.h>

FILE *fopen_ (const char *__restrict __filename, const char *__restrict __modes)
{
    FILE *res = fopen(__filename, __modes);
    assert(res != NULL);
    return res;
}

int fclose_(FILE *__stream)
{
    int res = fclose(__stream);
    assert(res != EOF);
    return res;
}

int fputs_(const char *__restrict __s, FILE *__restrict __stream)
{
    int res = fputs(__s, __stream);
    assert(res != EOF);
    return res;
}

int putc_(int __c, FILE *__stream)
{
    int res = putc(__c, __stream);
    assert(res != EOF);
    return res;
}

#endif