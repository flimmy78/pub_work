/*******************************************************************
 *   > File Name: 13-strcat.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Mar 2017 02:07:51 PM CST
 ******************************************************************/
#if (0)
char *strcat(char *dest, const char *src);
//@FUNC:将参数 src 字符串拷贝到参数 dest 所指的字符串尾。第
//一个参数 dest 要有足够的空间来容纳要拷贝的字符串。
char *strncat(char *dest, const char *src, size_t n);
#endif

#include <stdio.h>
/*INC for strcat*/
#include <string.h>

char *mystrncat(char *dest, const char *src, size_t n);

int main(int argc, char* argv[])
{
    char s1[30] = "STRING(s1)";
    char s2[] = "string(s2)";

    printf("before strcat()  s1:%s\n",s1);
    printf("after  strcat()  s1:%s\n",strcat(s1, s2));
    printf("after strncat(3) s1:%s\n",mystrncat(s1, s2, 3));

    return 0;
}

char *mystrncat(char *dest, const char *src, size_t n){
    size_t d_len = strlen(dest), i;

    for(i = 0; i < n && src[i] != '\0'; i++){
        dest[d_len + i] = src[i];
    }
    dest[d_len + i] = '\0';
    
    return dest;
}
