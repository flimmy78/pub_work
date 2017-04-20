
#all: ipmode moveadd pad screen1 color keypad multiw1 subscl

#Uncomment and edit the line below if necessary
#CFLAGS=-I/usr/include/ncurses

#LDFLAGS=-lncurses

SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall
INC = -lcurses

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(INC)

clean:
	$(RM) $(BIN) a.out *.*.sw?

.PHONY:all clean



