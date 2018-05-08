SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

static:
	$(CC) -o main $(SRC)

clean:
	$(RM) a.out .*.*.swp $(BIN) main

.PHONY:all clean
