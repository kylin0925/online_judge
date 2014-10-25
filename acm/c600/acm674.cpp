/* @JUDGE_ID: 53xxxx 674 C++ */
#include <stdio.h>
long coin[]={1,5,10,25,50};
long ans[10][8000];
unsigned long cex()
{
   long i,j;
   for(i=0;i<10;i++)
   {
      for(j=0;j<8000;j++)
      {
         if(i==0) ans[0][j]=1;
         else
           ans[i][j]=0;
      }
   }
   for(i=1;i<5;i++)
   {
      for(j=1;j<7490;j++)
      {
         if((j-coin[i])==0)
         {
            ans[i][j]=ans[i-1][j]+1;
         }
         else if((j-coin[i])>0)
         {
            ans[i][j]=ans[i-1][j]+ans[i][j-coin[i]];
         }
         else
           ans[i][j]=ans[i-1][j];
      }
   }

}
int main(int argc, char* argv[])
{
   int n;
   unsigned long c;
   cex();
   while(scanf("%d",&n)==1)
   {
       printf("%ld\n",ans[4][n]);
   }
        return 0;
}
 
