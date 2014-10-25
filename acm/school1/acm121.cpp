/* @JUDGE_ID: 53xxxx 121 C++ */
#include <stdio.h>
#include <math.h>
int con(double w,double h)
{
    int h1=(int)floor((1+((2*h-2)/sqrt(3))));
    int ski;
    ski=((int)floor(w))*h1;
    if(w-floor(w)<0.5) ski-=h1/2;
    return ski;
}
int main()
{
    double m,n,dhi=sqrt(3)/2,hi,tw;
    int a,b,grid,skew,w1,w2,ts;
    int th,h,h1,h2;
    while(scanf("%lf %lf",&m,&n)==2)
    {
       grid=(int)(floor(m)*floor(n));
       if(con(m,n)>con(n,m))
       {
         skew=con(m,n);
       }
       else{
         skew=con(n,m);
       }
       if(grid>=skew) printf("%d GRID\n",grid);
       else
         printf("%d SKEW\n",skew);
    }
        return 0;
}


