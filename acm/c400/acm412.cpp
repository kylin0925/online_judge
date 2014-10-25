/* @JUDGE_ID: 53xxxx 412 C++ */
#include <stdio.h>
#include <math.h>
int gcd(int m,int n){return ((n==0)?m:gcd(n,m%n));}
int ser[100];
int main(int argc, char* argv[])
{
        int n,ngcd,m,i,j,igcd;
        double pi;
        while(scanf("%d",&n)==1)
        {
                ngcd=0;
                if(!n) break;
                for(i=0;i<n;i++) scanf("%d",&ser[i]);
                for(i=0;i<n-1;i++)
                {
                   for(j=i+1;j<n;j++)
                   {
                       igcd=gcd(ser[i],ser[j]);
                       if(igcd==1) ngcd++;
                   }
                }
                if(ngcd>0)
                {
                   pi=sqrt((double)n*((double)n-1.0)*3.0/(double)ngcd);
                   printf("%.6lf\n",pi);
                }
                else
                {
                   printf("No estimate for this data set.\n");
                }
        }
        return 0;
}
 
