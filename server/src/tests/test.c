#include <stdio.h>

//#include "u8_pow_test.c"
//#include "u16_pow_test.c"
#include  "binstr_to_u16_test.c"
//#include "u16_to_binstr_test.c"
//#include "str_to_u16_test.c"
//#include "binstr_to_u8_test.c"

int main(void)
{
    puts("START");
    //u8_pow_test();
    //binstr_to_u8_test();
    //u16_pow_test();
    binstr_to_u16_test();
    //u16_to_binstr_test();
    //str_to_u16_test();
    puts("END");

    return 0;
}