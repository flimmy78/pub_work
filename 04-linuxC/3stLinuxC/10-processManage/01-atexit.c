/*******************************************************************
 *   > File Name: 01-atexit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun 16 17:58:27 2017
 ******************************************************************/
#if (0)
int atexit(void (*function)(void));
//用来设置一个程序正常结束前调用的函数。当程序通过调
//用 exit（）或从 main 中返回时，参数 function 所指定的函数会先被
//调用，然后才真正由 exit（）结束程序。
//如果执行成功则返回 0，否则返回-1，失败原因存于 errno 中。
#endif

#include <stdio.h>
#include <stdlib.h>

void my_exit(void){
    printf("Before exit() !\n");
}

int main(int argc, char* argv[])
{
    printf("%s,%d,%s\n", __FILE__, __LINE__, __func__);
    atexit(my_exit);

    return 0;
}
