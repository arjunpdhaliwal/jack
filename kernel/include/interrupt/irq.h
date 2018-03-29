#ifndef IRQ_H
#define IRQ_H

typedef void (*interrupt_handler)(int arg);

void irq_server(int irq, int arg);
void install_interrupt_handler(int irq, interrupt_handler func);

#endif