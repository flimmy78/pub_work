SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAG= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) a.out $(BIN) myfifo .*.*.swp

.PHONY:clean all
