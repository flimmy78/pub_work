SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall
OBJ_WRITE_LOCK=write_lock

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^

clean:
	$(RM) a.out $(BIN)	.*.*.swp $(OBJ_WRITE_LOCK)

.PHONY:clean all
