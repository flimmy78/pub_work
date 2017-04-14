SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
#ALL:
#	@echo $(SRC)
#	@echo $(BIN)
all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) a.out .*.sw?

.PHONY:all clean

