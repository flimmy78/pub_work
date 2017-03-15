#include <stdio.h>
#include <stdlib.h>

#define N 15
int main()
{
#if 0
    int i;
    int j;
    int a[N][N];
    for(i=0;i<N;i++)
    {
        a[i][0]=1;
        a[i][i]=1; 
    }
    for(i=2;i<N;i++)
    {
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
            printf("%5d ",a[i][j]);
        printf("\n");
    }
#endif
    
    int a = 255;
    int i;

    for(i = sizeof(int)*8 ; i > 0; i--){
        printf("%d", ((a&(1 << (i - 1))) >> (i - 1)));
#if 1
        if((i - 1 ) % 8 == 0)
            printf(" ");
#endif
    }
    puts("");
#if 0  
    a = a&(1 << 0);
    printf("a = %d\n", a);
#endif

#if 0
    for(i = sizeof(int)*8 - 1; i >= 0; i--){
        putchar('0' + (unsigned)(a&(1 << i)) >> i);
        if((i) % 8 == 0){
            printf(" ");
        }
    }
#endif

#if 0
    int k;

    k = a & (1 << 0);
    printf("0 :%d\n",k);

    k = a & (1 << 1);
    k = k >> 1;
    printf("1 :%d\n",k);

    k = a & (1 << 2);
    k = k >> 2;
    printf("2 :%d\n",k);

    puts("");
#endif

}
