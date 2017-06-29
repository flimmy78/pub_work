/*******************************************************************
 *   > File Name: linklist.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jun 22 10:33:26 2017
 ******************************************************************/

#include "linklist.h"

list_pnode init_linklist(void){
    list_pnode l;

    l = (list_pnode)malloc(sizeof(list_node));
    if(l == NULL){
        perror("malloc");exit(1);
    }

    l -> next = NULL;
    return l;
}

void init_linklist_(list_pnode *H){
    *H = (list_pnode)malloc(sizeof(list_node));
    if(*H == NULL){
        perror("malloc");exit(1);
    }

    (*H) -> next = NULL;
    return;
}


