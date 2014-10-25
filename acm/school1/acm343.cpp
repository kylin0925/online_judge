#include <stdio.h>
#include <math.h>
#include <string.h>
long double bt(char sno[],int b)
{
   int i,len;
   long double sum=0;
   len=strlen(sno);
   for(i=0;i<len;i++)
   {
      sum+=pow((long double)(sno[i]-'0'),(long double)(len-i-1));
   }
   return sum;
}
int main()
{
    char num[30],b[5],tsum[30],tsum2[30];
    double base;
    long double sum=0,sum2=0;
    int i,j,f=0,s=0;
    while(scanf("%s%s",&num,&b)==2)
    {
      sum=0;
      sum2=0;
      s=1;
      for(i=2;i<=36;i++)
      {
         sum=bt(num,i);
         f=0;
        sprintf(tsum,"%lf",sum);
        for(j=2;j<=36;j++)
        {
         sum2=bt(b,j);
         sprintf(tsum2,"%lf",sum);
         if(!strcmp(tsum,tsum2))
         {
           f=0;s=1;
           break;
         }
         else if(i==36)
         {
            f=1;
         }
        }
        if(s) break;
      }
      if(!f)
      {
        printf("%s (base %d) = %s (base %d)\n",num,i,b,j);
      }
    }
}
