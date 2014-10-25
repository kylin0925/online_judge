/* @JUDGE_ID: 53xxxx 400 C++ */
#include <stdio.h>
#include <string.h>
int n,i,maxl,j,t,hi,w,wc,k;
int main()
{

    char  file[1000][64];
    char  tmp[64];
    while(scanf("%d",&n)!=EOF)
    {
          maxl=1;
          for(i=0;i<n;i++)
          {
              scanf("%s",&file[i]);
              if(maxl<strlen(file[i]))
              {
                 maxl=strlen(file[i]);
              }
          }
          for(i=0;i<n;i++)
          {
              for(j=0;j<n;j++)
              {
                  if(strcmp(file[i],file[j])<0)
                  {
                     strcpy(tmp,file[i]);
                     strcpy(file[i],file[j]);
                     strcpy(file[j],tmp);
                     //for(t=0;t<64;t++) tmp[t]='\0';
                  }
              }

          }
          for(i=0;i<60;i++)
          {printf("-");}
          printf("\n");
          w=60/(maxl+2);
          hi=n/w;
          wc=w;
          if(n<w){ hi=n; wc=n;}
          if(w*hi<n)
          {
             hi++;
             //wc=w;
          }
          for(i=0;i<hi;i++)
          {
            for(j=0,k=0;j<w;j++,k=hi)
            {
                    printf("%-*s",maxl+2,file[i+k*j]);
            }
            printf("\n");
          }
          
    }
        return 0;
}
