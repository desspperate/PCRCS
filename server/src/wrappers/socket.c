#ifndef SOCKET_WRAPPER_C
#define SOCKET_WRAPPER_C

#include <sys/socket.h>

#include "static/socket_ret_check.c"

int socket_(int __domain, int __type, int __protocol)
{
    int res;
    socket_ret_check((res = socket(__domain, __type, __protocol)));
    return res;
}

int bind_(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
{
    int res;
    socket_ret_check((res = bind(__fd, __addr, __len)));
    return res;
    
}

int listen_(int __fd, int __n)
{
    int res;
    socket_ret_check((res = listen(__fd, __n)));
    return res;
}

int accept_(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len)
{
    int res;
    socket_ret_check((res = accept(__fd, __addr, __addr_len)));
    return res;
}


#endif