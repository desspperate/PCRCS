typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned       u32;

typedef union {
    u8  bytes [2];
    u16 s;
} u16_raw;

typedef enum {
    USER,
    ADMIN,
    SYSTEM,
} rtypes;

#define BUF_LEN 256