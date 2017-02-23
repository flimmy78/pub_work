CC = gcc
CFLAGS = -Wall -g -O0

SRC = ${wildcard *.c}
OBJS = ${patsubst %.c,%,$(SRC)}

all:$(OBJS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^
	touch t1 t2

clean:
	$(RM) $(OBJS) .*.sw? t1 t2
