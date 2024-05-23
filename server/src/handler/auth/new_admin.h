#ifndef NEW_ADMIN_H
#define NEW_ADMIN_H

#include <stddef.h>

#include "access_level.h"

extern int new_admin(char *login, size_t login_len, char *pword, size_t pword_len, access_level al);

#endif