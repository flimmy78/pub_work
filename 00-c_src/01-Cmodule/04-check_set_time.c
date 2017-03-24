/*******************************************************************
 *   > File Name: 04-check_set_time.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Mar 2017 05:50:01 PM CST
 ******************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int check_set_time(const char* tStr, int diffVal){
    char *sFormat = "xxxx-xx-xx_xx:xx:xx";
    char buf[19];
    int ret;

    if(tStr == NULL){
        printf("No param : eg. tStr [%s]\n",sFormat);return (-1);
    }
    strncpy(buf, tStr, strlen(sFormat));

    time_t set_sec, sys_sec;
    struct tm stm;
    
    if((sscanf(buf, "%d-%d-%d_%d:%d:%d",\
                    &stm.tm_year,\
                    &stm.tm_mon,\
                    &stm.tm_mday,\
                    &stm.tm_hour,\
                    &stm.tm_min,\
                    &stm.tm_sec)) != 6){
        printf("Invalid param : eg. tStr [%s]\n", sFormat);return (-2);
    }
    
    stm.tm_year -= 1900;
    stm.tm_mon  -= 1;

    set_sec = mktime(&stm);
    sys_sec = time((time_t*)NULL);
    //printf("\tset_sec :%ld  sys_sec :%ld\n", set_sec, sys_sec);
   
#if (1) 
    //ret = (set_sec > sys_sec && set_sec - sys_sec > diffVal || sys_sec > set_sec && sys_sec - set_sec > diffVal );
    if((ret = abs(set_sec -sys_sec)) > diffVal){
        //printf("ret = %d ,time will changed\n", ret);
        return 1;   /*时间相差太大*/
    }else{
        //printf("ret = %d ,time will not changed\n", ret);
        return 0;   /*时间相差较小*/
    }
#else
    /* 直接返回相差值 */
    ret = abs(set_sec - sys_sec);
    return ret;
#endif
}

#if (1)
int main(int argc, char* argv[])
{
    check_set_time(argv[1], 10);
    return 0;
}
#endif
