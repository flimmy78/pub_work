SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall

all:$(BIN)

$(BIN):%:%.c
	@echo $(SRC) 
	@echo $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out $(BIN) .*.*.sw?

.PHONY:all clean
