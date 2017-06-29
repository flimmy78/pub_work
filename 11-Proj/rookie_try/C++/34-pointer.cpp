/*******************************************************************
 *   > File Name: 34-pointer.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 14:11:02 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    int var = 20;   //实际变量的声明
    int *ip;        //指针变量的声明

    ip = &var;      //在指针变量中存储var的地址

    cout << "Value of var variable :";
    cout << var << endl;

    //输出指针变量中存储的地址
    cout << "Address stored in ip variable :";
    cout << ip << endl;

    //访问指针中地址的值
    cout << "Value of *ip variable :";
    cout << *ip << endl;

    return 0;
}
