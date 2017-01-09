
CC=arm-goke-linux-gnueabi-gcc

uart:
	$(CC) -g -Wall -c -o gk_uart.o gk_uart.c

uartcap:
	$(CC) -g -Wall -c -o gk_uartcap.o gk_uartcap.c -pthread

APP:uartcap uart
	$(CC) -g -Wall -o app_uart gk_uart.o gk_uartcap.o -pthread

clean:
	$(RM) a.out *.o app_uart
