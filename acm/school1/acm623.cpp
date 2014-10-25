/* @JUDGE_ID: 53xxxx 623 C++ */
#include <stdio.h>
#define  LR  300
void mull(int a[],int b,int c[])
{
  int i;
  long d,cy=0;
  for(i=LR-1;i>=0;i--)
  {
    d=a[i];
    c[i]=(d*b+cy)%10000;
    cy=(d*b+cy)/10000;
  }
}
int main()
{
    int n,i,j;
    int s[LR]={0};
    while(scanf("%d",&n)==1)
    {
      s[LR-1]=1;
      for(i=1;i<=n;i++)
      {
        mull(s,i,s);
      }
      for(i=0;i<LR;i++)
      {
         if(s[i]>0)
         {
           printf("%d!\n",n);
           printf("%d",s[i]);
           break;
         }
      }
      for(j=i+1;j<LR;j++)
      {
         printf("%04d",s[j]);
      }
      printf("\n");
      for(i=0;i<LR;i++)
      {
         s[i]=0;
      }
    }
        return 0;
}
 
