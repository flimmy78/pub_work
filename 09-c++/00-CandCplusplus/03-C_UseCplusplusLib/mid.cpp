/*******************************************************************
 *   > File Name: mid.cpp
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Nov 25 14:34:30 2017
 ******************************************************************/
/*中间接口库 mid.cpp*/  
/*对C++库进行二次封装*/
#include <iostream>  

void funcpp();  

#ifdef __cplusplus  
extern "C" {  // 即使这是一个C++程序，下列这个函数的实现也要以C约定的风格来搞！  
#endif  

    void m_funcpp()  
    {  
        funcpp();  
    }  

#ifdef __cplusplus  
}  
#endif
