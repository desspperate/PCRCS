#ifndef SOCKET_WRAPPER_H
#define SOCKET_WRAPPER_H

#include <sys/socket.h>

extern int socket_(int __domain, int __type, int __protocol);

extern int bind_(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);

extern int listen_(int __fd, int __n);

extern int accept_(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len);

extern int send_(int __fd, const void *__buf, size_t __n, int __flags);

extern int recv_(int __fd, void *__buf, size_t __n, int __flags);

#endif