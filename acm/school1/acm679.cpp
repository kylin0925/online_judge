/* @JUDGE_ID: 53xxxx 679 C++ */
#include <stdio.h>
int main(int argc, char* argv[])
{
   int n,d,l,t,ans;

   scanf("%d",&n);
   for(;n>0;n--)
   {
      scanf("%d %d",&d,&l);
      t=l-1;
      d--;
      ans=1;
      while(d>0)
      {
         ans=ans*2+t%2;
         t=t/2;
         d--;
      }
      printf("%d\n",ans);
   }
        return 0;
}
