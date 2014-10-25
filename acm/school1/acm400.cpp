/* @JUDGE_ID: 6722RJ 400 C++ */
#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,maxl=1,j,t,hi,w,wc,k;
    char  file[100][100];
    char  tmp[100];
    while(scanf("%d",&n)!=EOF)
    {
          maxl=1;
          for(t=0;t<100;t++){ tmp[t]='\0';}
          for(i=0;i<100;i++)
          {

               for(t=0;t<100;t++){ file[i][t]='\0';}
          }
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

                  }
              }

          }
          for(i=0;i<60;i++)
          {printf("-");}
          printf("\n");
          if(n!=0)
          {
                   w=60/(maxl+2);
                   if(w==0)
                   {
                         hi=n,w=1;
                   }
                   else
                   {
                            hi=n/w;
                   }
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
    }
        return 0;
}
