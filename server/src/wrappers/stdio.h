#ifndef STDIO_WRAPPER_H
#define STDIO_WRAPPER_H

#include <stdio.h>

extern FILE *fopen_ (const char *__restrict __filename, const char *__restrict __modes);

extern int fclose_(FILE *__stream);

extern int fputs_(const char *__restrict __s, FILE *__restrict __stream);

extern int putc_(int __c, FILE *__stream);

#endif