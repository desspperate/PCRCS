#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define START_CAPACITY 3
#define ERROR          NULL
#define ERROR_404      __INT_MAX__

typedef unsigned long int u64;

typedef struct dynamic
{
    u64    capacity;
    u64    length;
    void** array;
}   dynamic;

struct dynamic* dyn_init();

void dyn_free(struct dynamic* dyn);

int dyn_find(struct dynamic* dyn, void* value);

u64 dyn_len(struct dynamic* dyn);

void dyn_append(struct dynamic* dyn, void* value);

void dyn_print(struct dynamic* dyn, const char* format, const char* end);

void dyn_reverse_print(struct dynamic* dyn, const char* format, const char* end);

void dyn_insert(struct dynamic* dyn, void* value, u64 index);

void dyn_replace(struct dynamic* dyn, void* value, u64 index);

void* dyn_get(struct dynamic* dyn, u64 index);

void dyn_del(struct dynamic* dyn, u64 index);

void** get_c_arr(struct dynamic* dyn);

#endif