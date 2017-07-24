/*******************************************************************
 *   > File Name: 04-pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 22 Jul 2017 10:52:48 AM CST
 ******************************************************************/

#include <stdio.h>

/*说明：
 *两个同类型的指针可以相减
 *pa - pb，表示pa中的地址到pb中的地址之间
 *相差几倍的指针指向的空间大小（长度）。
 * */

int main(int argc, char* argv[])
{
    int a[10];
    int *pa1 = &a[8], *pa2 = &a[3];
    printf("pa1 = %p, pa2 = %p\n", pa1, pa2);
    printf("pa1 - pa2 = %d\n", pa1 - pa2);

    short b[10];
    short *pb1 = &b[8], *pb2 = &b[3];
    printf("pb1 = %p, pb2 = %p\n", pb1, pb2);
    printf("pb1 - pb2 = %d\n", pb1 - pb2);

    double c[10];
    double *pc1 = &c[8], *pc2 = &c[3];
    printf("pc1 = %p, pc2 = %p\n", pc1, pc2);
    printf("pc1 - pc2 = %d\n", pc1 - pc2);

    int d, e;
    //int *pd, *pe;
    int *pd = &d;
    int *pe = &e;
    printf("pd = %p, pe = %p\n", pd, pe);
    printf("pe - pd = %d\n", pe - pd);

    return 0;
}
