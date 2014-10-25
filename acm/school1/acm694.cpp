/* @JUDGE_ID: 53xxxx 694 C++ */
#include <stdio.h>
int cunt(unsigned long int s, unsigned long int st)
{
    int len=0;
    unsigned long int tmp;
    tmp=s;
    while(1)
    {
       if(tmp>st) break;
       if(tmp==1){len++; break;}
       if(tmp%2==0){ tmp=tmp/2,len++;}
       else
       {
          tmp=tmp*3+1;
          len++;
       }
    }
    return len;
}
void main()
{
  unsigned long int a,l,c=1;
  int len;
  while(1)
  {
      scanf("%ld %ld",&a,&l);
      if(a==-1&&l==-1) break;
      len=cunt(a,l);
      printf("Case %ld:",c++);
      printf(" A = %ld, limit = %ld, number of terms = %d\n",a,l,len);
  }
}
