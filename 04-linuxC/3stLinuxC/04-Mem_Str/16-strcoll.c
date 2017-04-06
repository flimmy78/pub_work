/*******************************************************************
 *   > File Name: 16-strcoll.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 08 Mar 2017 09:55:25 AM CST
 ******************************************************************/
#if (0)
int strcoll(const char *s1, const char *s2);
//@FUNC:依环境变量 LC_COLLATE 所指定的文字排列次序来比
//较 s1 和 s2 字符串
//若 LC_COLLATE 为“POSIX”或“C” ，则 strcoll（）与 strcmp（）
//作用完全相同
#endif

#include <stdio.h>
/*INC for strcoll*/
#include <string.h>

int main(int argc, char* argv[])
{
    char *s1 = "abcde";
    char *s2 = "ABCDE";
    int ret;

    ret = strcoll(s1, s2);
    printf("ret = %2d\n",ret);
    ret = strcoll(s1, s1);
    printf("ret = %2d\n",ret);
    ret = strcoll(s2, s1);
    printf("ret = %2d\n",ret);

    return 0;
}
