#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main(){
    printf("STDIN_FILENO:%u\n",STDIN_FILENO);
    printf("STDOUT_FILENO:%u\n",STDOUT_FILENO);
    printf("STDERR_FILENO:%u\n",STDERR_FILENO);
    printf("FOPEN_MAX:%u\n",FOPEN_MAX);
    return 0;
}
