#include <system.h>
#include <interrupt/pic.h>
#include <interrupt/irq.h>

interrupt_handler interrupt_handler_table[16] = {0};

void irq_server(int irq, int arg)
{
    interrupt_handler irq_handler;
	irq_handler = interrupt_handler_table[irq - 32];
    
    if (irq_handler) {
        irq_handler(arg);
    }
    pic_eoi();
    return;
}

void install_interrupt_handler(int i, interrupt_handler func) 
{
    if (func) {
        writel("added interrupt handler");
    } else {
        writel("failed");
    }
    interrupt_handler_table[i] = func;
}