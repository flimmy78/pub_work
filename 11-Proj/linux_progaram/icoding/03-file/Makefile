SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out $(BIN)  .*.*.sw? file.out

.PHONY:all clean

