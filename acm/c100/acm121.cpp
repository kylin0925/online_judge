/* @JUDGE_ID: 53xxxx 121 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
#define swap(a,b) {int t;t=a; a=b;b=t;}
int main()
{
    double m,n,dhi;
    int a,b,grid,skew,maxw,hi,w1,w2;

    while(scanf("%lf %lf",&m,&n)==2)
    {
        if(m>n)
        {
         swap(m,n);
         a=m,b=n;
         grid=a*b;
        }
        else
        {
          a=m,b=n;
          grid=a*b;
        }
        hi=(m-1)/(sqrt(3)/2);
        dhi=hi*sqrt(3)/2+1;
        if((m-dhi)>0.5)
        {
         hi++;
        }
        maxw=b;
        w1=((n-0.5)/0.5)/2;
        w2=maxw;
        if(hi%2==1)
        {
          skew=w2+(hi/2+1)*(w1)+(hi/2)*(w2);
        }
        else
        {
                  skew=w2+(hi/2)*(w1)+(hi/2)*(w2);
        }
        if(skew>grid)
        {
          printf("%d skew\n",skew);
        }
        else
        {
            printf("%d grid\n",grid);
        }
    }
        return 0;
}
/* END_OF_SOURCE_CODE */
