/* @JUDGE_ID: 53xxxx 490 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
    char in[150][150];
    int i,j,s,maxl;
    s=0 ;
    for(i=0;i<150;i++)
    {
     for(j=0;j<150;j++)
     {
        in[i][j]=' ';
     }
    }
    maxl=0;
     while(gets(in[s]))
     {
          if(strlen(in[s])>maxl) maxl=strlen(in[s]);
          s++;
     }
     for(i=0;i<maxl;i++)
     {
       for(j=s-1;j>=0;j--)
       {
           printf("%c",in[j][i]);
       }
       printf("\n");
     }
        return 0;
}
