CC=arm-goke-linux-gnueabi-gcc

uart:
	$(CC) -g -Wall -c -o uart.o app_uart.c

uartcap:
	$(CC) -g -Wall -c -o uartcap.o app_uartcap.c -lpthread

APP:uart uartcap
	$(CC) -g -Wall -o uart_APP uart.o uartcap.o -lpthread

install:
	 cp -rf uart_APP /opt/goke/rootfs_glibc/my_modules/




clean:
	$(RM) a.out *.o uart_APP
