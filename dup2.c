#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char **argv){
    int fd=0;
    if(argc!=2){
        fprintf(stderr,"ERROR");
        return 1;
    }
    fd=open(argv[1],O_WRONLY|O_CREAT|O_APPEND);
    if(fd==-1){
        perror("OPEN FAILED");
        return 1;
    }
    if(dup2(fd,STDOUT_FILENO)==-1){
        perror("OPEN FIALED");
        return 1;
    }
    printf("HELLO WORLD\n");
    close(fd);
    return 0;
}
