/*******************************************************************
 *   > File Name: 03-calloc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 10 Feb 2017 09:46:30 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if (0)
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
//function:在内存的动态存储区中分配n个长度为size的连续空间，
//函数返回一个指向分配起始地址的指针；如果分配不成功，返回NULL。
//return:
#endif

/*动态配置10个struct test空间*/
struct test
{
    int a[10];
    char b[20];
};

int main(int argc, char* argv[])
{
#if 0
    struct test *ptr = NULL;
    ptr = calloc(10,sizeof(struct test));
    printf("ptr...%p\n",ptr);
#endif
    if(argc < 2)
    {
        printf("Usage : %s 1/2\n",argv[0]);
        return (-1);
    }

    char Quantity = *(char *)argv[1];
    switch(Quantity)
    {
        case '1':
            {
                char *str = NULL;

                /*分配内存空间*/
                str = (char*)calloc(10,sizeof(char));
                printf("sizeof str = %d\n",sizeof str);/*地址的长度*/
                /*申请后的内存区域已清零*/
                int i;
                for(i = 0; i <= 10; i++)
                {
                    printf("%d",str[i]);
                }
                puts("");
                //printf("%s\n",str);
                /*将hello写入*/
                strcpy(str,"Hello");
                /*显示变量内容*/
                printf("String is :%s\n",str);
                /*释放空间*/
                free(str);
            }
            break;
        case '2':
            {
                int i;
                int *pn = (int*)calloc(10,sizeof(int));
                for(i = 0; i < 10; i++)
                    printf("%d",pn[i]);
                printf("\n");
                free(pn);
            }
            break;
        default:
            printf("No such function for the num\n");
    }

    return 0;
}
