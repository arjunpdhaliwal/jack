#include <string.h>
#include <interrupt/idt.h>

static struct IDTEntry idt[MAX_INTERRUPTS];
static struct IDTr idtr;

void idt_init()
{
    //set up idtr for processor
    idtr.limit = sizeof (struct IDTEntry) * MAX_INTERRUPTS-1;
    idtr.base = (uint64_t) &idt[0];
    memset((void*) &idt[0], 0, sizeof(struct IDTEntry) * MAX_INTERRUPTS - 1);
    set_isrs(0x08);

    __asm__( "lidt %0" :: "m" (idtr) );
} 

void idt_set_entry(uint64_t i, uint8_t flags, uint16_t sel, void (*irq)())
{
    //get base address of interrupt handler
    uintptr_t uiBase = (uintptr_t) &(*irq);

    // store base address into idt
    idt[i].offset_1 = uiBase & 0xffff;
    idt[i].offset_2 = (uiBase >> 16) & 0xffff;
    idt[i].offset_3 = (uiBase >> 32) & 0xffffffff;
    idt[i].zero	= 0;
    idt[i].type_attr = flags;
    idt[i].selector = sel;
    idt[i].ist = 0;
}


void set_isrs(uint16_t code_selector) {
    const uint8_t FLAGS = IDT_DESC_PRESENT | IDT_DESC_INT32;
	idt_set_entry (0, FLAGS, code_selector, _isr0);
	idt_set_entry (1, FLAGS, code_selector, _isr1);
	idt_set_entry (2, FLAGS, code_selector, _isr2);
	idt_set_entry (3, FLAGS, code_selector, _isr3);
	idt_set_entry (4, FLAGS, code_selector, _isr4);
	idt_set_entry (5, FLAGS, code_selector, _isr5);
	idt_set_entry (6, FLAGS, code_selector, _isr6);
	idt_set_entry (7, FLAGS, code_selector, _isr7);
	idt_set_entry (8, FLAGS, code_selector, _isr8);
	idt_set_entry (9, FLAGS, code_selector, _isr9);
	idt_set_entry (10, FLAGS, code_selector, _isr10);
	idt_set_entry (11, FLAGS, code_selector, _isr11);
	idt_set_entry (12, FLAGS, code_selector, _isr12);
	idt_set_entry (13, FLAGS, code_selector, _isr13);
	idt_set_entry (14, FLAGS, code_selector, _isr14);
	idt_set_entry (15, FLAGS, code_selector, _isr15);
	idt_set_entry (16, FLAGS, code_selector, _isr16);
	idt_set_entry (17, FLAGS, code_selector, _isr17);
	idt_set_entry (18, FLAGS, code_selector, _isr18);
	idt_set_entry (19, FLAGS, code_selector, _isr19);
	idt_set_entry (20, FLAGS, code_selector, _isr20);
	idt_set_entry (21, FLAGS, code_selector, _isr21);
	idt_set_entry (22, FLAGS, code_selector, _isr22);
	idt_set_entry (23, FLAGS, code_selector, _isr23);
	idt_set_entry (24, FLAGS, code_selector, _isr24);
	idt_set_entry (25, FLAGS, code_selector, _isr25);
	idt_set_entry (26, FLAGS, code_selector, _isr26);
	idt_set_entry (27, FLAGS, code_selector, _isr27);
	idt_set_entry (28, FLAGS, code_selector, _isr28);
	idt_set_entry (29, FLAGS, code_selector, _isr29);
	idt_set_entry (30, FLAGS, code_selector, _isr30);
	idt_set_entry (31, FLAGS, code_selector, _isr31);

	idt_set_entry (32, FLAGS, code_selector, _irq0);
	idt_set_entry (33, FLAGS, code_selector, _irq1);
	idt_set_entry (34, FLAGS, code_selector, _irq2);
	idt_set_entry (35, FLAGS, code_selector, _irq3);
	idt_set_entry (36, FLAGS, code_selector, _irq4);
	idt_set_entry (37, FLAGS, code_selector, _irq5);
	idt_set_entry (38, FLAGS, code_selector, _irq6);
	idt_set_entry (39, FLAGS, code_selector, _irq7);
	idt_set_entry (40, FLAGS, code_selector, _irq8);
	idt_set_entry (41, FLAGS, code_selector, _irq9);
	idt_set_entry (42, FLAGS, code_selector, _irq10);
	idt_set_entry (43, FLAGS, code_selector, _irq11);
	idt_set_entry (44, FLAGS, code_selector, _irq12);
	idt_set_entry (45, FLAGS, code_selector, _irq13);
	idt_set_entry (46, FLAGS, code_selector, _irq14);
	idt_set_entry (47, FLAGS, code_selector, _irq15);
}