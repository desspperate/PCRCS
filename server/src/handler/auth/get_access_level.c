#ifndef GET_ACCESS_LEVEL_C
#define GET_ACCESS_LEVEL_C

#include <assert.h>
#include <stddef.h>

#include "access_level.h"
#include "auth_config.h"

int get_access_level(access_level *al, char *login, size_t login_len, char *pword, size_t pword_len)
{
    assert(al != NULL);
    assert(login != NULL);
    assert(pword != NULL);
    assert(login[login_len] == 0);
    assert(pword[pword_len] == 0);

    for (int i = 0; i < login_len; ++i) {
        if (login[i] > 126 || login[i] < 33) {
            return 1;
        }
    }
    for (int i = 0; i < pword_len; ++i) {
        if (pword[i] > 126 || pword[i] < 33) {
            return 1;
        }
    }
    if (login_len > MAX_LOGIN_LEN) {
        return 2;
    } else if (login_len < MIN_LOGIN_LEN) {
        return 3;
    } else if (pword_len > MAX_PASSWORD_LEN) {
        return 4;
    } else if (pword_len < MIN_PASSWORD_LEN) {
        return 5;
    }

    return 0;
}

#endif