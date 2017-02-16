#ifndef  __SEQSTACK_h__
#define  __SEQSTACK_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct seqstack{
    datatype data[SIZE];
    int top;
}seq_stack,*seq_pstack;

extern void init_seqstack(seq_pstack *S);
extern bool seqstack_push(seq_pstack s,datatype data);
extern bool seqstack_pop(seq_pstack s,datatype* data);
extern bool isfull_seqstack(seq_pstack s);
extern bool isempty_seqstack(seq_pstack s);
extern void show_seqstack(seq_pstack s);
#endif
