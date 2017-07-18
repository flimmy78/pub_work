SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) a.out $(BIN)

.PHONY:clean all
