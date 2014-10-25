#include <stdio.h>
#include <string.h>
int main()
{
    char in[1000],*buffer,token[]=",";
    int len,i;
    while(gets(in))
    {
       if(!strcmp(in,"END")) break;
       len=strlen(in);
       in[len-1]=',';
       buffer=strtok(in,token);

       while(buffer!=NULL)
       {
             
             buffer=strtok(NULL,token);
             
       }
       printf("\n");
    }
        return 0;
}
