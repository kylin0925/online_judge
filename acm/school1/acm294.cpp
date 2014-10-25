/* @JUDGE_ID: 53xxxx 294 C++ */
#include <stdio.h>
long prime[50000];
long fa[1000],ex[1000];
int isprime(long n)
{
    int i;
    if(n%2==0) return 0;
    for(i=3;i*i<n;i+=2)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int build()
{
     long i,j;
     prime[0]=1;
     prime[1]=2;
     for(i=3,j=2;i<50000;i+=2)
      if(isprime(i)) prime[j++]=i;
     return j-1;
}
int factor(long n)
{
     int i,j,c=0,w,s=1;
     for(i=0;i<1000;fa[i]=0,ex[i]=0,i++)
           ;
     for(i=0,w=n;w%2==0 && w>1;w/=2,i++)
           ;
     fa[c]=2;
     ex[c++]=i;
     s*=(i+1);
     for(i=2;prime[i]!=0 && prime[i]<=w;i++){
       for(j=0;w%prime[i]==0 && w>1;w/=prime[i],j++)
            ;
        s*=(j+1);
     }

     return s;
}
int main(int argc, char* argv[])
{
       long l,u,tmp,n,mp,ml;
       int max,c;
       c=build();
       scanf("%d",&n);
       for(;n>0;n--)
       {
          max=1;

          scanf("%d %d",&l,&u);
          mp=l;
          ml=l;
          for(;ml<=u;ml++)
          {
              tmp=factor(ml);
              if(max<tmp){max=tmp,mp=ml;}
          }
          printf("Between %d and %d, %d",l,u,mp);
          printf(" has a maximum of %d divisors.\n",max);
       }
        return 0;
}
