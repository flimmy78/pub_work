CC = gcc
#CC = arm-goke-linux-gnueabi-gcc
CFLAGS = -Wall -g -O0 -std=c99

SRC = ${wildcard *.c}
OBJS = ${patsubst %.c,%,$(SRC)}

all:$(OBJS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^ -ljson


clean:
	$(RM) $(OBJS) .*.sw?
