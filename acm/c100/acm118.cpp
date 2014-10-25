/* @JUDGE_ID: 53xxxx 118 C++ */
#include <stdio.h>
#include <string.h>
int gx,gy,sx,sy,ns=0;
int lostp[100][100][7];
char map(char face,char turnde)
{
      if(turnde=='L')
      {
         if(face=='N')
          return 'W';
         else if(face=='S')
          return 'E';
         else if(face=='W')
          return 'S';
         else if(face=='E')
          return 'N';
      }
      else if(turnde=='R')
      {
         if(face=='N')
          return 'E';
         else if(face=='S')
          return 'W';
         else if(face=='W')
          return 'N';
         else if(face=='E')
          return 'S';
      }
      else if(turnde=='F')
      {
         if(face=='N')
         {
           if(lostp[sx][sy][1]!=1)
           {
            if(sy+1<=gy)
            {
             sy++;
            }
            else
            {
             lostp[sx][sy][1]=1;
             ns=1;
            }
           }
           return 'N';
         }
         else if(face=='S')
         {
           if(lostp[sx][sy][2]!=2)
           {
             if(sy-1>=0)
             {
                sy--;
             }
             else
             {
               lostp[sx][sy][2]=2;
               ns=1;
             }
           }
           return 'S';
         }
         else if(face=='W')
         {
           if(lostp[sx][sy][3]!=3)
           {
            if(sx-1>=0)
            {
             sx--;
            }
            else
            {
               lostp[sx][sy][3]=3;
               ns=1;
            }
           }
           return 'W';
         }
         else if(face=='E')
         {
           if(lostp[sx][sy][4]!=4)
           {
            if(sx+1<=gx)
            {
              sx++;
            }
            else
            {
             lostp[sx][sy][4]=4;
             ns=1;
            }
           }
          return 'E';
         }
      }
}
int main(int argc, char* argv[])
{
        int i,der,j,k;
        char ins[1200],prefa,c;

        for(i=0;i<100;i++)
        {
         for(j=0;j<100;j++)
         {
           for(k=0;k<7;k++){
              lostp[i][j][k]=0;
              }
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
            prefa = map(prefa,ins[i]);
         }
         printf("%d %d %c",sx,sy,prefa);
         (ns) ? printf(" LOST\n"): printf("\n");

         scanf("%d %d %c\n",&sx,&sy,&prefa);
        }
        return 0;
}

