/* @JUDGE_ID: 53xxxx 750 C++ */
#include <stdio.h>
#define  N 8
int column[N+1],rup[2*N+1],lup[2*N+1],queen[N+1];
int qu[92][9][9];
void backtrack(int i)
{
     int  j,x,y;
     static int num=0;
     if(i>N)
     {
            for(y=1;y<=N;y++)
            {
                for(x=1;x<=N;x++)
                {
                    if(queen[y]==x)
                    {
                       qu[num][y][x]=1;
                    }
                    else
                    {
                       qu[num][y][x]=0;
                    }
                }
            }
            num++;
     }
     else
     {
            for(j=1;j<=N;j++)
            {
                if(column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1)
                {
                   queen[i]=j;
                   column[j]=rup[i+j]=lup[i-j+N]=0;
                   backtrack(i+1);
                   column[j]=rup[i+j]=lup[i-j+N]=1;
                }
            }
     }
}
int main()
{
      int i,j,n,con,amon;
      int r,c;

      for(i=1;i<=N;i++)
      {
         column[i]=1;
      }
      for(i=1;i<=2*N;i++)
      {
         rup[i]=lup[i]=1;
      }

         backtrack(1);
      scanf("%d",&amon);
      for(;amon>0;amon--)
      {
       scanf("%d%d",&r,&c);

           con=0;
           printf("SOLN      COLUMN\n");
           printf(" #     1 2 3 4 5 6 7 8\n\n");
           for(n=0;n<92;n++)
           {

             if(qu[n][c][r]==1)
             {
                printf(" %-6d",++con);
                for(i=1;i<=8;i++)
                {
                    for(j=1;j<=8;j++)
                    {
                        if(qu[n][i][j]==1)
                        {
                           printf("%-2d",j);
                        }
                    }
                 }
               printf("\n");
              }
           }
        }
        return 0;
}
