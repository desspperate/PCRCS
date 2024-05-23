#include "includes.h"
#include "defs.h"

int main(int argc, char **argv)
{
    if (args_are_invalid(argc, argv)) {
        FILE *log = fopen_("server.log", "w");
        fputs_("Arguments are invalid. You should write available port (1024 — 9999).", log);
        fclose_(log);
        exit(EXIT_FAILURE);
    }

    FILE *log = fopen_("server.log", "w");
    fputs_("Starting PCRCS (Personal Computer Remote Control System) server.", log);
    fclose_(log);
    
    int                 server_fd;
    int                 port;
    struct sockaddr_in  address;
    socklen_t           addr_len;
    ssize_t             val_read;
    int                 client_fd;
    u8                  buf [BUF_LEN + 1];

    for (int i = 0; i < BUF_LEN + 1; ++i) {
        buf[i] = 0;
    }

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

    map     *users_queues = map_init();
    dynamic *queues = dyn_init();

    for (;;) {
        client_fd = accept_(server_fd, 0, 0);

        val_read = recv_(client_fd, buf, BUF_LEN, 0);
        if (val_read < 2) {
            response(client_fd, BAD_REQUEST, NULL, 0);
            continue;
        }
        buf[val_read] = 0;
        rheader.bytes[0] = buf[1];
        rheader.bytes[1] = buf[0];

        get_rtype_and_rcode(rtype, rcode, rheader.s);

        int need_to_exit = 0;
        switch (*rtype) {
            case USER:
                r_handler_user(*rcode, client_fd, buf, &users_queues, queues);
                break;
            case ADMIN:
                need_to_exit = r_handler_admin(*rcode, client_fd, buf, queues);
                break;
            case SYSTEM:
                r_handler_system();
                break;
            default:
                response(client_fd, BAD_REQUEST, NULL, 0);
                break;
        }
        close_(client_fd);
        if (need_to_exit) {
            break;
        }
    }

    map_destruct(users_queues);
    for (int i = 0; i < queues->length; ++i) {
        queue *tmp_queue = dyn_get(queues, i);
        for (int j = 0; j < tmp_queue->length; ++j) {
            free_(tmp_queue->storage->array[j]);
        }
        queue_destruct(tmp_queue);
    }
    free_(rtype);
    free_(rcode);
    close_(server_fd);
    exit(EXIT_SUCCESS);
}