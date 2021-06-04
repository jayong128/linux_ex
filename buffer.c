#include <stdio.h>

#include <unistd.h>
int main(){
    putchar('e');
    sleep(1);
    fputc('H', stderr);

    putchar('h');
    sleep(1);
    fputc('E', stderr);
 
    putchar('\n');
    sleep(1);
    fputc('L', stderr);
 
    putchar('p');
    sleep(1);
    fputc('L', stderr);
 
    putchar('u');
    sleep(1);
    fputc('O', stderr);
 
    putchar('b');
    sleep(1);
    fputc('!', stderr);
 
    putchar('\n');
    sleep(1);
    fputc('\n', stderr);
 
    return 0;
}