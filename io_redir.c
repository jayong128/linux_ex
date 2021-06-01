#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(){
    int backup_fd,fd;

    backup_fd=dup(STDOUT_FILENO);
    printf("Hello World(1)\n");
    
    fd=open("test.txt",O_WRONLY|O_CREAT|O_TRUNC,0744);
    dup2(fd,STDOUT_FILENO);
    printf("HELLO WORLD(2)\n");

    dup2(backup_fd,STDOUT_FILENO);
    printf("HELLO WORLD(3)\n");
    close(fd);
    return 0;
}