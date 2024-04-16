#ifndef MALLOC_WRAPPER_H
#define MALLOC_WRAPPER_H

#include <stddef.h>

extern void *malloc_(size_t __size);

extern void *calloc_(size_t __nmemb, size_t __size);

extern void *realloc_(void *__ptr, size_t __size);

extern void free_(void *__ptr);

#endif