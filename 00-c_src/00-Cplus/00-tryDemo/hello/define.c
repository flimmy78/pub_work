/*******************************************************************
 *   > File Name: define.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 02:18:28 PM CST
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    return 0;
}

#if (0)

#ifdef Macro    //if macro is defined , it will compile the code of A.
    The code block of A;
#else           //if macro isn't defined , it will compile the code of B.
    The code block of B;
#endif

#ifndef Macro   //if macro isn't defined , it will compile the code of A.
    The code block of A;
#else           //if macro is defined , it will compile the code of B.
    The code block of B;   
#endif

#if (Expression)  //if the expression is true , it will compile the code of A;
    The code block of A;
#elif(Expression) //if the expression is true , it will compile the code of B;
    The code block of B;
#else             //if none of above is true , it will compile the code of C;
    The code block of C;
#endif


#endif

