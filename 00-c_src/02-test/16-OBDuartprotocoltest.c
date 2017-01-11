/*******************************************************************
 *   > File Name: 16-OBDuartprotocoltest.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 11 Jan 2017 02:10:25 PM CST
 ******************************************************************/

#include <stdio.h>

#define OBD_UART_PROTOCOL_HEAD  0xBB
#define OBD_UART_PROTOCOL_TAIL  0xEE

int main(void)
{
    printf("%d\n",OBD_UART_PROTOCOL_HEAD);
    printf("%d\n",OBD_UART_PROTOCOL_TAIL);
    printf("%c\n",OBD_UART_PROTOCOL_HEAD);
    printf("%c\n",OBD_UART_PROTOCOL_TAIL);
    puts("------------------------------------");

    return 0;
}
