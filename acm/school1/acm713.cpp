#include <stdio.h>
#include <string.h>
int   f[10] ={1,0,1,1,0,1,1,0,1,1};
int   se[20]={1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1};
int   mi[10]={0,0,1,1,1,1,1,0,1,1};
int   fo[20]={1,1,0,1,1,0,0,1,0,1,1,0,1,1,0,1,1,1,0,1};
int   la[10]={1,0,1,1,0,1,1,0,1,0};
int main()
{
       int len,i,lnum,j;
       char num[15],ca='|',sp=' ';
       while(1)
       {
           scanf("%d %s",&len,&num);
           lnum=strlen(num);
           printf(" ");
           for(i=0;i<lnum;i++)
           {
              if(f[num[i]-'0'])
              {
                 for(j=0;j<len;j++)
                 {
                    printf("-");
                 }
              }
              else
              {
                 for(j=0;j<len;j++)
                 {
                    printf(" ");
                 }
              }
              printf("%*c",2,sp);
           }
           printf("\n");

           for(i=0;i<len;i++)
           {
              for(j=0;j<lnum;j++)
              {
                    if(se[(num[j]-'0')*2])
                    {
                         printf("|");
                    }
                    if(se[(num[j]-'0')*2+1])
                    {
                         printf("%*c%c",len,sp,ca);
                    }
                    if(se[num[j]-'0']==0)
                    {
                         printf(" ");
                    }
                    printf("%*c",2,sp);
              }
              printf("\n");
            }
           printf(" ");
           for(i=0;i<lnum;i++)
           {
              if(mi[num[i]-'0'])
              {
                 for(j=0;j<len;j++)
                 {
                    printf("-");
                 }
              }
              else
              {
                 for(j=0;j<len;j++)
                 {
                    printf(" ");
                 }
              }
              printf("  ");
           }
           printf("\n");
           for(i=0;i<len;i++)
           {
              for(j=0;j<lnum;j++)
              {
                    if(fo[(num[j]-'0')*2])
                    {
                         printf("|");
                    }
                    if(fo[(num[j]-'0')*2+1])
                    {
                         printf("%*c%c",len+1,sp,ca);
                    }
                    if(fo[num[j]-'0']==0)
                    {
                         printf(" ");
                    }
                   
              printf(" ");
              }
              printf("\n");
            }
            printf(" ");
           for(i=0;i<lnum;i++)
           {
              if(la[num[i]-'0'])
              {
                 for(j=0;j<len;j++)
                 {
                    printf("-");
                 }
              }
              else
              {
                 for(j=0;j<len;j++)
                 {
                    printf(" ");
                 }
              }
              printf("  ");
           }
           printf("\n");
       }
        return 0;
}
