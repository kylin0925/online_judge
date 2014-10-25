/* @JUDGE_ID: 53xxxx 106 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int p[1000001];
int gcd(int m,int n){return ((n==0)?m:gcd(n,m%n));}
int isprime(int a,int b,int c)
{
 if(gcd(gcd(a,b),c)==1) return 1;
 else return 0;
}
int main()
{
  int n,x,y,a,b,c,i,j,cp=0,pp;
  while(scanf("%d",&n)==1){
  pp=n;
  cp=0;
  for(i=0;i<1000001;i++)  p[i]=0;
  for(x=sqrt(n);x>0;x--)
  {
       for(y=x-1;y>0;y--)
       {
          a=x*x+y*y;
          b=2*x*y;
          c=x*x-y*y;
          if(((a*a)==(b*b+c*c))&&(a<=n))
          {
           for(j=1;(a*j)<=n;j++)
           {
            p[a*j]=1;
            p[b*j]=1;
            p[c*j]=1;
           }
           if(!p[a]){p[a]=1;}
           if(!p[b]){p[b]=1;}
           if(!p[c]){p[c]=1;}
           if(isprime(a,b,c)) cp++;
           }
       }
  }
  pp=0;
  for(i=1;i<=n;i++)
  {
   if(!p[i]){pp++;}
  }
  printf("%d %d\n",cp,pp);
  }
  return 0;
}
/* END_OF_SOURCE_CODE */
