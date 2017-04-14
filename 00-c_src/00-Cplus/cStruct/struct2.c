/*******************************************************************
 *   > File Name: struct2.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 01:24:26 PM CST
 ******************************************************************/
#if (0)
//指向结构的指针
#endif

#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

/*函数声明*/
void printBook(struct Books *book);

int main(int argc, char* argv[])
{
    struct Books Book1; 
    struct Books Book2;

    /* Book1 详述 */
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali"); 
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /*通过传Book1的地址来输出Book1信息*/
    printBook(&Book1);

    /*通过传Book2的地址来输出Book2信息*/
    printBook(&Book2);

    return 0;
}

void printBook(struct Books *book){
    printf("Book titile : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id :%d\n\n", book->book_id);
}
