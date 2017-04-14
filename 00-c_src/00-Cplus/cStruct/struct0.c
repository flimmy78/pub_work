/*******************************************************************
 *   > File Name: struct0.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 11:36:40 AM CST
 ******************************************************************/
#if (0)
struct [structure tag]
{
    member definition;
    member definition;
             ...
    member definition;
} [one or more structure variables]; 
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

int main(int argc, char* argv[])
{
    struct Books Book1;
    struct Books Book2;

    /*Book1详述*/
    strcpy(Book1.title, "Beginning Linux Programming 4th Edition");
    strcpy(Book1.author, "Neil Matthew & Richard Stones");
    strcpy(Book1.subject, "Linux Programming For C");
    Book1.book_id = 2007;

    /*Book2详述*/
    strcpy(Book2.title, "Introduction to Algorithms Third Edition");
    strcpy(Book2.author, "Thomas H.Cormen Charles E.Leiserson & Ronald L.Rivest Clifford Stein");
    strcpy(Book2.subject, "Algorithms");
    Book2.book_id = 2008;

    /*输出Book1的信息*/
    printf("Book1.title : %s\n", Book1.title);
    printf("Book1.author : %s\n", Book1.author);
    printf("Book1.subject : %s\n", Book1.subject);
    printf("Book1.book_id : %d\n\n", Book1.book_id);

    /*输出Book2的信息*/
    printf("Book2.title : %s\n", Book2.title);
    printf("Book2.author : %s\n", Book2.author);
    printf("Book2.subject : %s\n", Book2.subject);
    printf("Book2.book_id : %d\n\n", Book2.book_id);

    return 0;
}
