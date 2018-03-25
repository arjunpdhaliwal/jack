#ifndef PIC_H
#define PIC_H

#define PIC1		    0x20		/* IO base address for master PIC */
#define PIC2		    0xA0		/* IO base address for slave PIC */

#define PIC1_COMMAND	PIC1
#define PIC1_DATA	   (PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	   (PIC2+1)

#define ICW1_ICW4_EXPECT	0x01		/* ICW4 (not) needed */
#define ICW1_INIT	        0x10		/* Initialization - required! */
#define ICW4_8086	        0x01		/* 8086/88 (MCS-80/85) mode */
 
#define PIC1_IRQ_OFFSET 0x20
#define PIC2_IRQ_OFFSET 0x28

void pic_init();
void pic_eoi();

#endif