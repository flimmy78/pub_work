/*******************************************************************
 *   > File Name: 31-str.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 13:49:50 2017
 ******************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    int len;

    //复制str1到str3
    strcpy(str3, str1);
    cout << "strcpy(str3, str1) :" << str3 << endl;

    //连接str2到str3
    strcat(str3, str2);
    cout << "strcat(str1, str3) :" << str1 << endl;

    //连接后，str1的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    return 0;
}
