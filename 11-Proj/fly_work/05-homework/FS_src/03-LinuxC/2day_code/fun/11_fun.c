#include <stdio.h>

typedef void(*TYPE)(void);

void fun(void)
{
    printf("hello world\n");
}

//void(* fun1(void))(void)
TYPE fun1(void)
{
    return fun;
}

int main(void)
{
    void (*p)(void);

    p = fun1();
    p();
   return 0;
}
