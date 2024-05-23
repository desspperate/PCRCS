#ifndef GET_ACCESS_LEVEL_H
#define GET_ACCESS_LEVEL_H

#include <stddef.h>

#include "access_level.h"

extern access_level get_access_level(access_level *al, char *login, size_t login_len, char *pword, size_t pword_len);

#endif