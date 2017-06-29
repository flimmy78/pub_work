/*******************************************************************
 *   > File Name: test.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 16:40:30 2017
 ******************************************************************/

#include <stdio.h>
#include "seqlist.h"

int main(int argc, char* argv[])
{
    
    seq_plist l;
    datatype data;
    datatype ret;

    l = init_seqlist();
    while(1){
        printf("Pls input a integer :");
        ret = scanf("%d", &data);

        if(ret != 1){
            puts("\033[1m\033[45;33mInput err\033[0m");exit(1);
        }else if(data > 0){
            insert_seqlist(l, data);
            show_seqlist(l);
        }else if(data < 0){
            del_seqlist(l, -data);
            show_seqlist(l);
        }else if(data == 0){
            puts("\033[1;33misn't inserted or deleted !\033[0;0m");
        } 
    }

    return 0;
}
