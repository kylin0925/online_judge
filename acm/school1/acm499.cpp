/* @JUDGE_ID: 53xxxx 499 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char buffer[1000];
    int len,i,aph[300],max=-1;
    while(gets(buffer))
    {
        max=-1;
         for(i=0;i<300;i++)
         {
             aph[i]=0;
         }
         len=strlen(buffer);
         for(i=0;i<len;i++)
         {
            if(isalpha(buffer[i]))
            {
               aph[buffer[i]]++;
               if(aph[buffer[i]]>max) max=aph[buffer[i]];
            }
         }
         if(max!=-1)
         {
          for(i=0;i<300;i++)
          {
             if(aph[i]==max) printf("%c",i);
          }
          printf(" %d\n",max);
         }
    }
        return 0;
}

