/* @JUDGE_ID: 53xxxx 138 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int main()
{
  long a[14],b[14],i;
  a[0]=0;
  b[0]=0;
  a[1]=1;
  b[1]=1;
  a[2]=6;
  b[2]=8;
  printf("6 8\n");
  for(i=3;i<=11;i++)
  {
   a[i]=a[i-1]*7-a[i-2]*7+a[i-3];
   b[i]=b[i-1]*7-b[i-2]*7+b[i-3];
   printf("%d %d\n",a[i],b[i]);
  }
  return 0;
}
/* END_OF_SOURCE_CODE */
