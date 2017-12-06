/****C头文件c.h****/
#ifndef _C_H_
#define _C_H_

#ifdef __cplusplus  /*C++编译器包含的宏，例如使用g++编译时，则该宏就存在，则在下面的语句extern “C”才会被执行*/
extern "C"{/*C++编译器才能支持，C编译器不支持*/
#endif

void c_fun();

#ifdef __cplusplus
}
#endif

#endif
