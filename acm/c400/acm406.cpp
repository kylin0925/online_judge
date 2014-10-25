/* @JUDGE_ID: 53xxxx 406 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int IsPrime(int n)
{
    int i;

    if (n % 2 == 0) return 0;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int n,c;
    int p[1000];
    int i,t=2,coun=0,ptst,pten;
    p[0]=1;
    p[1]=2;
    for(i=3;i<1000;i++)
    {
       if(IsPrime(i))
       {
          p[t]=i;
          t++;
       }
       else
       {
          p[i]=1002;
       }
    }
    while(scanf("%d %d",&n,&c)==2)
    {
        coun=0;
        for(i=0;p[i]<=n;i++)
        {
            coun++;
        }
        if(coun%2==1)
        {
           ptst=(coun-c*2)/2+1;
           pten=(c*2-1)+ptst;
        }
        else
        {
           ptst=(coun-c*2)/2;
           pten=c*2+ptst;
        }
        printf("\n");
        printf("%d %d:",n,c);
        if(coun<=(c*2))
        {
           for(i=0;p[i]<=n;i++)
           {
               printf(" %d",p[i]);
           }
        }
        else
        {
           for(;ptst<pten;ptst++)
           {
              printf(" %d",p[ptst]);
           }
        }    
        printf("\n");
    }

        return 0;
}
/* END_OF_SOURCE_CODE */
