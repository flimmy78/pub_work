/*******************************************************************
 *   > File Name: 03-setenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 04:32:40 PM CST
 ******************************************************************/
#if (0)
int setenv(const char *name, const char *value, int overwrite);/*改变或增加环境变量*/
//setenv（）用来改变或增加环境变量的内容。参数 name 为环境变量
//名称字符串，参数 value 则为变量内容，参数 overwrite 用来决定是
//否要改变已存在的环境变量。如果 overwrite 不为 0，而该环境变量
//原已有内容，则原内容会被改为参数 value 所指的变量内容：如果
//overwrite 为 0，且该环境变量已有内容，则参数 value 会被忽略
//执行成功则返回 0，有错误发生时返回-1。
#endif

#include <stdio.h>
#include <stdlib.h>

#define OVERWRITE   0

int main(int argc, char* argv[])
{
    char *p;

    if(p = getenv("USER")){/*获取环境变量*/
        printf("USER = %s\n", p);
    }

    if(!setenv("USER", "test", OVERWRITE)){/*增加环境变量*/
        printf("USER = %s\n", getenv("USER"));
    }

    unsetenv("USER");/*删除环境变量*/
    printf("USER = %s\n", getenv("USER"));


    return 0;
}
