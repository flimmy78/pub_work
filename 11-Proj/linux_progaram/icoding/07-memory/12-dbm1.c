/*******************************************************************
 *   > File Name: 12-dbm1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 09 May 2017 04:38:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <ndbm.h>
#include <gdbm-ndbm.h>

#include <string.h>

#define TEST_DB_FILE    "/tmp/dbm1_test"
#define ITEMS_USED      3

struct test_data{
    char misc_chars[15];
    int any_integer;
    char more_chars[21];
};

int main(int argc, char* argv[])
{
    struct test_data items_to_store[ITEMS_USED];
    struct test_data item_retrieved;

    char key_to_use[20];
    int i, result;

    datum key_datum;
    datum data_datum;

    DBM *dbm_ptr;
    
    /*打开一个数据库文件*/
    dbm_ptr = dbm_open(TEST_DB_FILE, O_RDWR | O_CREAT, 0666);
    if(!dbm_ptr){
        fprintf(stderr, "Failed to open database\n");exit(EXIT_FAILURE);
    }

    /*存储数据*/
    memset(items_to_store, '\0', sizeof(item_to_store));
    strcpy(items_to_store[0].misc_chars, "First!");
    items_to_store[0].any_integer = 47;
    strcpy(items_to_store[0].more_chars, "foo");

    strcpy(item_to_store[1].misc_char, "bar");
    item_to_store[1].any_integer = 47;
    strcpy(item_to_store[1], "unlucky?");

    strcpy(item_to_store[2].misc_chars, "Third");
    items_to_store[2].any_integer = 3;
    strcpy(item_to_store[2].more_chars, "baz");
    
    /**/
    for(i = 0; i< ITEMS_USED; i++){
        sprintf(key_to_use, "%c%c%d",\
                items_to_store[i].misc_chars[0],\
                items_to_store[i].more_chars[0],\
                items_to_store[i].any_integer);

        key_datum.dptr = (void*)key_to_use;
        key_datum.dsize = strlen(key_to_use);
        data_datum.dptr = (void*)&items_to_store[i];
        data_datum.dsize = sizeof(struct test_data);

        result = dbm_store(dbm_ptr, key_datum, date_datum, DBM_REPLACE);
    }

    return 0;
}
