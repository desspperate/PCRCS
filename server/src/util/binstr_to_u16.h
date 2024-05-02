#ifndef BINSTR_TO_U16_H
#define BINSTR_TO_U16_H

#include <stddef.h>

typedef unsigned short u16;

extern u16 binstr_to_u16(char *binstr, size_t len);

#endif