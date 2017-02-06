
CC=arm-goke-linux-gnueabi-gcc

CUR_DIR:=$(shell /bin/pwd)
RUN_DIR=/opt/goke/rootfs_glibc/my_modules
DEP_LIB:= -lpthread
CFLAGS := -g -Wall
CPPFLAGS:= -g -Wall

gk_uart_v0:
	$(CC) $(CFLAGS) gk_uart.c -o gk_uart_v0  $(DEP_LIB)

install:
	cp -rf gk_uart_v0 $(RUN_DIR)

clean:
	$(RM) a.out *.o gk_uart_v0
