#ifndef OPERATOR_PUSH_C
#define OPERATOR_PUSH_C

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "../../queue/dynamic_array.h"
#include "../../queue/queue.h"
#include "../../wrappers/malloc.h"

void operator_push(dynamic *queues, char *command, size_t len)
{
    assert(queues != NULL);
    assert(command != NULL);

    queue *tmp_queue;
    for (int i = 0; i < queues->length; ++i) {
        tmp_queue = dyn_get(queues, i);
        char *commmand_coppy = (char*)calloc_(len, sizeof(char));
        memcpy(commmand_coppy, command, len);
        queue_push(tmp_queue, commmand_coppy);
    }
}

#endif