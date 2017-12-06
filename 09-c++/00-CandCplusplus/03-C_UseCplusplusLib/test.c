/*******************************************************************
 *   > File Name: test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 14:36:16 2017
 ******************************************************************/
/*C源文件test.c*/  
/*C通过链接二次接口库调用C++库*/
#include <stdio.h>  

extern void m_funcpp();

int main()  
{  
    m_funcpp();  

    return 0;  
}  
