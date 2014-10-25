/* @JUDGE_ID: 53xxxx 232 C++ */
#include <stdio.h>
char sq[50][50];
int main(int argc, char* argv[])
{
    int r,c,i,j,k,num,x,y;
    int resq[50][50][5];
    int n[50][50],puzzle=1,cc;
    while(1)
    {
       for(i=0;i<50;i++)
       {
        for(j=0;j<50;j++)
        {
         for(k=0;k<5;k++)
         {
          resq[i][j][k]=0;
          n[i][j]=0;
         }
        }
       }
       scanf("%d",&r);
       if(r==0) break;
       scanf("%d",&c);
       num=1;
       for(i=0;i<r;i++)
       {
        scanf("%s",sq[i]);
       }
       for(i= 0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               if(sq[i][j]!='*')
               {
                  if(!resq[i][j][0]&&!resq[i][j][1])
                  {
                     n[i][j]=num++;
                     resq[i][j][0]=resq[i][j][1]=1;
                     for(x=i;sq[x][j]!='*' && x<r;x++)
                     {
                      resq[x][j][1]=1;
                     }
                     for(x=j+1;sq[i][x]!='*' && x<c;x++)
                      resq[i][x][0]=1;
                  }
                  else if(!resq[i][j][0]&&resq[i][j][1])
                  {
                     n[i][j]=num++;
                     resq[i][j][1]=0;
                     for(x=j;sq[i][x]!='*' && x<c;x++)
                      resq[i][x][0]=1;
                  }
                  else if(resq[i][j][0]==1&&!resq[i][j][1])
                  {
                     n[i][j]=num++;

                     for(x=i;sq[x][j]!='*' && x<r;x++)
                      resq[x][j][1]=1;
                  }

               }
           }
       }
       printf("puzzle #%d:\n",puzzle++);
       printf("Across\n");
       cc=0;
       for(i=0;i<r;i++)
       {
         cc=0;
         while(cc<c)
         {
          if(resq[i][cc][0]&&n[i][cc]>0)
          {
             printf("  %d.",n[i][cc]);
             while(sq[i][cc]!='*' && sq[i][cc]!='\0')
             {
                printf("%c",sq[i][cc++]);
             }
             printf("\n");
          }
          else
          {
           cc++;
          }
         }
       }
       printf("\nDown\n");
       cc=0;
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             if(resq[i][j][1] && n[i][j]>0)
             {
                printf("  %d.",n[i][j]);
                for(x=i;sq[x][j]!='*' && x<r;x++)
                {
                  printf("%c",sq[x][j]);
                }
                printf("\n");
             }
          }
       }
       printf("\n");
    }
        return 0;
}
