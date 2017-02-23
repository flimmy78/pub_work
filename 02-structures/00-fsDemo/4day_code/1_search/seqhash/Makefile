CC = gcc
CFLAGFS = -Wall -g -O0
OBJS = hashsearch
SRC = hashsearch.c hash.c
$(OBJS) : $(SRC)
	    $(CC) $(CFLAGFS) -o $@ $^  -lm

clean:
	$(RM) $(OBJS) .*.sw?
