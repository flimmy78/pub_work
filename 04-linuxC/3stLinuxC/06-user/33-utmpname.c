/*******************************************************************
 *   > File Name: 33-utmpname.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 12 18:24:05 2017
 ******************************************************************/
#if (0)
int utmpname(const char *file);
//用来设置 utmp 文件的路径，以提供 utmp 相关函数的
//存取路径。如果没有使用 utmpname（）则默认 utmp 文件路径为
///var/run/utmp。
#endif

#include <stdio.h>
#include <utmp.h>

int main(int argc, char* argv[])
{
    return 0;
}
