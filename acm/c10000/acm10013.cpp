/* @JUDGE_ID: 53xxxx 10013 C++ */
#include <stdio.h>
char a[1000000],b[1000000],c[1000000];
void p(int i,int ca)
{
   int p=i-1,s;

   for(;ca>0;p--)
   {
      s=c[p]-'0'+ca;
      c[p]=s%10+'0';
      ca=s/10;
  }
}
int main(int argc, char* argv[])
{
   int n;
   int l;
   int i,ca;
   scanf("%d\n",&n);
   for(;n>0;n--)
   {
      scanf("%d\n",&l);
      for(i=0;i<l;i++)
      {
        scanf("%d %d",&a[i],&b[i]);
      }
      for(i=0;i<l;i++)
      {
         c[i]=(a[i]+b[i])%10+'0';
         ca=(a[i]+b[i])/10;
         p(i,ca);
      }
      c[l]='\0';
      printf("%s\n",c);
   }
        return 0;
}
