/*******************************************************************
 *   > File Name: 02-putenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 04:07:43 PM CST
 ******************************************************************/
#if (0)
int putenv(char *string);/*改变或增加环境变量*/
//putenv（）用来改变或增加环境变量的内容。参数 string 的格式为
//name＝value， 如果该环境变量原先存在，则变量内容会依参数 string
//改变，否则此参数内容会成为新的环境变量。
//执行成功则返回 0，有错误发生则返回-1。
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *p;
    if(p = (char*)getenv("USER")){
        printf("Before putenv :USER = %s\n",p);/*获取、打印USER环境变量*/
    }else{
        printf("getenv USER err\n");exit(1);/*获取失败，退出进程*/
    }

    //printf("%d\n",(int)NULL);/*空指针，输出0*/

    putenv("USER=test");/*改变环境变量*/

    printf("After  putenv :USER = %s\n",(char*)getenv("USER"));/*打印环境变量*/

    return 0;
}
