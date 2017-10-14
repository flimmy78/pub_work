/*******************************************************************
 *   > File Name: 54-ifTest.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Oct  9 18:26:05 2017
 ******************************************************************/

#include <stdio.h>

#define DISABLE 0
#define ENABLE  1
#define WATERLOGO_FUNCTION DISABLE

int main(int argc, char* argv[])
{
#if defined (WATERLOGO_FUNCTION)&&(WATERLOGO_FUNCTION == ENABLE)
    printf("This is test 1\n");
#else
    printf("This is test 2\n");
    printf("%d\t%d\n", (WATERLOGO_FUNCTION),(WATERLOGO_FUNCTION == ENABLE));
#endif
    return 0;
}
