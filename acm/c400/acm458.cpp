/* @JUDGE_ID: 53xxxx 458 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
void main()
{
  char a;
  while(scanf("%c",&a)==1)
  {
    if(a=='\n')
    {
        printf("\n");
        continue;
    }
    else
    {
        printf("%c",a-7);
    }
  }

}
/* END_OF_SOURCE_CODE */
