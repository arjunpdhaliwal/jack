#include <stdint.h>

#ifndef _SYS_IO
#define _SYS_IO 1

void outb(uint8_t value, unsigned short int port);
uint8_t inb(unsigned short int port);

#endif
