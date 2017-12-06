/*******************************************************************
 *   > File Name: 12-const.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:16:41 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;

    //WIDTH = 100; //error

    area = LENGTH *WIDTH;
    cout << area;
    cout << NEWLINE;

    return 0;
}
