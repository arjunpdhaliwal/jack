#include "system.h"
#include "pic.h"

void irq_server(int irq)
{
    
    pic_eoi();
    return;
}