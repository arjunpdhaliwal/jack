IMAGE = os.iso
BIN = kernel.bin
KERNOBJ = kernel/kernel.a
BOOTSRC = $(wildcard boot/x86_64/*.s)
BOOTOBJS = $(BOOTSRC:.s=.o)

LIBK = libc/libk.a

LINKER = linker.ld

ISOFILES = isofiles
IMAGEPATH = isofiles/boot

GRUBMKRESCUE = grub-mkrescue

LD = ld
LD_FLAGS = -n

LIBKPATH = libc/
KERNPATH = kernel/
BOOTPATH = boot/x86_64

all : $(IMAGE)

$(IMAGE) : $(BIN)
	cp $(BIN) $(IMAGEPATH)
	$(GRUBMKRESCUE) -o $(IMAGE) $(ISOFILES)

$(BIN) : $(BOOTOBJS) $(KERNOBJ)
	$(LD) $(LD_FLAGS) -o $(BIN) -T $(LINKER) $(BOOTOBJS) $(KERNOBJ) $(LIBK)

$(BOOTOBJS) :
	cd $(BOOTPATH) && make

$(KERNOBJ) : $(LIBK) 
	cd $(KERNPATH) && make

$(LIBK) :
	cd $(LIBKPATH) && make

.PHONY: clean
clean:
	rm -f *.o
	rm -f $(IMAGEPATH)/$(BIN)x
	rm -f $(IMAGE)
	rm -f $(BIN)
	cd $(KERNPATH) && make clean
	cd $(BOOTPATH) && make clean
	cd $(LIBKPATH) && make clean