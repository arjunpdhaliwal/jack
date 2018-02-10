IMAGE = os.iso
BIN = kernel.bin
KERNOBJ = kernel/main.o

FILES = mb_header.s boot.s start64.s
BOOTOBJS = $(FILES:.s=.o)
LINKER = linker.ld

ISOFILES = isofiles
IMAGEPATH = isofiles/boot

GRUBMKRESCUE = grub-mkrescue

NASM = nasm
ASM_FLAGS = -f elf64

LD = ld
LD_FLAGS = -n

KERNPATH = kernel/ 

all : $(IMAGE)

$(IMAGE) : $(BIN)
	cp $(BIN) $(IMAGEPATH)
	$(GRUBMKRESCUE) -o $(IMAGE) $(ISOFILES)

$(BIN) : $(BOOTOBJS) $(KERNOBJ)
	$(LD) $(LD_FLAGS) -o $(BIN) -T $(LINKER) $(BOOTOBJS) $(KERNOBJ)	

%.o : %.s
	$(NASM) $(ASM_FLAGS) $<

$(KERNOBJ) : 
	cd $(KERNPATH) && make

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(IMAGEPATH)/$(BIN)
	rm -f $(IMAGE)
	rm -f $(BIN)
	cd $(KERNPATH) && make clean