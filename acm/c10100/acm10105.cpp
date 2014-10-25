/* @JUDGE_ID: 53xxxx 10105 C++ */
#include <stdio.h>
int sum;
int main(int argc, char* argv[])
{
    int n,k,x,i,j;
    while(scanf("%d %d",&n,&k)==2)
    {
        sum=1.0;
        for(;k;k--)
        {
            scanf("%d",&x);
            for(j=1,i=1;j<=x;j++,i++)
            {
               sum*=i;
               sum/=j;
            }
            for(j=1;j<=n-x;j++,i++)
            {
               sum*=i;
               sum/=j;
            }
            n-=x;
        }
        printf("%d\n",sum);
    }
        return 0;
}
 
