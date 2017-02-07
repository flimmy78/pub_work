/*******************************************************************
 *   > File Name: common_used_test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 07 Feb 2017 10:57:46 AM CST
 ******************************************************************/

#include "common_used.h"

int main(int argc, char* argv[])
{
    int err_value = -1;
    BEGIN_DEBUG_PRINT("main run start");
    Printf("Printf test");
    Printd("Printd test");
    if(err_value != 0)
    {
        ERR_PRINT("err_value is not zero","This is err test");
    }
    END_DEBUG_PRINT("main stop run");
    return 0;
}

