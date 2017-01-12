
CC=arm-goke-linux-gnueabi-gcc

CFLAGS= -g -Wall

OBJ= *.o

APP_UART:app_uart open_sd_file
	$(CC) $(CFLAGS)  $(OBJ) -o APP_UART

app_uart:
	$(CC) $(CFLAGS) -c app_uart.c -o app_uart.o

open_sd_file:
	$(CC) $(CFLAGS) -c open_sd_file.c -o open_sd_file.o

install:
	cp -f APP_UART /opt/goke/rootfs_glibc/my_modules/

clean:
	$(RM) a.out $(OBJ) APP_UART
