SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) .*.sw? a.out

.PHONY:all clean

#all:
#	@echo $(SRC)
#	@echo $(BIN)
