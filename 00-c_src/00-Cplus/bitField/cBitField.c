/*******************************************************************
 *   > File Name: C_Bit_Field.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 09:42:30 AM CST
 ******************************************************************/

#include <stdio.h>

#ifdef TEST
#if (0)
struct 
{
    unsigned int widthValidated;
    unsigned int heightValidated;
}status;
#else
struct
{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
}status;
#endif
#endif

#pragma pack(push)
#pragma pack(4)
/*定义简单的结构*/
struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;
}status1;

/*定义位域结构*/
struct 
{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
}status2;

struct
{
    unsigned int age : 3;
}Age;
#pragma pack(pop)

int main(int argc, char* argv[])
{
    printf("Memory size occupied by status1 :%d\n", sizeof(status1));
    printf("Memory size occupied by status2 :%d\n", sizeof(status2));
    printf("Memory size occupied by Age :%d\n", sizeof(Age));

    return 0;
}
