/*******************************************************************
 *   > File Name: cpp.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Nov 24 16:26:00 2017
 ******************************************************************/

#include <iostream>
#include "c.h"
using namespace std;

int main(void)
{
    c_fun();
    cout << "FILE :" << __FILE__ << ", FUNC :" << __func__ << ", LINE :" << __LINE__ << endl;

    return 0;
}
