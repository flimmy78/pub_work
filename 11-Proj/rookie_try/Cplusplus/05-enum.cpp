/*******************************************************************
 *   > File Name: 05-enum.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 09:53:00 2017
 ******************************************************************/

#include <iostream>
using namespace std;

enum time{
    first,second,
    third, forth, fifth
};

int main(void)
{
    enum time a = fifth;
    if(a == fifth)
    {
        cout << "Succeed!\n";
    }

    return 0;
}
