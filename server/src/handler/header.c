#ifndef HEADER_HANDLER_C
#define HEADER_HANDLER_C

typedef unsigned char  u8;
typedef unsigned short u16;

#include <assert.h>

#include "../util/binstr_init.h"
#include "../util/u16_to_binstr.h"
#include "../util/binstr_to_u8.h"
#include "../util/binstr_to_u16.h"
#include "../wrappers/malloc.h"

#include "../util/binstr_print.h"

void get_rtype_and_rcode(u8 *rtype_ptr, u16 *rcode_ptr, u16 rheader)
{
    assert(rtype_ptr != NULL);
    assert(rcode_ptr != NULL);

    char *rheader_bin = u16_to_binstr(rheader);

    char *rtype_bin = binstr_init(6);
    char *rcode_bin = binstr_init(12);

    for (int i = 0; i < 5; ++i) {
        rtype_bin[i] = rheader_bin[i];
    }
    for (int i = 0; i < 11; ++i) {
        rcode_bin[i] = rheader_bin[i + 5];
    }

    *rtype_ptr = binstr_to_u8(rtype_bin, 6);
    *rcode_ptr = binstr_to_u16(rcode_bin, 12);

    free_(rheader_bin);
    free_(rtype_bin);
    free_(rcode_bin);
}

#endif