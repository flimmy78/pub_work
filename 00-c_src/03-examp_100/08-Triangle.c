/*******************************************************************
 *   > File Name: 08-Triangle.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sun 15 Jan 2017 11:42:52 AM CST
 ******************************************************************/
/*杨辉三角，提炼的数学公式为：
 * x,表示行；y，表示列；
 *1.    c(x,y) = 1  ,(x=1,x= N+1);
 *2.    c(x,y) = (c(x-1,y-1) + c(x-1,y)),其他
 *根据以上递归的数学表达式编程
 */

#include <stdio.h>

#if 0
int c(int x, int y);

int main(int argc, char* argv[])
{
    int i, j, n = 13;
    printf("N = ");
    if(n > 12)
        scanf("%d",&n);
    for(i = 0; i <= n; i++)
    {
        for(i=0; i < 12 -i; i++)
            printf("  ");
        for(j = 1; j < i+2; j++)
            printf("%6d",c(i,j));
        printf("\n");
    }
    return 0;
}

int c(int x, int y)
{
    int z;
    if((y == 1)||(y == x+1))
        return (1);
    z = c(x-1, y-1) + c(x-1, y);
    return (z);
}
#else
/*********************************************
 *@function:
 *@param(int x):表示行
 *@param(int y):表示列
 ********************************************/
int c(int x, int y){
    int z;
    /*如果处在行首或者行尾，返回1*/
    if((y == 1) || (y == (x + 1)))
        return (1);
    /*否则返回z*/
    z = c((x - 1),(y - 1)) + c((x - 1), y);
    return (z);
}

int main(void)
{
    int i,j,N,k;

    /*行列关系:j = i + 1*/
    printf("Input N :");
    scanf("%d",&N);
    for(i = 0; i < N; i++){

            /*打印空格*/
#if (1)
            for(k = (N - i- 1); k >= 0; k--){
                printf("    ");
            }
#endif 

        /* 打印每一行*/
        for(j = 1; j <= (i + 1); j++){
            /*打印值*/
            printf("%6d  ",c(i,j));
        }
        /*换行*/
        puts("");
    }
}

#endif
