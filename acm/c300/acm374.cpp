/* @JUDGE_ID: 53xxxx 374 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
int main(void)
{
 long b,p,m;
 unsigned
 long i,r,rr,pp,pr;
 while(scanf("%d",&b)==1)
 {
  scanf("%d",&p);
  scanf("%d",&m);
  rr=b%m;
  r=rr;
  for(i=2;;i++)
  {
    rr=(rr*r)%m;
    if(rr==r) {i--;break;}
  }
  pp=p/i;
  pr=p%i;
  rr=b%m;
  if(pr==0) pr=i;
  rr=1;
   for(i=0;i<pr; i++)
   {
     rr=(rr*r)%m;
   }
  printf("%d\n",rr);
 }
   return 0;
}
/* END_OF_SOURCE_CODE */
