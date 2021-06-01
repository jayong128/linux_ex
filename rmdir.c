#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
int main(){
    int fd=0;
    if(mkdir("test",0755)==0){
        printf("SECCESS\n");
    }else{
        perror("FAILED\n");
    }
    fd=open("./test/dum",O_WRONLY|O_CREAT|O_TRUNC);
    if(fd==-1){
        perror("ERROR OPEN");
        return 1;
    }
    unlink("./test/dum");
    char buf[10]="HELLO";
    int re=write(fd,buf,10);
    if(re==10){
        printf("WRITE OK\n");
    }else{
        printf("FAIL\n");
    }
    close(fd);
    if(remove("test")==0){
        printf("REMOVE SUCCESS\n");
    }else{
        printf("R_FAILED\n");
    }
    return 0;
}
