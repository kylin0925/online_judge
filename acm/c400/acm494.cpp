/*@JUDGE_ID:53xxxx  494 C*/ 
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
void main(void)
{
  char a;
  int count=0,b=0;
  while(scanf("%c",&a)==1)
  {
   if((a!=' ')&&(a!='\n'))
   {
    if((a>='a' && a<='z') || (a>='A'&& a<='Z'))
    { b=0;}
   }
   else
   {
    if(b==0)
    {
      count++;
      b=1;
    }
   }
   if((a=='\n')&&(count>0)) printf("%d\n",count),count=0;
  }
}
/*@END_OF_SOURCE_CODE*/
