SRC=${wildcard *.c}
BIN=${patsubst %.c, %, $(SRC)}
CFLAGS= -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) -o $@ $^ $(CFLAGS)
	@touch src_file && ls -al >> src_file

SRC_FILE:
	cat *.c *.txt >> src_file

clean:
	$(RM) a.out $(BIN) .*.*.sw? test.txt src_file dst_file

.PHONY:all clean
