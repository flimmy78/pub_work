/*******************************************************************
 *   > File Name: 03-lfind.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 15 16:32:58 2017
 ******************************************************************/
#if (0)
void *lfind(const void *key, const void *base, size_t *nmemb, size_t size, int(*compar)(const void *, const void *));
//线性搜索
//lfind(（）利用线性搜索在数组中从头至尾一项项查找数据。参数
//key 指向欲查找的关键数据，参数 base 指向要被搜索的数组开头地
//址，参数 nmemb 代表数组中的元素数量，每一元素的大小则由参
//数 size 决定，最后一项参数 compar 为一函数指针，这个函数用来
//判断两个元素是否相同，若传给 compar 的异地个参数所指的元素
//数据和第二个参数所指的元素数据相同时则返回 0，两个元素数据
//不相同则返回非 0 值。lfind（）与 lsearch（）不同点在于，当找不
//到关键数据时 lfind()仅会返回 NULL，而不会主动把该笔数据加入
//数组尾端。
//找到关键数据则返回找到的该笔元素的地址，如果在数组中找不到
//关键数据则返回空指针（NULL）
#endif

#include <stdio.h>
#include <search.h>

int main(int argc, char* argv[])
{
    return 0;
}
