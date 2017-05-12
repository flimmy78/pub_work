SRC = ${wildcard *.cpp}
BIN = ${patsubst %.cpp, %, $(SRC)}
CC = g++
CFLAGS = -g -Wall

all:$(BIN)

$(BIN):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out .*.*.sw? $(BIN)

.PHONY:clean all
