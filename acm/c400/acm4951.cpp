/* @JUDGE_ID: 53xxxx 495 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>
char fbl[5002][2500];
int rfb=3;
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
void fb(int n)
{
  int i;
  char a[2500],b[2500],t[2500];
  for(i=0;i<2500;i++){
    a[i]='\0';
    b[i]='\0';
  }
  if (n<=2)
  else if(n<=rfb) printf("The Fibonacci number for %d is %s\n",n,fbl[n-1]);
  else
  {
     a[0]='1',b[0]='1';
     for(i=3;i<=n;i++)
     {
        strcpy(t,b);
        addf(a,b,b);
        strcpy(fbl[i-1],b);
        strcpy(a,t);
     }
     rfb=n;
        printf("The Fibonacci number for %d is %s\n",n,b);
  }
}
int main()
{
   int a;
   fbl[2][0]='3';
   fb(a);
   while(scanf("%d",&a)==1)
   {

      printf("The Fibonacci number for %d is %s\n",n,);
   }
        return 0;
}
/* END_OF_SOURCE_CODE */
