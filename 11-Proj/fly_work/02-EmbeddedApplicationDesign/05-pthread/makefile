#01-thread.c	创建三个线程，每个线程执行同一个执行函数；\
	执行5次循环（可以看成5个小任务），每次循环随机等待1~6s\
	意义在于模拟每个任务的完成时间是随机的。
SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) a.out $(BIN) .*.*.sw? myfifo

.PHONY:all clean

