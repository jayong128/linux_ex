#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc,char **argv)
{
    int fd = 0;
    if(argc != 2)
    {
        printf("Usage %s <filename>\n",argv[0]);
        exit(0);
    }
 
    fd = open(argv[1],O_RDONLY);
    if(fd<0)
    {
        perror("failed open file");
        exit(0);
    }
    printf("successed open file %s and fd:%d\n",argv[1],fd);
    close(fd);
 
    return 0;
}
