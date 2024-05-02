#ifndef NULL_CHECK_C
#define NULL_CHECK_C

#include <stdlib.h>

static void null_check(void *p)
{
    if (p == NULL) {
        exit(EXIT_FAILURE);
    }
}

#endif