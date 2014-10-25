/* @JUDGE_ID: 53xxxx 371 C++ */
#include <stdio.h>
#include <math.h>
long cunt(long long s)
{
    int len=0;
    long long tmp;
    tmp=s;
    while(1)
    {
       if(tmp%2==0){ tmp=tmp/2,len++;}
       else
       {
          tmp=tmp*3+1;
          len++;
       }
       if(tmp==1){ break;}
    }
    return len;
}
int main()
{
  long a,b,p,ta,tb;
  long i;
  long max,tmp;
  while(1)
  {
   scanf("%ld %ld",&a,&b);
   max=-1;
   if(a>b)
   {
     ta=b,tb=a;
   }
   else
   {
     ta=a,tb=b;
   }
   if(!a && !b) break;
   for(i=ta;i<=tb;i++)
   {
      tmp=cunt(i);
      if(tmp>max){p=i, max=tmp;}
   }
   printf("Between %ld and %ld, %ld generates",ta,tb,p);
   printf(" the longest sequence of %ld values.\n",max);
  }
  return 0;
}
