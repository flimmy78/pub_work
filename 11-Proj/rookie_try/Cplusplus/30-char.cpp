/*******************************************************************
 *   > File Name: 30-char.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 13:47:43 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int main(void)
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << "Greeting message :";
    cout << greeting << endl;

    return 0;
}
