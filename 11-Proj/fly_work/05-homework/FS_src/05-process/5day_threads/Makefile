# Makefile
#

#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET = /opt/filesystem
endif

DEBUG = -g -O0 -Wall 

CFLAGS += $(DEBUG)
ifdef CROSS_COMPILE
PROGS = ${patsubst %.c, %, ${wildcard *.c}} 
else
PROGS = ${filter-out thread-attr, ${patsubst %.c, %, ${wildcard *.c}}}	
endif
all : $(PROGS)

install: $(PROGS)
ifdef CROSS_COMPILE
	mkdir $(TARGET)/root/long_term/thread -p
	cp $(PROGS) $(TARGET)/root/long_term/thread -f
endif
% : %.c
	$(CC)  $(CFLAGS)  $< -o $@ -lpthread

.PHONY: uninstall clean dist

uninstall :
ifdef CROSS_COMPILE
	cd $(TARGET)/root/long_term/thread && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(PROGS) core *.gz

dist: clean
	tar czf ../farsight_threads_demo_all_for_1604.tar.gz ../threads
	
