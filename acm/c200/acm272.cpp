/* @JUDGE_ID: 53xxxx 272 C */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
void main(void)
{
   char  c;
   int b=0;
   while(scanf("%c",&c)!=EOF)
   {
     if(c=='\"')
      {
       if(b==0)
       {
        printf("``");
        b=1;
       }
       else
       {
        b=0;
        printf("''");
       }
      }
      else
      {
       printf("%c",c);
      }
   }
}
/* END_OF_SOURCE_CODE */
