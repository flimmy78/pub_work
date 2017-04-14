/*******************************************************************
 *   > File Name: cTypedef.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 10:13:22 AM CST
 ******************************************************************/
#if (0)
//可以使用 typedef 来为用户自定义的数据类型取一个新的名字。例如，您可以
//对结构体使用 typedef 来定义一个新的数据类型名字，然后使用这个新的数据
//类型来直接定义结构变量
#endif

#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;
BYTE b1, b2;
//typedef unsigned char byte;

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}Book;

int main(int argc, char* argv[])
{
    Book book;

    strcpy(book.title, "the one flying a kite ");
    strcpy(book.author, "Khaled Hosseini");
    strcpy(book.subject, "salvation of the soul");
    book.book_id = 1001;

    printf( "书标题 : %s\n", book.title);
    printf( "书作者 : %s\n", book.author);
    printf( "书类目 : %s\n", book.subject);
    printf( "书 ID  : %d\n", book.book_id);
    return 0;
}
