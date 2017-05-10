SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
LDFLAGS = -lsqlite3

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) a.out .*.*.sw? $(BIN)

.PHONY:all clean
