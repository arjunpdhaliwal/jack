CC = ~/Downloads/cross/x86_64-elf-4.9.1-Linux-x86_64/bin/x86_64-elf-gcc
GCC = gcc
CCFLAGS = -Wall -c -g -ffreestanding -nostdlib -I../libc/include
FILES = main.c system.c idt.c isr.c irq.c pic.c
OBJS = $(FILES:.c=.o)

all : $(OBJS)

$(OBJS) :
	$(CC) $(FILES) $(CCFLAGS)

.PHONY: clean
clean:
	rm -f *.o