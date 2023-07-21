CC = gcc
CFLAGS = -Wall -g -Werror
BUILD = birthday_bomb
OBJS = support.o phases.o

.PHONY: all clean

all: $(BUILD)

clean: 
	$(RM) $(BUILD) $(OBJS)

birthday_bomb: $(OBJS)

support.o:
	$(CC) -Wall -Werror -c support.c -o support.o

phases.o:
	$(CC) -Wall -Werror -c phases.c -o phases.o
