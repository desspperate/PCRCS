#include <stdbool.h>
#include <stdlib.h>

#include <string.h>

#include "queue.h"
#include "dynamic_array.h"

struct queue* queue_init()
{
    struct queue* queue_;
    queue_ = (struct queue*)malloc(sizeof(struct queue));

    queue_->length = 0;
    queue_->storage = dyn_init();

    return queue_;
}

void queue_destruct(struct queue* queue_)
{
    dyn_free(queue_->storage);
    free(queue_);
}

void queue_print(struct queue* queue_, char* format, char* end)
{
    dyn_print(queue_->storage, format, end);
}

void queue_push(struct queue* queue_, void* value)
{
    dyn_insert(queue_->storage, value, 0);
    queue_->length++;
}

static u64 queue_size(struct queue* queue_)
{
    return queue_->length;
}

void* queue_pop(struct queue* queue_)
{
    void *value;
    value = dyn_get(queue_->storage, queue_size(queue_) - 1);
    dyn_del(queue_->storage, queue_size(queue_) - 1);

    queue_->length--;

    return value;
}

void* queue_back(struct queue* queue_)
{
    return dyn_get(queue_->storage, 0);
}

void* queue_front(struct queue* queue_)
{
    return dyn_get(queue_->storage, queue_size(queue_) - 1);
}

bool queue_is_empty(struct queue* queue_)
{
    return (queue_size(queue_) == 0);
}