/* @JUDGE_ID: 53xxxx 278 C++ */
#include <stdio.h>
void main()
{
 int n,r,col;
 char c;
 scanf("%d",&n);
 for(;n>0;n--)
 {
   scanf("%c %d %d\n",&c,&r,&col);
   if(c=='K')
   {
      printf("%d\n",((col+1)/2)*((r+1)/2));
   }
   else if(c=='r' || c=='Q')
   {
      printf("%d\n",((col<r)?col:r));
   }
   else if(c=='k')
   {
     printf("%d\n",((col*r+1)/2));
   }
 }
}
