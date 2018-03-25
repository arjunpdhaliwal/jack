#include "system.h"

void irq_server()
{
	writel("irq");
    return;
}