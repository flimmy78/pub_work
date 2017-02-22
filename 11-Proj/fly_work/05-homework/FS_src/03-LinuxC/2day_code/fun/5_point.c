#include <stdio.h>


void fun1(int *p1,int *p2)
{
    int t;
    printf("%d,%d\n",*p1,*p2);
    /*
       t = p1;
       p1 = p2;
       p2 = t;
     */
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void fun2(int ** p1,int **p2)
{
    /*
    int *tp;

    tp = *p1;
    *p1 = *p2;
    *p2 = tp; 
    */
    int t;
    t = **p1;
    **p1 = **p2;
    **p2 = t;
}

int main(void)
{
    int x = 20,y = 50;
    int *px = &x,*py = &y;
#if 0
    printf("px = %p,py = %p\n",px,py);
    printf("x = %d,y = %d\n",x,y);
    fun1(px,py);	    //实参为px和py，传：px和py的值，所以称为值传递 ,不能改变实参px，py但是可以改变它们指向的数据  
    printf("px = %p,py = %p\n",px,py);
    printf("x = %d,y = %d\n",x,y);
#else

    printf("px = %p,py = %p\n",px,py);
    printf("x = %d,y = %d\n",x,y);
    fun2(&px,&py);	    //实参为px和py，传：px和py的地址，所以称为地址传递,既可以改变px和py，又可以改变px和py指向的数据 
    printf("px = %p,py = %p\n",px,py);
    printf("x = %d,y = %d\n",x,y);
#endif
    return 0;
}
