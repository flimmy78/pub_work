/*******************************************************************
 *   > File Name: 01-sqlite3_open.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 24 Feb 2017 03:15:29 PM CST
 ******************************************************************/

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    /*打开数据库，不存在则创建*/
    rc = sqlite3_open("test.db",&db);

    if(rc != 0){
        fprintf(stderr, "can't open database : %s\n",sqlite3_errmsg(db));
        exit(0);
    }else{
        fprintf(stdout, "Opened database successfully\n");
    }
    
    sqlite3_close(db);/*关闭数据库*/

    return 0;
}
