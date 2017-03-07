/*******************************************************************
 *   > File Name: 04-index.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 14 Feb 2017 02:38:42 PM CST
 ******************************************************************/

#include <stdio.h>
#include <strings.h>

#if (0)
char *index(const char *s, int c);/*查找字符串第一个出现的指定字符*/
char *rindex(const char *s, int c);
//@return :成功返回匹配字符串的指针；未发现，返回NULL
#endif

int main(int argc, char* argv[])
{
    char *STR = "ABCDE6789012345EDCBA";
    char *Fp, *Lp;
    printf("STR :%s\t STR--%p\n",STR,STR);
    
    /*找到字符串STR第一次出现字符'E'的地方*/
    Fp = index(STR, 'E');
    printf("index Fp :%s\t Fp----%p\n",Fp,Fp);

    /*找到字符串STR最后出现字符'E'的地方*/
    Lp = rindex(STR, 'E');
    printf("rindex Lp :%s\t Lp----%p\n",Lp,Lp);


    return 0;
}
