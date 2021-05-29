#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char **argv){
    int fd1=0,fd2=0;
    char buf[11]="";
    if(argc!=2){
        fprintf(stderr,"ERROR");
        return 1;
    }
    fd1=open(argv[1],O_RDONLY);
    if(fd1==-1){
        fprintf(stderr,"FAI:Ed OPEN%s\n",argv[1]);
        return 1;
    }
    fd2=dup(fd1);
    if(fd2==-1){
        perror("FAILED DUP");
        return 1;
    }
    read(fd1,buf,5);
    printf("fd1 : %s\n",buf);
    read(fd2,buf,5);
    printf("fd2 : %s\n",buf);
    close(fd1);
    close(fd2);
    return 0;
}
