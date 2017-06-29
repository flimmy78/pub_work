/*******************************************************************
 *   > File Name: main.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:45:22 2017
 ******************************************************************/

#include <iostream>
using namespace std;

int count;
extern void write_extern();

int main(void)
{
    count = 5;
    write_extern();

    return 0;
}
