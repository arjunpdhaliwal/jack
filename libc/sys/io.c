#include <sys/io.h>

void outb(unsigned char value, unsigned short int port)
{
    __asm__ volatile ( "outb %0, %1" : : "a"(value), "Nd"(port) );
}