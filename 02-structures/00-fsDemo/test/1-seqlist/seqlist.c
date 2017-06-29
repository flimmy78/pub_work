/*******************************************************************
 *   > File Name: seqlist.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Wed Jun 21 17:44:34 2017
 ******************************************************************/

#include "seqlist.h"

/*初始化线性表1*/
seq_plist init_seqlist(void){
    seq_plist l;
    l = (seq_plist)malloc(sizeof(seq_list));
    if(l == NULL){
        perror("malloc");exit(1);
    }

    l -> last = -1;
    return l;
}

/*初始化线性表2*/
void init_seqlist_(seq_plist *L){
    *L = (seq_plist)malloc(sizeof(seq_list));
    if(*L == NULL){
        perror("malloc");exit(1);
    }

    (*L) -> last = -1;
    return;
}

/*表是否为空*/
bool isempty_seqlist(seq_plist l){
    if(l -> last == -1)
        return true;
    else
        return false;
}

/*表是否为满*/
bool isfull_seqlist(seq_plist l){
    if(l -> last == (SIZE - 1))
        return true;
    else
        return false;
}

/*插入*/
bool insert_seqlist(seq_plist l, datatype data){
    int i,j;

    /*判断表是否已满*/
    if(isfull_seqlist(l)){
        printf("\033[1;33mSeqlist is full !\033[0;0m\n");return false;
    }

    /*确定插入的位置*/
    for(i = 0; i <= l -> last; i ++){
        if(data < l -> data[i])
            break;
    }
    
    /*移动数据*/
    for(j = l -> last; j >= i; j--){
        l -> data[j + 1] = l -> data[j];
    }

    /*插入*/
    l -> data[i] = data;

    /*last 加1*/
    l -> last ++;

    return true;
}

/*删除*/
bool del_seqlist(seq_plist l, datatype data){
    int i,j;

    if(isempty_seqlist(l)){
        printf("Seqlist is empty！\n");
        return false;
    }

    for(i = 0; i <= l -> last; i ++){
        if(data == l -> data[i])
            break;
    }

    if(i > l->last){
        printf("%d不存在!\n", data);
        return false;
    }

    for(j = i; j < l-> last; j ++){
        l -> data[j] = l -> data[j + 1];
    }
    l -> last --;
    
    return true;
}

/*遍历*/
void show_seqlist(seq_plist l){
    int i;

    for(i = 0; i <= (l -> last); i++){
        printf("%d\t", l -> data[i]);
    }
    puts("");
}
