#include <sys/io.h>
#include <stdint.h>

void outb(uint8_t value, unsigned short int port)
{
    __asm__ volatile ( "outb %0, %1" : : "a"(value), "Nd"(port) );
}

uint8_t inb(unsigned short int port)
{
    uint8_t value;
    __asm__ volatile ( "inb %1, %0" : "=a"(value) : "Nd"(port) );
    return value;
}