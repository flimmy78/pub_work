SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall
LIB = -lcurses

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIB)

clean:
	$(RM) $(BIN) a.out *.*.sw?

.PHONY:all clean
