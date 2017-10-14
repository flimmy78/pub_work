/*******************************************************************
 *   > File Name: 02-ctime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 16:21:10 2017
 ******************************************************************/
#if (0)
char *ctime(const time_t *timep);
//ctime（）将参数 timep 所指的 time_t 结构中的信息转换成真实世界
//所使用的时间日期表示方法，然后将结果以字符串形态返回。此函
//数已经由时区转换成当地时间，字符串格式为“Wed Jun 30 21 :49 08
//1993\n”。若再调用相关的时间日期函数，此字符串可能会被破坏
#endif

#include <stdio.h>
#include <time.h>

#define ENABLE  1
#define DISABLE 0

#define COMPILE_TIME  ENABLE

int main(int argc, char* argv[])
{
    time_t timep;
    time(&timep);

    printf("%s", ctime(&timep));

#if (COMPILE_TIME)
    char compile_time_str[15] = {0};
    char compile_date_str[15] = {0};

    //printf("sizeof(__TIME__) = %d\n", sizeof(__TIME__));
    //printf("sizeof(__DATE__) = %d\n", sizeof(__DATE__));
    sprintf(compile_time_str, "%s", __TIME__);
    sprintf(compile_date_str, "%s", __DATE__);
    //printf("compile time :%s\t%s\n", __TIME__, __DATE__);
    printf("compile time :%s\t%s\n", __TIME__, __DATE__);
    printf("Char :%c\n", compile_date_str[0]);
#endif

        

    return 0;
}
