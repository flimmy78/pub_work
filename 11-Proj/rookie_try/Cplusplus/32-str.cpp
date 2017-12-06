/*******************************************************************
 *   > File Name: 32-str.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 13:57:17 2017
 ******************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str1 = "Hello";
    string str2 = "World";
    string str3;
    int len;

    //复制str1到str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;

    //连接str1和str2
    str3 = str1 + str2;
    cout << "str1 + str2 :" << str3 << endl;

    //连接后，str3的总长度
    len = str3.size();
    cout << "str3.size() : " << len << endl;

    return 0;
}
