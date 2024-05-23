#ifndef GET_AUTH_DATA_C
#define GET_AUTH_DATA_C

#include <assert.h>
#include <stddef.h>

#include "../../auth/auth_config.h"

int check_auth_data(char *buf)
{
    assert(buf != NULL);

    int i = -1;
    int cnt = 0;
    while (buf[++i] != 0) {
        if (buf[i] == SEPARATOR_CHAR) {
            cnt++;
        }
    }

    if (cnt < 2) {
        return 1;
    } 
}

size_t get_login(char *login, char *buf)
{
    assert(buf != NULL);
    assert(login != NULL);

    int i = -1;
    while (buf[++i] != SEPARATOR_CHAR) {
        login[i] = buf[i];
    }

    return i;
}

size_t get_pword(char *pword, char *buf)
{
    assert(buf != NULL);
    assert(pword != NULL);

    int i = -1;
    while (buf[++i] != SEPARATOR_CHAR) {
        pword[i] = buf[i];
    }

    return i;
}

#endif