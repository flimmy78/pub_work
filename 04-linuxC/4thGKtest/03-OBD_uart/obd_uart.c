/*******************************************************************
 *   > File Name: obd_uart.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 08 Feb 2017 04:03:42 PM CST
 ******************************************************************/

#include "obd_uart.h"

int GK_SetPthreadStackSize(pthread_attr_t* attr, int stacksize)
{
    if(pthread_attr_init(attr) != 0)/*初始化线程属性*/
    {
        perror("pthread_attr_init err");
        return (-1);
    }
    if(pthread_attr_setstacksize(attr,stacksize) != 0 )/*设定线程栈的大小*/
    {
        perror("pthread_attr_setstacksize err");
        return (-1);
    }

    return 0;
}

void* Uart_ReadPthread(void* arg)
{
    /*设置线程分离属性*/
    if((pthread_detach(pthread_self())) != 0)
    {
        printf("%s pathread_deatch err\n",__func__);
        return NULL;
    }

}

void* Uart_WritePthread(void* arg)
{
    /*设置线程分离属性*/
    if((pthread_detach(pthread_self())) != 0)
    {
        printf("%s pathread_deatch err\n",__func__);
        return NULL;
    }

}

int Uart_StartService(void)
{
    /*定义线程标识符*/
    /*定义线程属性对象*/
    /*设置线程栈的大小*/
    /*运行线程函数*/
    return 0;
}
