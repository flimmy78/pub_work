SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}

CFLAGS = -g -Wall
LIB = -lcrypt

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

clean:
	$(RM) a.out .*.*.sw? $(BIN)

.PHONY:all clean
