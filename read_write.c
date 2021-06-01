#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_TIT_LEN 100
#define MAX_AUT_LEN 20
#define DUMMY_FNAME "dummy"
typedef struct _Book Book;
struct _Book
{
    char title[MAX_TIT_LEN+1];
    char author[MAX_AUT_LEN+1];
    int num;
};
void TestWrite();
void TestRead();
 
 
int main()
{
    TestWrite();
    TestRead(); 
    return 0;
}
void TestWrite()
{
    int fd = 0;
    Book books[3]={
        {"Unix System Programming with Linux","ehjang",1},
        {"Escort C Language","ehjang",2},
        {"Advanced Programming in the UNIX","Stevens",3}
    };
 
    fd = open(DUMMY_FNAME,O_WRONLY|O_CREAT|O_TRUNC,0644); //쓰기,생성,내용지움
    if(fd == -1)
    {
        perror("failed open dummy file.");
        exit(1);
    }
 
    int re = 0;
    re = write(fd, books, sizeof(books));
    if(re == -1)
    {
        perror("failed write ");
        exit(1);
    }
 
    printf("write %d bytes\n",re);
    close(fd);
}
 
 
void TestRead()
{
    int fd = 0;
    Book book;
    fd = open(DUMMY_FNAME,O_RDONLY);//읽기 전용
    if(fd == -1)
    {
        perror("failed open dummy file.");
        exit(1);
    }
    int re = 0;
    while((re = read(fd, &book, sizeof(Book))) >0)
    {
        printf("title:%s\n",book.title);
        printf("\tauthor:%s\n",book.author);
        printf("\tbook no:%d\n",book.num);
    }
    close(fd);
}