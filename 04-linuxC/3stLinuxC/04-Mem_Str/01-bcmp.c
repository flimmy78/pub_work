/*******************************************************************
 *   > File Name: 01-bcmp.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Jun  9 10:10:29 2017
 ******************************************************************/
#if (0)
bcmp(const void *s1, const void *s2, size_t n);//比较内存内容
//@FUNC：用来比较 s1 和 s2 所指的内存区间前 n 个字节，若参数 n
//为 0，则返回 0。将s1减去s2
//@RETUEN:若参数 s1 和 s2 所指的内存内容都完全相同则返回 0 值，否则返回
//非零值
#endif

#include <stdio.h>
#include <strings.h>

int main(int argc, char* argv[])
{
    char s1[] = "123GHjkl456#";
    char s2[] = "125QAjK=456%";

    int  ret;
#if 0
    for(i = 0; s1[i] != 0; i++){
        printf("s1[%d] = %c\n",i,s1+i );
    }


    for(i = 0; si[i] != 0; i++){
        if((ret = bcmp((void *)s1[i], (void *)s2[i], 1)) == 0){
            
        }
    }
#endif

    if((ret = bcmp((void*)s1, (void*)s2, 3)) == 0){
        printf("ret = %d\n", ret);
    }else{
        printf("ret = %d\n", ret);
    }

    return 0;
}
