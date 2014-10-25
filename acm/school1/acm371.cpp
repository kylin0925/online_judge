/* @JUDGE_ID: 53xxxx 371 C++ */
#include <stdio.h>
#include <math.h>

int g[1000000]={0};
int cunt(long double s)
{
    int len=0;
    long double tmp;
    tmp=s;
    while(1)
    {
       if(tmp<=1000000 && g[(int)(tmp)-1]>0) return (len+g[(int)tmp-1]);
       else if(fmod(tmp,2)==0){ tmp=tmp/2,len++;}
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
  long double a,b,p,ta,tb;
  long double i;
  long double max,tmp;
  for(i=0;i<1000000;i++)
  {
     g[(int)i]=cunt((int)i+1);
  }
  while(1)
  {
   scanf("%Lf %Lf",&a,&b);
   max=-1;
   if(ta>tb){ ta=b,tb=a;}
   else
   {   ta=a,tb=b; }
   if(!a && !b) break;
   for(i=ta;i<=tb;i++)
   {
      if(i<1000000) tmp=g[(int)i-1];
      else
         tmp=cunt(i);
      if(tmp>max){p=i, max=tmp;}
   }
   printf("Between %.0Lf and %.0Lf, %.0Lf generates",a,b,p);
   printf(" the longest sequence of %.0Lf values.\n",max);
  }
  return 0;
}
