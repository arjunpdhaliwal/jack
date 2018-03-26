NASM = nasm
ASM_FLAGS = -f elf64

HEADERFILE = mb_header.s
BOOTFILE = boot.s
STARTFILE = start64.s
INTFILE = interrupts.s
FILES = $(HEADERFILE) $(BOOTFILE) $(STARTFILE) $(INTFILE)
OBJS = $(FILES:.s=.o)

all : $(OBJS)

$(OBJS) :
	$(NASM) $(ASM_FLAGS) $(HEADERFILE)
	$(NASM) $(ASM_FLAGS) $(BOOTFILE)
	$(NASM) $(ASM_FLAGS) $(STARTFILE)
	$(NASM) $(ASM_FLAGS) $(INTFILE)

.PHONY: clean
clean:
	rm -f *.o