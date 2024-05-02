#ifndef HEADER_HANDLER_H
#define HEADER_HANDLER_H

typedef unsigned short u16;
typedef unsigned char  u8;

extern void get_rtype_and_rcode(u8 *rtype_ptr, u16 *rcode_ptr, u16 rheader);

#endif