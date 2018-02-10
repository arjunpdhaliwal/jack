CC = gcc
CCFLAGS = -Wall -c -nostdlib
FILES = main.c
OBJS = $(FILES:.c=.o)

all : $(OBJS)

$(OBJS) :
	$(CC) $(FILES) $(CCFLAGS)

.PHONY: clean
clean:
	rm -f *.o