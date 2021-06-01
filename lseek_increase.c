// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <stdlib.h>
// int main(int argc,char **argv){
//     int fd, count;
//     int size;
//     if(argc!=3){
//         fprintf(stderr,"Usage errer");
//         return 1;
//     }
//     if((fd=open(argv[1],O_WRONLY))==-1){
//         perror("FAILED");
//         return 1;
//     }
//     if((size=lseek(fd,0,SEEK_END))>0){
//         printf("[before]%s file size : %d\n",argv[1],size);
//     }
//     count=atoi(argv[2])-1;
//     lseek(fd,count,SEEK_END);
//     write(fd,".",1);
//     if((size=lseek(fd,0,SEEK_END))>0){
//         printf("[after]%s file size : %d\n",argv[1],size);
//     }
//     close(fd);
// }
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc,char **argv)
{
    int fd = 0;
    if(argc != 2)
    {
        fprintf(stderr,"usage: %s <filename>\n",argv[0]);
        return 1;
    }
    fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd == -1)
    {
        fprintf(stderr,"failed open %s\n",argv[1]);
        return 1;
    }
    if(lseek(fd, 20, SEEK_CUR)==-1)
    {
        printf("can't lseek %s file. \n",argv[1]);
    }
    else
    {
        char dummy='a';
        write(fd,&dummy,1);
    }       
    close(fd);
    return 0;
}