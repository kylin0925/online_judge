/* @JUDGE_ID: 53xxxx 10019 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
#include <math.h>
void sov(int m)
{
      char strm[10];
      int i,b1=0,b2=0,im,len;
      im=m;
      while(im>0)
      {
        if(im%2) b1++;
        im/=2;
      }
      sprintf(strm,"%d",m);
      im=0;
      len=strlen(strm);
      for(i=0;i<len;i++)
      {
         im+=(int)((double)(strm[i]-'0')*pow(16.0,(double)(len-i)));
      }
      while(im>0)
      {
        if(im%2) b2++;
        im/=2;
      }
      printf("%d %d\n",b1,b2);
}
int main(int argc, char* argv[])
{
        int n;
        int m;
        scanf("%d",&n);
        for(;n;n--)
        {
                scanf("%d",&m);
                sov(m);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
 
