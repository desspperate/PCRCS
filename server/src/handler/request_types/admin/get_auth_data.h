#ifndef GET_AUTH_DATA_H
#define GET_AUTH_DATA_H

#include <stddef.h>

extern int check_auth_data(char *buf);

extern size_t get_login(char *login, char *buf);

extern size_t get_pword(char *pword, char *buf);

#endif