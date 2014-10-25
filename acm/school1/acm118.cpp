/* @JUDGE_ID: 53xxxx 118 C++ */
#include <stdio.h>
#include <string.h>
int gx,gy,sx,sy,ns=0;
int lostp[100][100][7];
char prefa;
char map(char td)
{
     if(td=='R')
     {
        if(prefa=='N') prefa='E';
        else if(prefa=='S') prefa='W';
        else if(prefa=='W') prefa='N';
        else if(prefa=='E') prefa='S';
     }
     else if(td=='L')
     {
        if(prefa=='N') prefa='W';
        else if(prefa=='S') prefa='E';
        else if(prefa=='W') prefa='S';
        else if(prefa=='E') prefa='N';
     }
     else if(td=='F')
     {
        if(prefa=='N')
        {
          if((sy+1)<=gy)
           sy++;
          else
          {
            if(lostp[sy][sx][1]||lostp[sy][sx][4]||lostp[sy][sx][3])
            {
               ns=0;
            }
            else
            {
              lostp[sy][sx][1]=1;
              ns=1;
            }
          }
        }
        else if(prefa=='S')
        {
          if((sy-1)>=0)
           sy--;
          else
          {
            if(lostp[sy][sx][2]||lostp[sy][sx][3]||lostp[sy][sx][4])
            {
              ns=0;
            }
            else
            {
              lostp[sy][sx][2]=1;
            }
          }
        }
        else if(prefa=='W')
        {
          if((sx-1)>=0)
            sx--;
          else
          {
             if(lostp[sy][sx][1]||lostp[sy][sx][3]||lostp[sy][sx][2])
             {
               ns=0;
             }
             else
             {
               lostp[sy][sx][3]=1;
               ns=1;
             }
          }
        }
        else if(prefa=='E')
        {
          if((sx+1)<=gx)
           sx++;
          else
          {
             if(lostp[sy][sx][1]||lostp[sy][sx][2]||lostp[sy][sx][4])
             {
               ns=0;
             }
             else
             {
               lostp[sy][sx][4]=1;
               ns=1;
             }
          }
        }
     }
}
int main(int argc, char* argv[])
{
        int i,der,j,k;
        char ins[120],c;

        for(i=0;i<100;i++)
        {
         for(j=0;j<100;j++)
         {
            for(k=0;k<7;k++)
              lostp[i][j][k]=0;
          }
        }
        scanf("%d %d\n",&gx,&gy);
        scanf("%d %d %c\n",&sx,&sy,&prefa);
        while(scanf("%s",&ins)==1)
        {
         ns=0;

         for(i=0;i<strlen(ins);i++)
         {
           if(ns==0)
             map(ins[i]);
         }
         printf("%d %d %c",sx,sy,prefa);
         (ns) ? printf(" LOST\n"): printf("\n");

         scanf("%d %d %c\n",&sx,&sy,&prefa);
        }
        return 0;
}

