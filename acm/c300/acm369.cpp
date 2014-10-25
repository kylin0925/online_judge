#include <stdio.h>
int main(int argc, char **argv)
{
    long i,j,n,r;
    long double mul;
    while(scanf("%d %d",&n,&r)==2)
    {
         mul=1;
         if(n==0 && r==0) break;
         for(i=n,j=1;i>(n-r);i--,j++)
         {
             mul*=i;
             mul/=j;
         }
         printf("%d things taken %d at a time is %.0Lf exactly.\n",n,r,mul);
    }
        return 0;
}
 
