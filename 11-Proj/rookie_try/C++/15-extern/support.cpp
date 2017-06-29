/*******************************************************************
 *   > File Name: support.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Mon Jun 19 10:46:24 2017
 ******************************************************************/

#include <iostream>
using namespace std;

extern int count;

void write_extern(void){
    std::cout << "Count is  " << count << std :: endl;
}
