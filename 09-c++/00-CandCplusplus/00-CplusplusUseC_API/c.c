/*******************************************************************
 *   > File Name: c.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Nov 24 16:17:20 2017
 ******************************************************************/

#include <stdio.h>
#include "c.h"

void c_fun(void){
    printf("FILE :%s, FUNC :%s, LINE :%d\n", __FILE__, __func__, __LINE__);
}
