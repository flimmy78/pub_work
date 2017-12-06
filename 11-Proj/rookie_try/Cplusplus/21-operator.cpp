/*******************************************************************
 *   > File Name: 21-operator.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 16:27:54 2017
 ******************************************************************/

#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;

    e = (a + b) * c /b;     //( 30 * 15) / 5
    cout << "(a + b) * c / d 的值是" << e << endl;

    e = ((a + b) * c) / d;  // ( 30 * 15) / 5
    cout << "((a + b)) * c) / d的值是" << e << endl;

    e = (a + b) * ( c / d); // (30) * (15/5)
    cout << "( a + b ) * ( c / d) 的值是" << e << endl;

    e = a + ( b * c) / d;
    cout << "a + ( b * c) / d的值是" << e << endl;

    return 0;
}
