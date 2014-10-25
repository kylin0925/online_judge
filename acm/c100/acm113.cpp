/* @JUDGE_ID: 53xxxx 113 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int main()
{
  long double a,b,c;
  while(scanf("%Lf",&a)==1)
  {
   scanf("%Lf",&b);
   c=pow(b,1/a);
   printf("%.0Lf\n",c);
  }
  return 0;
}
/* END_OF_SOURCE_CODE */
