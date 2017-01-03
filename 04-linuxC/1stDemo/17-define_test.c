/*******************************************************************
 *   > File Name: 17-test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 03 Jan 2017 09:06:50 AM CST
 ******************************************************************/

#include <stdio.h>
#include <string.h>

#define UART_BUFFER_MAX_SIZE 512
#define UART_WR_BUFFER_MAX_SIZE (30*1024)
#define UART_DATA_BUFFER_MAX_SIZE   (UART_BUFFER_MAX_SIZE >> 3)

#define UART_CAP_PROTOCOL_HEAD "$FG"

int main(void)
{
    unsigned a1 = UART_BUFFER_MAX_SIZE;
    unsigned a2 = UART_WR_BUFFER_MAX_SIZE;
    unsigned a3 = UART_DATA_BUFFER_MAX_SIZE;

    printf("a1 = %d\ta2 = %d\ta3 = %d\n",a1,a2,a3);
    printf("~\n");
    printf("strlen(UART_CAP_PROTOCOL_HEAD) = %d\n",strlen(UART_CAP_PROTOCOL_HEAD));

    return 0;
}
