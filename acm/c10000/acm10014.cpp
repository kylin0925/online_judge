/* @JUDGE_ID: 53xxxx 10014 C++ */
#include <stdio.h>
int n;
double c[3500];
double count(int n)
{
    int i;
    double sum=0.0;
    for(i=1;n;n--,i++)
    {
       sum+=n*c[i];
    }
    return sum;
}
int main(int argc, char* argv[])
{
   int i,j,cn;
   double sum,a0,an1,tmp;
   scanf("%d",&n);
   for(;n;n--)
   {
      scanf("%d %lf %lf",&cn,&a0,&an1);
      for(i=1;i<=cn;i++)
      {
         scanf("%lf",&c[i]);
      }
      tmp=count(cn);
      sum=a0+((an1-a0-2*tmp)/(cn+1));
      printf("%.2lf\n",sum);
   }
        return 0;
}
