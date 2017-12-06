/*******************************************************************
 *   > File Name: 35-pointer.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:17:48 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    int var = 20;
    int *ip;
    ip = &var;

    cout << "var的值 :";
    cout << var << endl;

    cout << "变量ip的存储地址 :";
    cout << ip << endl;

    cout << "指针 *ip的值 :";
    cout << *ip << endl;


    return 0;
}
