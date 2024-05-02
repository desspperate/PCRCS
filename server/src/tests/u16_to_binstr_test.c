#ifndef U16_TO_BINSTR_TEST_C
#define U16_TO_BINSTR_TEST_C

#include "../util/u16_to_binstr.c"
#include "../util/binstr_to_u16.c"
#include "../util/u16_pow.c"

#include <assert.h>
#include <stdlib.h>

void u16_to_binstr_test()
{
    for (int i = 0; i < 65536; ++i) {
        char *binstr = u16_to_binstr(i);

        assert(binstr_to_u16(binstr, 17) == i);

        free(binstr);
    }
}

#endif