/* @JUDGE_ID: 53xxxx 10007 C++ */
#include <stdio.h>
int table[35][30];
int tmp[100];
void print(int i)
{
   int j;
   for(j=19;j>=0;j--)
   {
      if(table[i][j])
      {
        printf("%d",table[i][j]);
        break;
      }
   }
   j--;
   for(;j>=0;j--)
   {
      printf("%04d",table[i][j]);
   }
   printf("\n");
}
void build()
{
   int i,j,x,y,t,c;
   table[0][0]=table[1][0]=1;
   for(i=2;i<33;i++)
   {
       for(x=0;x<20;tmp[x]=0,x++);
       for(j=0;j<i;j++)
       {
          c=0;
          for(x=0;x<20;x++)
          {
              for(y=0;y<20;y++)
              {
                 t=table[j][x]*table[i-j-1][y];
                 tmp[y+x]+=t%10000+c;
                 c=t/10000;
              }
          }
       }
       for(j=0;j<20;j++)
       {
          table[i][j]+=(tmp[j]%10000);
          table[i][j+1]+=(tmp[j]/10000);
       }
   }
   for(i=2;i<33;i++)
   {
       for(j=2;j<=i;j++)
       {
       c=0;
         for(x=0;x<20;x++)
         {
           t=table[i][x]*j;
           table[i][x]=t%10000+c;
           c=t/10000;
         }
       }
   }

}
int main(int argc, char* argv[])
{
   build();
   int n;
   while(scanf("%d",&n)==1)
   {
      if(!n) break;
      print(n);
   }
        return 0;
}
 
