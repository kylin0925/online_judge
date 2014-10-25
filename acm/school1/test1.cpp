/*   @JUDGE_ID:   6191YA   110   C++   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>


void find(int cnt,int now,char ss[200])
{
  int i,j;

  if(now==cnt)
  {
    for(j=0;j<now*2;j++)
      printf(" ");
    printf("writeln(");
    for(j=0;j<strlen(ss);j++)
    {
      printf("%c",ss[j]);
      if(j==strlen(ss)-1)
        printf(")\n");
      else
        printf(",");
    }
  }
  else
  {
    for(i=now;i>=0;i--)
    {
      for(j=0;j<now*2;j++)
        printf(" ");
      if(i==now)
        printf("if %c < %c then\n",ss[i-1],'a'+now);
      else if(i==0)
        printf("else\n");
      else
        printf("else if %c < %c then\n",ss[i-1],'a'+now);
      for(j=10;j>i;j--)
        ss[j]=ss[j-1];
      ss[i]='a'+now;
      find(cnt,now+1,ss);
      for(j=i;j<9;j++)
        ss[j]=ss[j+1];
    }
  }
}
void main(void)
{
  int i;
  int cnt;
  //char end[50];

  scanf("%d",&cnt);
  printf("program sort(input,output);\n");
  printf("var\n");
  for(i=0;i<cnt;i++)
  {
    printf("%c",'a'+i);
    if(i==cnt-1)
      printf(" : integer;\n");
    else
      printf(",");
  }
  printf("begin\n");
  printf("  readln(");
  for(i=0;i<cnt;i++)
  {
    printf("%c",'a'+i);
    if(i==cnt-1)
      printf(");\n");
    else
      printf(",");
  }
  find(cnt,1,"a");
  //cout<<"end.\n";

  puts("end.");
}
