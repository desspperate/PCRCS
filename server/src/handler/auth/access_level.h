#ifndef ACCESS_LEVEL_H
#define ACCESS_LEVEL_H

typedef enum {
    NO,
    FULL
} access_level;

typedef unsigned char u8;

typedef union {
    u8 b [sizeof(access_level)];
    access_level i;
} raw_access_level;


#endif