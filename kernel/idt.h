#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#define MAX_INTERRUPTS 256
#define GDT_SEL 0x8

#define IDT_DESC_TASK 0x05 // 00000101

#define IDT_DESC_TRAP16 0x07 // 00000111
#define IDT_DESC_TRAP32 0x0F // 00001111

#define IDT_DESC_INT16 0x06	// 00000110
#define IDT_DESC_INT32 0x0E	// 00001110

#define IDT_DESC_RING0 0x00 // 00000000
#define IDT_DESC_RING1 0x20	// 00100000
#define IDT_DESC_RING2 0x40	// 01000000
#define IDT_DESC_RING3 0x60	// 01100000

#define IDT_DESC_PRESENT	0x80	//10000000

struct __attribute__((__packed__)) IDTEntry
{
   uint16_t offset_1; // offset bits 0..15
   uint16_t selector; // a code segment selector in GDT or LDT
   uint8_t ist;       // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
   uint8_t type_attr; // type and attributes
   uint16_t offset_2; // offset bits 16..31
   uint32_t offset_3; // offset bits 32..63
   uint32_t zero;     // reserved
};

struct __attribute__((__packed__)) IDTr
{
    uint16_t limit; // size of gdt
    uint64_t base; // base address of gdt
};

void idt_init();
void idt_set_entry(uint64_t i, uint8_t flags, uint16_t sel, void (*irq)());
void set_isrs(uint16_t code_selector);

void _isr0();
void _isr1();
void _isr2();
void _isr3();
void _isr4();
void _isr5();
void _isr6();
void _isr7();
void _isr8();
void _isr9();
void _isr10();
void _isr11();
void _isr12();
void _isr13();
void _isr14();
void _isr15();
void _isr16();
void _isr17();
void _isr18();
void _isr19();
void _isr20();
void _isr21();
void _isr22();
void _isr23();
void _isr24();
void _isr25();
void _isr26();
void _isr27();
void _isr28();
void _isr29();
void _isr30();
void _isr31();
void _isr32();

void _irq0();
void _irq1();
void _irq2();
void _irq3();
void _irq4();
void _irq5();
void _irq6();
void _irq7();
void _irq8();
void _irq9();
void _irq10();
void _irq11();
void _irq12();
void _irq13();
void _irq14();
void _irq15();

#endif