
#include "pic.h"
#include <stdint.h>
#include <sys/io.h>

void pic_init() {
    uint8_t icw = ICW1_INIT | ICW1_ICW4_EXPECT;

	outb(icw, PIC1_COMMAND);      // starts initialization sequence (in cascade mode)
	outb(icw, PIC2_COMMAND);

	outb(PIC1_IRQ_OFFSET, PIC1_DATA);  // ICW2: Master PIC vector offset
	outb(PIC2_IRQ_OFFSET, PIC2_DATA);  // ICW2: Slave PIC vector offset
	
    outb(4, PIC1_DATA); // ICW3: tell Master PIC that slave PIC at IRQ2 (0000 0100)
    outb(2, PIC2_DATA); // ICW3: tell Slave PIC its cascade identity (0000 0010)
 
	outb(ICW4_8086, PIC1_DATA);
	outb(ICW4_8086, PIC2_DATA);
}

// Sends the correct End Of Interrupt command to the PIC
void pic_eoi(unsigned int int_no) {
    if (int_no >= 40) {
        outb(0x20, PIC2);
    }
    outb(0x20, PIC1);
}