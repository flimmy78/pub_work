SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
#TEST = ${subst ee,EE,feet on the street}
#STR = ${strip $(TEST)}
#STR2 = ${strip a b c d}

#test:
#	@echo ${SRC}
#	@echo ${BIN}
#	@echo ${TEST}
#	@echo ${STR}
#	@echo ${STR2}

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) .*.sw?

.PHONY:all clean
