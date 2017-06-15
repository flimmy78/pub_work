/*******************************************************************
 *   > File Name: 01-asctime.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun  8 16:03:31 2017
 ******************************************************************/
#if (0)
char *asctime(struct tm *timeptr);
//asctime（）将参数 timeptr 所指的 tm 结构中的信息转换成真实世界
//所使用的时间日期表示方法，然后将结果以字符串形态返回。此函
//数已经由时区转换成当地时间，字符串格式为：
//“Wed Jun 30 21:49:08 1993\n”
//若再调用相关的时间日期函数，此字符串可能会被破坏。此函数与
//ctime 不同处在于传入的参数是不同的结构。
/*converts the calendar time timep to broken-down time representation*/
struct tm *gmtime(const time_t *timep); 
time_t time(time_t *tloc);  //get time in seconds
#endif

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t timep;
    time(&timep);   //获取系统时间
    
    /*转化时间*/
    printf("%s",asctime(gmtime(&timep)));

    return 0;
}
