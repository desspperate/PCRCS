#ifndef NEW_ADMIN_C
#define NEW_ADMIN_C

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "auth_config.h"
#include "access_level.h"
#include "../../wrappers/stdio.h"
#include "../../wrappers/malloc.h"

int new_admin(char *login, size_t login_len, char *pword, size_t pword_len, access_level al)
{
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

    raw_access_level  al_raw;
    FILE             *admin_table;
    u8               *new_line;

    al_raw.i = al;

    new_line = (u8*)calloc_(login_len + pword_len + 2 + sizeof(access_level) + 1, sizeof(u8));
    /* (+ 2) for separtor chars; (+ 1) for \n in the end of the new_line */
    
    memcpy(new_line, login, login_len);
    new_line[login_len] = SEPARATOR_CHAR;

    memcpy(new_line + login_len + 1, pword, pword_len);
    new_line[login_len + 1 + pword_len] = SEPARATOR_CHAR;

    memcpy(new_line + login_len + pword_len + 2, al_raw.b, sizeof(access_level));
    new_line[login_len + pword_len + 2 + sizeof(access_level)] = '\n';

    admin_table = fopen_(ADMIN_TABLE_PATH,  "ab");
    for (int i = 0; i < login_len + pword_len + 2 + sizeof(access_level) + 1; ++i) {
        putc_(new_line[i], admin_table);
    }
    
    free_(new_line);
    fclose_(admin_table);

    return 0;
}

#endif