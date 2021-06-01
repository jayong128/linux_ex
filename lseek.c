#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#define max 5
int main(int argc,char **argv){
    int fd, size;
    char ch;
    if(argc!=2){
        fprintf(stderr,"argument\n");
        return 1;
    }
    if((fd=open(argv[1],O_RDONLY))==-1){
        perror("FAIL");
        return 1;
    }
    if((size=lseek(fd,0,SEEK_END))<0){
        printf("FAIL LSEEK\n");
        return 1;
    }
    while ((size-1)>0)
    {
        lseek(fd,-2,SEEK_CUR);
        read(fd,&ch,1);
        printf("%c",ch);
        size--;
    }
    printf("\n");
    close(fd);
}