/*******************************************************************
 *   > File Name: 36-quote.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:24:20 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    //声明简单的变量
    int i;
    double d;

    //声明引用变量
    int& r = i;
    double& s = d;

    i = 5;
    cout << "Value of i :" << i << endl;
    cout << "Value of i reference :" << r << endl;

    d = 11.7;
    cout << "Value of d :" << d << endl;
    cout << "Value of d reference :" << s << endl;
    

    return 0;
}
