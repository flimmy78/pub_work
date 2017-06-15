/*******************************************************************
 *   > File Name: 05-qsort.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 16:53:52 2017
 ******************************************************************/
#if (0)
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *,const void *));
//利用快速排序法排列数组
//参数 base 指向欲排序的数组开头地址，参数 nmemb 代表数组中的
//元素数量，每一元素的大小则由参数 size 决定，最后一项参数
//compar 为一函数指针，这个函数用来判断两个元素间的大小关系，
//若传给 compar 的第一个参数所指的元素数据大于第二个参数所指
//的元素数据则必须回传大于零的值，两个元素数据相等则回传 0。
#endif

#include <stdio.h>
#include <stdlib.h>

#define nmemb 7

int compar(void *a, const void *b){
    int *aa = (int *)a, *bb = (int *)b;
    
    if(*aa > *bb)
        return 1;
    if(*aa == *bb)
        return 0;
    if(*aa < *bb)
        return (-1);
}

int main(int argc, char* argv[])
{
    int base[nmemb] = {3,102,5,-2,98,52,18};
    int i;

    for(i = 0; i< nmemb; i++){
        printf("%d ",base[i]);
    }
    puts("");

    qsort(base, nmemb, sizeof(int), compar);

    for(i = 0; i< nmemb; i++){
        printf("%d ",base[i]);
    }
    puts("");

    return 0;
}
