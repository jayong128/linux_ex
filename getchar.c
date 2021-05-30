#include <stdio.h>
 
int main()
{
    int i = 0;
    char buf[20]="";
    for(i=0; i<5; i++)
    {   
        printf("<%d> :",i);
        buf[i] = getchar();
    }   
    printf("buf:%s\n",buf);
    return 0;
}