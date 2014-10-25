#include <stdio.h>
int main(int argc, char* argv[])
{
    int c,r,im[100][100],i,j,nw[100][100];
    int tmp[3][3],x,y,h,k,sss;
    while(scanf("%d",&r)==1)
    {
         scanf("%d",&c);

         for(i=0;i<r;i++)
         {
             for(j=0;j<c;j++)
             {
               scanf("%d",&im[i][j]);
             }
         }
         for(i=0;i<r;i++)
         {
            for(x=0;x<3;x++)
            {
              for(y=0;y<3;tmp[x][y]=0,y++)
                ;
            }
           for(j=0;j<c;j++)
           {
               if(i==0&&j==0)
               {
                 tmp[1][1]=im[i][j];
                 tmp[1][2]=im[i][j+1];
                 tmp[2][1]=im[i+1][j];
                 tmp[2][2]=im[i+1][j+1];
               }
               else if(i==0&& j==c)
               {
                 tmp[1][0]=im[i][j-1];
                 tmp[1][1]=im[i][j];
                 tmp[2][0]=im[i+1][j];
                 tmp[2][1]=im[i+1][j+1];
               }
               else if(i==r && j==0)
               {
                 tmp[0][1]=im[i-1][j];
                 tmp[0][2]=im[i-1][j+1];
                 tmp[1][1]=im[i][j];
                 tmp[1][2]=im[i][j+1];
               }
               else if(i==r && j==c)
               {
                 tmp[0][0]=im[i-1][j-1];
                 tmp[0][1]=im[i-1][j];
                 tmp[1][1]=im[i][j-1];
                 tmp[1][2]=im[i][j];
               }
               else if(i==0 && j>0)
               {
                 tmp[1][0]=im[i][j-1];
                 tmp[1][1]=im[i][j];
                 tmp[1][2]=im[i][j+1];
                 tmp[2][0]=im[i+1][j-1];
                 tmp[2][1]=im[i+1][j];
                 tmp[2][2]=im[i+1][j+1];
               }
               else if(i>0 && j==0)
               {
                 tmp[0][1]=im[i-1][j];
                 tmp[0][2]=im[i-1][j+1];
                 tmp[1][1]=im[i][j];
                 tmp[1][2]=im[i][j+1];
                 tmp[2][1]=im[i+1][j];
                 tmp[2][2]=im[i+1][j+1];
               }
               else if(i==r &&j>0)
               {
                 tmp[0][0]=im[i-1][j-1];
                 tmp[0][1]=im[i-1][j];
                 tmp[0][2]=im[i-1][j+1];
                 tmp[1][0]=im[i][j-1];
                 tmp[1][1]=im[i][j];
                 tmp[1][2]=im[i][j+1];

               }
               else if(i>0 && j==c)
               {
                 tmp[0][0]=im[i-1][j-1];
                 tmp[0][1]=im[i-1][j];
                 tmp[1][0]=im[i][j-1];
                 tmp[1][1]=im[i][j];
                 tmp[2][0]=im[i+1][j-1];
                 tmp[2][1]=im[i+1][j];

               }
               else
               {
                tmp[0][0]=im[i-1][j-1];
                tmp[0][1]=im[i-1][j];
                tmp[0][2]=im[i-1][j+1];
                tmp[1][0]=im[i][j-1];
                tmp[1][1]=im[i][j];
                tmp[1][2]=im[i][j+1];
                tmp[2][0]=im[i+1][j-1];
                tmp[2][1]=im[i+1][j];
                tmp[2][2]=im[i+1][j+1];

               }
               for(x=0;x<3;x++)
               {
                 for(y=0;y<3;y++)
                 {
                   for(k=0;k<3;k++)
                   {
                     for(h=0;h<3;h++)
                     {
                        if(tmp[x][y]<tmp[k][h])
                        {
                           sss=tmp[x][y];
                           tmp[x][y]=tmp[k][h];
                           tmp[k][h]=sss;
                        }
                     }
                   }
                 }
               }
               //printf("tmp %d\n",tmp[1][1]);
               nw[i][j]=tmp[1][1];
           }
         }
         for(i=0;i<r;i++)
         {
                for(j=0;j<c;j++)
                {
                 printf("%d ",nw[i][j]);
                }
                printf("\n");
         }
    }
        return 0;
}
