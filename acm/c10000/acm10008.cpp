/* @JUDGE_ID: 53xxxx 10008 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int ch[26]={0};
int cha[26]={0};
char buff[8000];
int main(int argc, char* argv[])
{
    int n,i,j,tmp1,tmp2;
    for(i=0;i<26;i++) cha[i]=i;
    scanf("%d\n",&n);
    while(n>0)
    {
      gets(buff);
      for(i=0;i<strlen(buff);i++)
      {
         if(islower(buff[i])) buff[i]=toupper(buff[i]);
         ch[buff[i]-'A']++;
      }
      n--;
    }
    for(i=0;i<26;i++)
    {
      for(j=0;j<26;j++)
      {
         if(ch[i]>ch[j])
         {
            tmp1=ch[i];
            ch[i]=ch[j];
            ch[j]=tmp1;
            tmp2=cha[i];
            cha[i]=cha[j];
            cha[j]=tmp2;
         }
         if((ch[i]==ch[j])&&(cha[i]<cha[j]))
         {
            tmp1=ch[i];
            ch[i]=ch[j];
            ch[j]=tmp1;
            tmp2=cha[i];
            cha[i]=cha[j];
            cha[j]=tmp2;

         }
      }
    }
    for(i=0;i<26;i++)
    {
       if(ch[i]>0)
          printf("%c %d\n",cha[i]+'A',ch[i]);
    }
        return 0;
}
