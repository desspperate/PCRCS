#include "handler/request_types/user/user.h"
#include "handler/request_types/admin/admin.h"
#include "handler/request_types/system/system.h"
#include "handler/header.h"
#include "handler/response/response.h"
#include "handler/auth/new_admin.h"
#include "wrappers/malloc.h"
#include "wrappers/socket.h"
#include "wrappers/stdio.h"
#include "wrappers/unistd.h"
#include "args_are_invalid.h"
#include "util/str_to_u16.h"

#include <stdlib.h>
#include <arpa/inet.h>

/* include things to rewrite */
#include "hashmap/hash_map.h"
#include "queue/queue.h"
#include "queue/dynamic_array.h"