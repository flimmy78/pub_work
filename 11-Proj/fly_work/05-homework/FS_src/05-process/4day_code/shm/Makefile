# Makefile
#

#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET = /opt/filesystem
endif


DEBUG = -g -O0 -ggdb
#DEBUG = -g -O2 
CFLAGS += $(DEBUG)

PROGS = ${patsubst %.c, %, ${wildcard *.c}} 

all : $(PROGS)

install: $(PROGS)
ifdef CROSS_COMPILE
	mkdir $(TARGET)/root/long_term/ipc -p
	cp $(PROGS) $(TARGET)/root/long_term/ipc -f
endif
%.o : %.c
	$(CC)  $(CFLAGS) -c $< -o $@

.PHONY: uninstall clean dist

uninstall :
ifdef CROSS_COMPILE
	cd $(TARGET)/root/long_term/ipc && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(PROGS) core *.gz

dist: clean
	tar czf ../farsight_ipc_shm_for_1604_update.tar.gz ../shm
	
