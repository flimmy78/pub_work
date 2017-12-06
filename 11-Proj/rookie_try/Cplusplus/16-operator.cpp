/*******************************************************************
 *   > File Name: 16-operator.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:54:07 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    cout << "Line 1 - c 的值是" << c << endl;
    c = a - b;
    cout << "Line 2 - c 的值是 " << c << endl ;
    c = a * b;
    cout << "Line 3 - c 的值是 " << c << endl ;
    c = a / b;
    cout << "Line 4 - c 的值是 " << c << endl ;
    c = a % b;
    cout << "Line 5 - c 的值是 " << c << endl ;

    int d = 10;   //  测试自增、自减
    c = d++;
    cout << "Line 6 - c 的值是 " << c << endl ;

    d = 10;    // 重新赋值
    c = d--;
    cout << "Line 7 - c 的值是 " << c << endl ;


    return 0;
}
