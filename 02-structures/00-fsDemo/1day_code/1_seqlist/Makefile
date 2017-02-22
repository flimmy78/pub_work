CC = gcc
CFLAGFS = -Wall -g -O0
OBJS = test
SRC = test.c seqlist.c
$(OBJS) : $(SRC)
	    $(CC) $(CFLAGFS) -o $@ $^

clean:
	$(RM) $(OBJS) .*.sw?
