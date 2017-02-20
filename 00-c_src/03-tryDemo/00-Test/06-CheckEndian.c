/*******************************************************************
 *   > File Name: 06-CheckEndian.c
 *   > Author: fly
 *   > Mail: XXXXXXXXXX@icode.com
 *   > Create Time: Sat 04 Feb 2017 04:26:15 PM CST
 ******************************************************************/

#include <stdio.h>

#define LITTLE_ENDIAN   0
#define BIG_ENDIAN      1

typedef unsigned char BYTE;
typedef unsigned int INT;

int CheckEndian(void)
{
  INT num, *p;
  p = &num;
  num = 0;
  *(BYTE*)p = 0xFF; 
  if(num == 0xFF)
      return LITTLE_ENDIAN;
  else
      return BIG_ENDIAN;
}

int CheckEndian_(void)
{
    union w
    {
        int a;
        char b;
    }c;
    c.a = 1;
    
    if(c.b == 1)
        return LITTLE_ENDIAN;
    else
        return BIG_ENDIAN;
}

int main(int argc, char* argv[])
{
    if(CheckEndian() == LITTLE_ENDIAN)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }

    return 0;
}
