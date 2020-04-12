CC = x86_64-elf-gcc
GCC = gcc
AR = ar rcs

CCFLAGS = -Wall -c -g -ffreestanding -nostdlib -I../../libc/include -I../include

SRCFILES = idt.c isr.c irq.c pic.c

LIB = interrupt.a
OBJS = $(SRCFILES:.c=.o)

all : $(LIB)

$(LIB) : $(OBJS)
	$(AR) $(LIB) $(OBJS)

$(OBJS) :
	$(CC) $(SRCFILES) $(CCFLAGS)

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.a
