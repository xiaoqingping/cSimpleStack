SOURCE = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCE))
CC = gcc
CFLAGS = -g -Wall 
Main:$(OBJS)
	$(CC) $(CFLAGS) -o Main $(OBJS)

depends:$(SOURCE)
	$(CC) -MM $(CFLAGS) $(SOURCE) > depends
-include depends

.PHONY:clean
clean:
	rm *.o *.exe depends
