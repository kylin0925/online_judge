/*@JUDGE_ID:53xxxx  591 C*/ 
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
void main(void)
{
  int n;
  int h[100];
  int con=0,i,hi,moven=0,setn=1;
  while(scanf("%d",&n)==1)
  {
   moven=0;
   con=0;
   if(n==0) break;
   for(i=0;i<n;i++)
   {
    scanf("%d",&h[i]);
    con+=h[i];
   }
    hi=con/n;
    for(i=0;i<n;i++)
    {
     if(h[i]>hi){
      moven+=(h[i]-hi);
      }
    }
    printf("Set #%d\n",setn++);
    printf("The minimum number of moves is %d.\n",moven);
    printf("\n"); 
  }
}
/*@END_OF_SOURCE_CODE*/
