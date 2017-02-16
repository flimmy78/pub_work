CC = gcc
CFLAGFS = -Wall -g -O0
OBJS = test
SRC = test.c btree.c linkqueue.c seqstack.c
$(OBJS) : $(SRC)
	    $(CC) $(CFLAGFS) -o $@ $^

clean:
	$(RM) $(OBJS) .*.sw?
