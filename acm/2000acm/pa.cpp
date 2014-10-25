#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
    long double n,i,sum;

    while(scanf("%Lf",&n)==1)
    {
         sum=n;
         for(i=1;i<=n;i++)
         {
            sum+=floor(sqrt((n*n)-(n-i)*(n-i)));
         }
         sum=sum*4-4*(n-1)-3;
         printf("%Lf\n",n);
         printf("%Lf\n",sum);
    }
        return 0;
}
 