#include <stdio.h>
#define  N 8
int column[N+1],rup[2*N+1],lup[2*N+1],queen[N+1];
FILE *fp;
void backtrack(int i)
{
     int  j,x,y;
     static int num=0;
     if(i>N)
     {
          fprintf(fp,"sol#%d\n",++num);
            for(y=1;y<=N;y++)
            {
                for(x=1;x<=N;x++)
                {
                    if(queen[y]==x)
                    {
                       fprintf(fp," Q");
                    }
                    else
                    {
                       fprintf(fp," .");
                    }

                }
             fprintf(fp,"\n");
            }

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
      int i,j,n,con;
      int r,c;

      for(i=1;i<=N;i++)
      {
         column[i]=1;
      }
      for(i=1;i<=2*N;i++)
      {
         rup[i]=lup[i]=1;
      }
         fp=fopen("8queen.o","w");
         backtrack(1);
       fclose(fp);  
}
