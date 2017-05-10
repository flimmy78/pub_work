SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
LDFLAGS = -lgdbm_compat -lgdbm
INC = -I/usr/include/gdbm

all:$(BIN)

$(BIN):%:%.c
#@echo $(SRC) 
#@echo $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(INC)

clean:
	$(RM) a.out $(BIN) .*.*.sw?

.PHONY:all clean
