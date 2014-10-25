/* @JUDGE_ID: 53xxxx 485 C++ */
#include <stdio.h>
long double cnr(int n,int r)
{
   int i,j;
   long double sum=1;
   for(i=n,j=1;i>n-r;i--,j++)
   {
       sum*=i;
       sum/=j;
   }
   return sum;
}
int main(int argc, char **argv)
{
    int i,f,j;
    long double t;
    FILE *fp;
    //fp=freopen("acm485.txt","w",stdout);
    f=1;
    while(f)
    {
       for(i=0;f;i++)
       {
        for(j=0;j<=i;j++)
        {
           t=cnr(i,j);
           if(t>=10000000){ f=0;}
           printf("%.0Lf ",t);
        }
        printf("\n");
       }
    }
        return 0;
}
