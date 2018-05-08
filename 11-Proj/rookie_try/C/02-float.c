/*******************************************************************
 *   > File Name: 02-float.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年04月24日 星期二 14时06分52秒
 ******************************************************************/


#include <stdio.h>
#include <float.h>
 
int main()
{
   printf("float 存储最大字节数 : %u \n", sizeof(float));
   printf("float 最小值: %E\n", FLT_MIN );
   printf("float 最大值: %E\n", FLT_MAX );
   printf("精度值: %d\n", FLT_DIG );
   
   return 0;
}
