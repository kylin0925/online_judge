/*@JUDGE_ID:53xxxx  465 C*/
#include <stdio.h>
#include <string.h>
char buff[1000],tmp[100];

int main(int argc, char* argv[])
{
    int i=0,f=0;
    long double a,b;
    char c;
    while(gets(buff))
    {
        if(strlen(buff)==0) continue;
        printf("%s\n",buff);
        for(i=0;i<strlen(buff);i++)
        {
           if(buff[i]=='+'){ f=1;c='+';}
           else if(buff[i]=='*'){ f=2;c='*';}
        }
        if(f==1)
        {
           sscanf(strtok(buff,"+"),"%Lf",&a);
           sscanf(strtok(NULL,"+"),"%Lf",&b);
        }
        if(f==2)
        {
           sscanf(strtok(buff,"*"),"%Lf",&a);
           sscanf(strtok(NULL,"*"),"%Lf",&b);
        }
        if(a>2147483647){ printf("first number too big\n");}
        if(b>2147483647){ printf("second number too big\n");}
        if(c=='+')
        {
         if((a+b)>2147483647)
          printf("result too big\n");
        }
        else
        {
         if((a*b)>2147483647)
          printf("result too big\n");
        }
    }
        return 0;
}
