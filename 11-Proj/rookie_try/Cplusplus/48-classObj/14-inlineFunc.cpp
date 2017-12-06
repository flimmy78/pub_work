/*******************************************************************
 *   > File Name: 14-inlineFunc.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue Dec  5 11:30:03 2017
 ******************************************************************/

#include <iostream>
using namespace std;

inline int Max(int x, int y){
    return (x > y) ? x : y;
}

int main(void)
{
    cout << "Max(20, 10):" << Max(20,10) << endl;
    cout << "Max (0,200): " << Max(0,200) << endl;
    cout << "Max (100,1010): " << Max(100,1010) << endl;

    return 0;
}
