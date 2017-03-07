/*******************************************************************
 *   > File Name: 14-strchr.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 02:34:51 PM CST
 ******************************************************************/
#if (0)
char *strchr(const char *s, int c);
/*找出参数 s 字符串中第一个出现的参数 c 地址，然后
 * 将该字符出现的地址返回。*/
char *strrchr(const char *s, int c);
/*找出参数 s 字符串中最后个出现的参数 c 地址，然后
 * 将该字符出现的地址返回。*/
#endif

#include <stdio.h>
/*INC for strchr*/
#include <string.h>

int main(int argc, char* argv[])
{
    char *str = "012345678901234567890123456789";
    char *p;
    
    printf("Str :%s\n",str);
    
    /*找到字符'5'第一次出现的位置*/
    p = strchr(str, '5');
    printf("%s\n",p);
    /*找到字符'5'最后一次出现的位置*/
    p = strrchr(str, '5');
    printf("%s\n",p);
    /*未找到字符'f',返回NULL*/
    if((p = strchr(str, 'f')) == NULL){
        printf("strchr no found \'f\'\n");
    }

    return 0;
}
