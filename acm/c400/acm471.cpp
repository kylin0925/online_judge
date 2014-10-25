/* @JUDGE_ID: 53xxxx 471 C++ */
#include <stdio.h>
#include <string.h>
int r(long double n)
{
   int d[15],i;
   char sn[15];
   sprintf(sn,"%.0Lf",n);
   for(i=0;i<15;i++)
     d[i]=0;
   for(i=0;i<strlen(sn);i++)
   {
       if(d[sn[i]-'0']) return 0;
       d[sn[i]-'0']++;
   }
   return 1;
}
int main(int argc, char* argv[])
{
    int n,i;
    long double a,p;
    char in[15];
    scanf("%d",&n);
    for(;n>0;n--)
    {
        scanf("%s",&in);
        i=1;
        sscanf(in,"%Lf",&a);
        p=a ;
        while(p<=98765432101)
        {
            if(r((long double)i) && r(p))
              printf("%.0Lf / %d = %s\n",p,i,in);
            i++;
            p+=a;
        }
    }
        return 0;
}
 
