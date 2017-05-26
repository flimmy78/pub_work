##.PHONY:clean
##
##CC=g++
##CFLAGS= -g -Wall
##
##hello=00_hello
##sizeof=01_sizeof
##
##all=$(hello) $(sizeof)
##
##ALL:$(all)
##
##clean:
##	$(RM) a.out  $(all)

SRC = ${wildcard *.cpp}
BIN = ${patsubst %.cpp, %, $(SRC)}
CFLAGS = -g -Wall
CC = g++

all:$(BIN)

$(BIN):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out $(BIN)

.PHONY:clean all
