/* @JUDGE_ID: 53xxxx 369 C++ */
#include <stdio.h>
int main()
{
    int n,r;
    int i,j;
    long double mul;
    while(1)
    {
          scanf("%d %d",&n,&r);
          if(n==0 && r==0) break;

           mul=1;
           for(i=n,j=1;i>(n-r);i--,j++)
           {
               mul*=i;
               mul/=j;
           }

           printf("%d things taken %d at a time is %.0Lf exactly.\n",n,r,mul);

    }
        return 0;
}
