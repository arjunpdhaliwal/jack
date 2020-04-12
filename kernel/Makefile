CC = x86_64-elf-gcc
GCC = gcc
AR = ar

CCFLAGS = -Wall -c -g -ffreestanding -nostdlib -I../libc/include -I./include

MAINSRCFILES = main.c system.c
MAINOBJS = $(MAINSRCFILES:.c=.o)

LIBINTERRUPTPATH = ./interrupt
LIBINTERRUPT = interrupt/interrupt.a

LIBDRIVERPATH = ./driver
LIBDRIVER = driver/driver.a

KERNEL = kernel.a

all : $(KERNEL)

$(KERNEL) : $(MAINOBJS) $(LIBINTERRUPT) $(LIBDRIVER)
	$(AR) x $(LIBINTERRUPT)
	$(AR) x $(LIBDRIVER)
	$(AR) rcs $(KERNEL) *.o

$(MAINOBJS) :
	$(CC) $(MAINSRCFILES) $(CCFLAGS)

$(LIBINTERRUPT) :
	cd $(LIBINTERRUPTPATH) && make

$(LIBDRIVER) :
	cd $(LIBDRIVERPATH) && make

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.a
	cd $(LIBINTERRUPTPATH) && make clean
	cd $(LIBDRIVERPATH) && make clean
