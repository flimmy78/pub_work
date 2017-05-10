/*******************************************************************
 *   > File Name: 01-sqlite3.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed 10 May 2017 10:43:45 AM CST
 ******************************************************************/

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    sqlite3 *db;
    //char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if(rc){
        fprintf(stderr, "Can't open database:%s\n", sqlite3_errmsg(db));exit(0);
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);
    return 0;
}
