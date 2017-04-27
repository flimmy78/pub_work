SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) a.out $(BIN)

.PHONY:clean all
