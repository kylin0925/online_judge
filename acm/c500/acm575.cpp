/* @JUDGE_ID: 53xxxx 575 C++ */
#include <stdio.h>
#include <string.h>
unsigned long mypow(int n)
{
  int i;
  unsigned long m=2;
  for(i=1;i<n;i++)
  {
      m*=2;
  }
  return m;
}
int main(int argc, char **argv)
{
    char buffer[1000];
    unsigned long n;
    int len,ex,i;
    while(1)
    {
         scanf("%s",buffer);
         if(buffer[0]=='0') break;
         len=strlen(buffer);
         n=0;
         ex=len;
         for(i=0;i<len;ex--,i++)
         {
            n+=(buffer[i]-'0')*(mypow(ex)-1);
         }
         printf("%d\n",n);
    }
        return 0;
}
