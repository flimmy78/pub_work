CC = gcc
CFLAGFS = -Wall -g -O0
OBJS = test
SRC = test.c linklist.c
all:josephu $(OBJS)
$(OBJS) : $(SRC)
	    $(CC) $(CFLAGFS) -o $@ $^

josephu : josephu.c linklist.c
	    $(CC) $(CFLAGFS) -o $@ $^

clean:
	$(RM) $(OBJS) josephu .*.sw?
