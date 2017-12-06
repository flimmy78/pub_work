.IGNORE:$(BIN)

SRC=${wildcard *.c *.cpp}
C_BIN=${patsubst %.c, %, $(SRC)}
CPP_BIN=${patsubst %.cpp, %, $(C_BIN)}
BIN= $(CPP_BIN)
OBJ= main
CFLAGS = -g -Wall

#test:
#	@echo ${SRC}
#	@echo ${BIN}
#	@echo ${OBJ}
#	@echo $(CC)
#	@echo $(CXX)

all:$(BIN)

$(BIN):
	$(CXX) -o $(OBJ) $(SRC) $(CFLAGS)

clean:
	$(RM) $(OBJ)



