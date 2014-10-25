/* @JUDGE_ID: 53xxxx 474 C*/
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int main()
{
  int in,pow2e;
  double cc;
  while(scanf("%d",&in)==1)
  {
   pow2e=(int)ceil((double)(in*log10(2)));
   cc=pow(2,pow2e/log10(2)-in);
   printf("2^-%d = %.3lfe-%d\n",in,cc,pow2e);
  }
 return 0;
}
/* END_OF_SOURCE_CODE */
