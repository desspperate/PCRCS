def binstr_to_u8():
    with open('binstr_to_u8_test.c', 'w') as f:
        f.write("""#include <assert.h>

#include "../util/binstr_to_u8.c"
#include "../util/u8_pow.c"

void binstr_to_u8_test() {
""")
        for i in range(2**8):
            binstr = '\\'.join(list(bin(i)[2:]))   

            f.write(f'    assert(binstr_to_u8("\{binstr}\\xff", {len(bin(i)) - 1}) == {i});\n')
        f.write('}')
        
        
def binstr_to_u16():
    with open('binstr_to_u16_test.c', 'w') as f:
        f.write("""#include <assert.h>

#include "../util/binstr_to_u16.c"
#include "../util/u16_pow.c"

void binstr_to_u16_test() {
""")
        for i in range(2**16):
            binstr = '\\'.join(list(bin(i)[2:]))   

            f.write(f'    assert(binstr_to_u16("\{binstr}\\xff", {len(bin(i)) - 1}) == {i});\n')
        f.write('}')
    

if __name__ == '__main__':
    binstr_to_u8()
    binstr_to_u16()