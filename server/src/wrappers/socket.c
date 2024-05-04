#ifndef SOCKET_WRAPPER_C
#define SOCKET_WRAPPER_C

#include <stdio.h>
#include <assert.h>
#include <sys/socket.h>

int socket_(int __domain, int __type, int __protocol)
{
    int res = socket(__domain, __type, __protocol);
    assert(res >= 0);
    return res;
}

int bind_(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
{
    int res = bind(__fd, __addr, __len);
    assert(res >= 0);
    return res;
    
}

int listen_(int __fd, int __n)
{
    int res = listen(__fd, __n);
    assert(res >= 0);
    return res;
}

int accept_(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len)
{
    int res = accept(__fd, __addr, __addr_len);
    assert(res >= 0);
    return res;
}

int send_(int __fd, const void *__buf, size_t __n, int __flags)
{
    int res = send(__fd, __buf, __n, __flags);
    assert(res >= 0);
    return res;
}

int recv_(int __fd, void *__buf, size_t __n, int __flags)
{
    int res = recv(__fd, __buf, __n, __flags);
    assert(res >= 0);
    return res;
}

#endif