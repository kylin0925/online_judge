/* @JUDGE_ID: 53xxxx 100 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
void main(void)
{
  long n,j,end,cn;
  long max=-1,c=0;
  while( scanf("%d %d",&end,&n)!=NULL){
  cn=n;
  j=n;
  for(;j>=end;j--)
  {
   n=j;
   c=0;
   while(n!=1)
   {
    if((n%2)!=0)
    {
     n=3*n+1;
     c++;
    }
    else
    {
     n=n/2;
     c++;
    }
   }
   if(max<c) max=c+1;
  }
  printf("%d %d %d",end,cn,max);
  max=-1;
 }
}
/* @END_OF_SOURCE_CODE */
