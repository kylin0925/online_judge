/* @JUDGE_ID: 53xxxx 160 C++ */
#include <stdio.h>
int prime[101];
int re[100];
int isprime(int n)
{
    int i;
    if(n%2==0) return 0;
    for(i=3;i*i<n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main(int argc, char* argv[])
{
    int i,j,n,t,te;
    char sp=' ';
    prime[0]=0;
    prime[1]=1;
    prime[2]=2;
    prime[3]=3;
    for(i=0;i<100;re[i]=0,i++);
    for(i=4;i<=100;i++)
    {
       if(isprime(i))
       {
         prime[i]=i;
       }
       else
       {
         prime[i]=0;
       }
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(i=0;i<100;re[i]=0,i++);
        for(i=2;i<=n;i++)
        {
            t=i;
            j=2;
            while(t!=1)
            {
               if(prime[j]>1)
               {
                  if(t%prime[j]==0)
                  {
                   t/=prime[j];
                   re[j]++;
                   j=1;
                  }

               }
                   j++;
            }
        }
        for(i=2;i<=n;i++)
        {
            for(j=n;j>1;j--)
            {
               if(re[j]<re[j+1])
               {
                  te=re[j];
                  re[j]=re[j+1];
                  re[j+1]=te;
               }
            }
        }
        printf("%3d! =",n);
        for(i=2,j=1;re[i]>0;i++,j++)
        {
           if(j==16)
           {
            printf("\n");
            printf("%*c",8,sp);
            printf("%d",re[i]);
           }
           else
           {
            printf("%3d",re[i]);
           }
        }
        printf("\n");
    }
        return 0;
}
