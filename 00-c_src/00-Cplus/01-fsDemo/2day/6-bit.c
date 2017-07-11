/*******************************************************************
 *   > File Name: 6-bit.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 10 Jul 2017 05:13:43 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdbool.h>

/*说明：
 * 赋值运算：=
 *算术运算：+、-、*、/、%、++、--
 *关系运算符：>、>=、<、<=、==、！=
 *逻辑运算：!、||、&&
 *位运算：~、|、&、^、<<、>>
 *复合运算：+=、*=、|=、&=
 *条件运算：？：
 *逗号运算：
 *sizeof
 * */

int main(int argc, char* argv[])
{
    char a = 5, b = 3;

    printf("a = %hhd, b = %hhd\n", a, b);
    printf("~a = %hhd\n", ~a);
    printf("a | b = %hhd\n", a | b);
    printf("a & b = %hhd\n", a & b);
    printf("a << 2 = %hhd\n", a << 2);
    printf("-a << 2 = %hhd\n", -a << 2);
    printf("a >> 2 = %hhd\n", a >> 2);
    printf("-a >> 2 = %hhd\n", -a >> 2);
    printf("a ^ b = %hhd\n", a ^ b);


    return 0;
}
