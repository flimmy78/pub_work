/*******************************************************************
 *   > File Name: 04-menu.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon 15 May 2017 03:24:12 PM CST
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    enum days{one, two, three}day;
    day = one;
    switch(day){
        case one:
            cout << "one" <<endl;
            break;
        case two:
            cout << "two" <<endl;
            break;
        default:
            cout << "three"<<endl;
            break;
    }

    return 0;
}
