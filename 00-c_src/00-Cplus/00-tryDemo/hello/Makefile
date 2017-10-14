SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^ ${CFLAGS}

hello:
	@echo "预处理"
	gcc -E Hello.c -o hello.i
	@echo "编译"
	gcc -S hello.i -o hello.s
	@echo "汇编"
	gcc -c hello.s -o hello.o
	@echo "链接"
	gcc hello.o -o hello

clean:
	$(RM) hello hello.* $(BIN)

.PhONY:all clean hello
