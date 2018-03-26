#include <system.h>
#include <interrupt/pic.h>

void irq_server(int irq)
{
    
    pic_eoi();
    return;
}