/*******************************************************************
 *   > File Name: test.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 14:07:57 2017
 ******************************************************************/
/*C++源文件test.cpp中调用C库的函数*/  
#include <iostream>  

#ifdef __cplusplus  
extern "C" {// 告诉编译器下列代码要以C链接约定的模式进行链接  
#endif  

void func();  

#ifdef __cplusplus  
}  
#endif  

int main()  
{  
    func();  

    return 0;  
} 
