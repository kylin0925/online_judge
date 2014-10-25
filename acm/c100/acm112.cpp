/* @JUDGE_ID: 53xxxx 112 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <stdlib.h>
char buff[10000];
int n;
int findrst(int s)
{
    int i=s+1,f=1;
    while(f)
    {
      if(buff[i]=='(') f++;
        if(buff[i]==')') f--;
        i++;
    }
    return i;
}
int sov(int sum,int s,int e)
{
    int lst,lend,rst,rend,nowno,i;
    if(s+1==e) return false;
    lst=s+1;
    nowno=atoi(&buff[lst]);
    while(buff[lst++]!='(');
    lst--;
    rst=findrst(lst);
    rend=e-1;
    lend=rst-1;
    if(sum==nowno && lst+1==lend && rst+1==rend)
     return true;
    else
     return (sov(sum-nowno,lst,lend) || sov(sum-nowno,rst,rend));
}
int main(int argc, char* argv[])
{
    char c;
    int l,i;
    while(scanf("%d",&n)==1)
    {
      scanf(" ");
      scanf("%c",&c);
      l=1;
      i=1;
      buff[0]=c;
      while(l)
      {
         scanf("%c",&c);
         if(c!='\n' && c!=' ')
          buff[i++]=c;
         if(c=='(') l++;
         else  if(c==')') l--;

      }
     if(!sov(n,0,i-1) || i==2) printf("no\n");
      else
         printf("yes\n");
    }
        return 0;
}
/* END_OF_SOURCE_CODE */
