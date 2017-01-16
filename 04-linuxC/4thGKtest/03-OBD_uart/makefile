.PHONY:APP clean install

CC=arm-goke-linux-gnueabi-gcc

CFLAGS= -g -Wall

OBJ= *.o
OBJ_APP=APP_UART_1
OBJ_DIR=/opt/goke/rootfs_glibc/my_modules/

APP:DVR_UART SD_FILE
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ_APP)

DVR_UART:
	$(CC) $(CFLAGS) dvr_uart.c -c -o dvr_uart.o

SD_FILE:
	$(CC) $(CFLAGS) sd_file.c -c -o sd_file.o

install:
	cp -f $(OBJ_APP) $(OBJ_DIR)

clean:
	$(RM) a.out $(OBJ) $(OBJ_APP)
