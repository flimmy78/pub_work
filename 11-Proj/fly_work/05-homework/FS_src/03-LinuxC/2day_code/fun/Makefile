CC = gcc
CFLAGS = -Wall -g -O0

#调用函数
SRC = ${wildcard *.c}
OBJS = ${patsubst %.c,%,$(SRC)}

#伪目标all：目的为了建立依赖关系

all:$(OBJS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^	

clean:
	@$(RM) $(OBJS) .*.sw?
