/*******************************************************************
 *   > File Name: 18-strcspn.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 15:09:14 2017
 ******************************************************************/
#if (0)
size_t strcspn(const char *s, const char *reject);
//@FUNC:返回字符串中连续不含指定字符串内容的字符数
//从参数 s 字符串的开头计算连续的字符，而这些字符都
//完全不在参数 reject 所指的字符串中。简单地说，若 strcspn（）返
//回的数值为 n，则代表字符串 s 开头连续有 n 个字符都不含字符串
//reject 内的字符
//@Return:返回字符串 s 开头连续不含字符串 reject 内的字符数目。
#endif

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char str[] = "Linux was first developed for 384/486-based pcs.";
    printf("str :%s, strlen(str) = %ld\n",str, strlen(str));

    int i;
    for(i = 0; str[i] != 0; i++){
        printf("str[%2d] = %c\t",i , str[i]);
        if((i+1) % 4 == 0){
            puts("");
        }
    }

    printf("%ld\n", strcspn(str, " "));         /*出现“ ”的位置*/
    printf("%ld\n", strcspn(str, "/-"));        /*出现“/-”的位置*/
    printf("%ld\n", strcspn(str, "1234567980"));/*出现“1234657890”的位置*/

    return 0;
}
