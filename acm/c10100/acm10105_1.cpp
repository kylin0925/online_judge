/* @JUDGE_ID: 53xxxx 10105 C++ */
#include <stdio.h>
long double sum;
int main(int argc, char* argv[])
{
    int n,k,x,i,j;
    while(scanf("%d %d",&n,&k)==2)
    {
        sum=1.0;
        i=1;
        for(;k;k--)
        {
            scanf("%d",&x);
            for(j=1;j<=x;j++,i++)
            {
               sum*=i;
               sum/=j;
            }
        }
        printf("%.0Lf\n",sum);
    }
        return 0;
}
 
