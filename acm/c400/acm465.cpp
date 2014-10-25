/*@JUDGE_ID:53xxxx  465 C*/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i=0,f=0;
    char a[100],b[100],c,tmp[100];
    long double fa,fb;
    while(scanf("%s",&tmp)==1)
    {
         if(i==0)
         {
           f=0;
           strcpy(a,tmp);
         }
         else if(i==1)
         {
           c=tmp[0];
         }
         else if(i==2)
         {
           strcpy(b,tmp);
           i=-1;
           if(strcmp(a,"32767")>0)
           {
             f=1;
             printf("first number too big\n");
           }
           if(strcmp(b,"32767")>0)
           {
            f=1;
            printf("second number too big\n");
           }
           if(c=='+')
           {
            sscanf(a,"%Lf",&fa);
            sscanf(b,"%Lf",&fb);
            if((fa+fb)>32767) printf("result too big\n");
            else if(!f)
                printf("%s %c %s\n",a,c,b);
            }
            else
            {
             sscanf(a,"%Lf",&fa);
             sscanf(b,"%Lf",&fb);
             if((fa*fb)>32767) printf("result too big\n");
             else if(!f)
                printf("%s %c %s\n",a,c,b);
            }
          }
         i++;

    }
        return 0;
}
