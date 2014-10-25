/* @JUDGE_ID: 53xxxx 424 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
void re(char a[])
{
  int i,j;
  char t;
  i=strlen(a)-1;
  for(j=0;j<=i/2;j++)
  {
    t=a[j];
    a[j]=a[i-j];
    a[i-j]=t;
  }
}
void addf(char a[],char b[],char ru[])
{
  int len1,len2,i,c,tmp;
  char *numa,*numb;
  if(strlen(a)>strlen(b))
  {
       len1=strlen(b);
       len2=strlen(a);
       numa=b,numb=a;
  }
  else
  {
       len1=strlen(a);
       len2=strlen(b);
       numa=a,numb=b;
  }
  re(numa),re(numb);
  for(c=0,i=0;i<len1;i++)
  {
       tmp=(numa[i]-'0')+(numb[i]-'0')+c;
       ru[i] = (tmp % 10) + '0';
       c= tmp / 10;
  }
  for(i=len1;i<len2;i++)
  {
       tmp = (numb[i] - '0') + c;
       ru[i] = (tmp % 10) + '0';
       c = tmp / 10;
  }
  if(c == 0)
  {    ru[len2] = '\0';
   }
  else
  {    ru[len2] = c + '0';
       ru[len2 + 1] = '\0';
  }
  re(ru);
}
void main()
{
 char in[100],r[101],*a,*b;
 int i,j,c=0,cc=1;
 gets(r);
 while(gets(in))
 {
    if(in[0]=='0')
    {
      printf("%s",r);
      break;
    }
    addf(in,r,r);


 }

}
/* END_OF_SOURCE_CODE */
