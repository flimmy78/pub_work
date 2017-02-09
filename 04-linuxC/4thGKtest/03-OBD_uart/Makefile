.PHONY:
.IGNORE:install clean

CC=arm-goke-linux-gnueabi-gcc
CFLAGS= -g -Wall
DEP_LIB:= -lpthread

CUR_DIR:=$(shell /bin/pwd)
RUN_DIR:=/opt/goke/rootfs_glibc/my_modules/
OBJ:=common_used_test sd_file_test dvr_uart_test

common_used_test:
	$(CC) $(CFLAGS) common_used_test.c -o common_used_test

sd_file_test:
	$(CC) $(CFLAGS) sd_file_test.c  sd_file.c -o sd_file_test

dvr_uart_test:
	$(CC) $(CFLAGS)  sd_file.c dvr_uart.c dvr_uart_test.c -o dvr_uart_test

install:
	cp -rf common_used_test $(RUN_DIR)
	cp -rf sd_file_test $(RUN_DIR)
	cp -rf dvr_uart_test $(RUN_DIR)

clean:
	$(RM) a.out $(OBJ)




