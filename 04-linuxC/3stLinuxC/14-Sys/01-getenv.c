/*******************************************************************
 *   > File Name: 01-getenv.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 27 Feb 2017 03:52:57 PM CST
 ******************************************************************/
#if (0)
char *getenv(const char *name);/*取得环境变量内容*/
//执行成功则返回指向该内容的指针，找不到符合的环境变量名称则
//返回 NULL
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc < 2){/*判断命令行是否输入参数*/
        printf("Usage : %s env-name\n",argv[0]);exit(1);
    }

    char *env;/*定义一个字符串指针*/
    
    if((env = getenv(argv[1])) == NULL){
        printf("getenv %s err\n",argv[1]);exit(1);/*获取失败*/
    }
    
    printf("%s=%s\n",argv[1],env);/*获取成功，打印环境变量*/

    return 0;
}
