#include "includes.h"
#include "defs.h"

int main(int argc, char **argv)
{
    if (args_are_invalid(argc, argv)) {
        puts("Arguments are invalid. You should write available port (1024 — 9999).");
        exit(EXIT_FAILURE);
    }
    
    int                 server_fd;
    int                 port;
    struct sockaddr_in  address;
    socklen_t           addr_len;
    ssize_t             val_read;
    int                 client_fd;
    u8                  buf [BUF_LEN + 1];

    buf [BUF_LEN] = '\0';

    port = str_to_u16(argv[1], 5);
    addr_len = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = 0;

    server_fd = socket_(AF_INET, SOCK_STREAM, 0);
    bind_(server_fd, (struct sockaddr*)&address, addr_len);
    listen_(server_fd, 100);

    u16_raw  rheader;
    u8      *rtype;
    u16     *rcode;

    rtype = (u8*)calloc_(1, sizeof(u8));
    rcode = (u16*)calloc_(1, sizeof(u16));

    expression_status_t expression_status;

    for (;;) {
        client_fd = accept_(server_fd, 0, 0);

        val_read = recv(client_fd, buf, BUF_LEN, 0);
        if (val_read == 0) {
            continue;
        }
        buf[val_read] = '\0';
        rheader.bytes[0] = buf[0];
        rheader.bytes[1] = buf[1];

        get_rtype_and_rcode(rtype, rcode, rheader.s);

        switch (*rtype) {
            case USER:
                r_handler_user();
                break;
            case ADMIN:
                r_handler_admin();
                break;
            case SYSTEM:
                r_handler_system();
                break;
            default:
                puts("Error 360");
                expression_status = BAD_REQUEST;
                send(client_fd, &expression_status, EXPRESSION_STATUS_SIZE, 0);
                break;
        }
    }

    free_(rtype);
    free_(rcode);
    close(server_fd);
    exit(EXIT_SUCCESS);
}