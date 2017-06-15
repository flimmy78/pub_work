/*******************************************************************
 *   > File Name: 02-bsearch.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 14 13:08:31 2017
 ******************************************************************/
#if (0)
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
//二元搜索
//bsearch（）利用二元搜索从排序好的数组中查找数据。参数 key 指
//向欲查找的关键数据，参数 base 指向要被搜索的数组开头地址，参
//数 nmemb 代表数组中的元素数量，每一元素的大小则由参数 size
//决定，最后一项参数 compar 为一函数指针，这个函数用来判断两
//个元素之间的大小关系，若传给 compar 的第一个参数所指的元素
//数据大于第二个参数所指的元素数据则必须回传大于 0 的值，两个
//元素数据相等则回传 0。
//找到关键数据则返回找到的地址，如果在数组中找不到关键数据则
//返回 NULL。
#endif

#include <stdio.h>
#include <stdlib.h>

#define NMEMB   5
#define SIZE    10

int compar(void *a, const void *b){
    return (strcmp((char *)a, (char *)b));
}

int main(int argc, char* argv[])
{
    char data[50][size] = {"linux", "freebsd", "solaris", "sunos", "windows"};
    char key[80], *base, *offset;
    int i, nmemb = NMEMB, size = SIZE;
    
    while(1){
        printf(">");
        fgets(key, sizeof(key), stdin);
        key[strlen(key) - 1] = '\0';
        if(!strcmp(key, "exit"))
            break;
        if(!strcmp(key, "list")){
            for(i = 0; i< nmemb; i++)
                printf("%s\n", data[i]);
            continue;
        }
        base = data[0];
        qsort(base, nmemb, size, compar);
        offset = (char *)bsearch(key, base, nmemb, size, compar);

        if(offset == NULL){
            printf("%s not found !\n", key);
            strcpy(data[nmemb++], key);
            printf("Add %s to data array\n", key);
        }else{
            printf("Found :%s\n", offset);
        }
    }

    return 0;
}
