CC = ~/Downloads/cross/x86_64-elf-4.9.1-Linux-x86_64/bin/x86_64-elf-gcc
GCC = gcc
AR = ar

CCFLAGS = -Wall -c -g -ffreestanding -nostdlib -I../libc/include -I./include

MAINSRCFILES = main.c system.c
MAINOBJS = $(MAINSRCFILES:.c=.o)

LIBINTERRUPTPATH = ./interrupt
LIBINTERRUPT = interrupt/interrupt.a

KERNEL = kernel.a

all : $(KERNEL)

$(KERNEL) : $(MAINOBJS) $(LIBINTERRUPT)
	$(AR) x $(LIBINTERRUPT)
	$(AR) rcs $(KERNEL) *.o

$(MAINOBJS) :
	$(CC) $(MAINSRCFILES) $(CCFLAGS)

$(LIBINTERRUPT) :
	cd $(LIBINTERRUPTPATH) && make

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.a
	cd $(LIBINTERRUPTPATH) && make clean