/*******************************************************************
 *   > File Name: 11-define.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:14:17 2017
 ******************************************************************/

#include <iostream>
using namespace std;

#define LENGTH  10
#define WIDTH   5
#define NEWLINE '\n'

int main(void)
{
    int area;

    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;

    return 0;
}
