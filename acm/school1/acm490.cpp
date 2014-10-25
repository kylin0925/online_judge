/* @JUDGE_ID: 53xxxx 490 C++ */
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
   char st[150][150];
   int s=0,maxl=-1,len,i,j;
   for(i=0;i<150;i++)
   {
    for(j=0;j<150;j++)
    {
       st[i][j]='\0';
    }
   }
   while(gets(st[s]))
   {
        len=strlen(st[s]);

        if(len>maxl) maxl=len;
        s++;
   }
    for(i=0;i<maxl;i++)
    {
        for(j=s-1;j>=0;j--)
        {
            if(st[j][i]!='\0')
             printf("%c",st[j][i]);
            else
              printf(" ");
        }
       printf("\n");
    }
        return 0;
}
