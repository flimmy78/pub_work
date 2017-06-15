/*******************************************************************
 *   > File Name: 16-strcoll.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 14:54:41 2017
 ******************************************************************/
#if (0)
int strcoll(const char *s1, const char *s2);
//@FUNC:strcoll（）会依环境变量 LC_COLLATE 所指定的文字排列次序来比
//较 s1 和 s2 字符串。
//若参数 s1 和 s2 字符串相同则返回 0。s1 若大于 s2 则返回大于 0 的
//值。s1 若小于 s2 则返回小于 0 的值
//若 LC_COLLATE 为“POSIX”或“C”，则 strcoll（）与 strcmp（）
//作用完全相同
#endif

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}
