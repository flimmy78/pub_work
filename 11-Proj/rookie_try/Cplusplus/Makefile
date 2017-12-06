SRC = ${wildcard *.cpp}
BIN = ${patsubst %.cpp, %, $(SRC)}
CFLAGS = -g -Wall -ansi
CC = g++

all:$(BIN)

$(BIN):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out .*.*.sw? $(BIN)

.PHONY:all clean
