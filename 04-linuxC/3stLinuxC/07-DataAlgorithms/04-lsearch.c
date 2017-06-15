/*******************************************************************
 *   > File Name: 04-lsearch.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 16:36:53 2017
 ******************************************************************/
#if (0)
void *lsearch(const void *key, void *base, size_t *nmemb, size_t size, int(*compar)(const void *, const void *));
//线性搜索
//lsearch（）利用线性搜索在数组中从头至尾一项项查找数据。参数
//key 指向欲查找的关键数据，参数 base 指向要被搜索的数组开头地
//址，参数 nmemb 代表数组中的元素数量，每一元素的大小则由参
//数 size 决定，最后一项参数 compar 为一函数指针，这个函数用来
//判断两个元素是否相同，若传给 compar 的第一个参数所指的元素
//数据和第二个参数所指的元素数据相同时则返回 0，两个元素数据
//不相同则返回非 0 值。如果 lsearch（）找不到关键数据时会主动把
//该项数据加入数组里。
//找到关键数据则返回找到的该笔元素的四肢，如果在数组中找不到
//关键数据则将此关键数据加入数组，再把加入数组后的地址返回
#endif

#include <stdio.h>
#include <search.h>
#include <stdlib.h>

#define NMEMB   50
#define SIZE    10

int compar(const void *a, const void *b){
    return (strcmp((char *)a, (char *)b));
}

int main(int argc, char* argv[])
{
    char data[NMEMB][SIZE] = {"Linux", "freebsd", "solzris", "windows"};
    char key[80], *base, *offset;
    int i, nmemb = NMEMB, size = SIZE;

    for(i = 1; i< 5; i++){
        fgets(key, sizeof(key), stdin);
        key[strlen(key) - 1] = '\0';
        base = data[0];
        offset = (char*)lfind(key, base, &nmemb, size, compar);
        if(offset == NULL){
            printf("%s not found !\n", key);
            offset = (char *)lsearch(key, base, &nmemb, size, compar);
            printf("Add %s to data array\n", offset);
        }else{
            printf("Found :%s\n", offset);
        }
    }

    return 0;
}
