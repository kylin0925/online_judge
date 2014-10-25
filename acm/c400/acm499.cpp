/* @JUDGE_ID: 53xxxx 499 C++ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char bu;
    int  a[30],b[30],i,len,max=-1;
     for(i=0;i<30;i++)
     {
           a[i]=0;
           b[i]=0;
           max=-1;
     }
    while(scanf("%c",&bu)==1)
    {
           if(isupper(bu))
           {
                  a[bu-'A']++;
                  if(a[bu-'A']>max) max=a[bu-'A'];
           }
           else if(islower(bu))
           {
                  b[bu-'a']++;
                  if(b[bu-'a']>max) max=b[bu-'a'];
           }
           if(bu=='\n')
           {
            for(i=0;i<30;i++)
            {
                if(b[i]==max)  printf("%c",i+'a');
                if(a[i]==max)  printf("%c",i+'A');
            }
            printf(" %d\n",max);
              for(i=0;i<30;i++)
              {
                 a[i]=0;
                 b[i]=0;
                 max=-1;
              }
          }

    }
 return 0;
}

