/*@JUDGE_ID: 53xxxx 147 C++ DP*/
#include <stdio.h>
long coin[]={5,10,20,50,100,200,500,1000,2000,5000};
long ans[10][5100];
unsigned long cex()
{
   long i,j;
   for(i=5;i<5100;i++)
   {
    ans[0][i]=1;
   }
   for(i=1;i<10;i++)
   {
      for(j=1;j<5100;j++)
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
   float n;
   cex();
   for(scanf("%f",&n);n;scanf("%f",&n))
   {
        printf("%.2f%12ld\n",n,ans[9][(long)(n*100)]);
   }
        return 0;
}
