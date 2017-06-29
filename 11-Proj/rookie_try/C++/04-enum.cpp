/*******************************************************************
 *   > File Name: 04-enum.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 09:49:45 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    enum days{one, two, three}day;

    day = one;
    switch(day){
        case one:
            cout << "one" << endl;
            break;
        case two:
            cout << "two" << endl;
            break;
        default:
            cout << "three" << endl;
            break;
    }

    return 0;
}
