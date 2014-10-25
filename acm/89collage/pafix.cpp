#include <stdio.h>
int main(int argc, char* argv[])
{
    int c,r,im[100][100],i,j,nw[100][100];
    int tmp[10],x,k,tmps,l,u;
    freopen("pa.dat","r",stdin); //input file: pa.dat
    scanf("%d",&r);
    scanf("%d",&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
               scanf("%d",&im[i][j]);
        }
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
                    for(k=0;k<10;tmp[k]=0,k++);
                    for(k=i-1,l=0;k<=i+1;k++,l++)
                    {
                        for(x=j-1,u=0;x<=j+1;x++,u++)
                        {
                                tmp[l*3+u]=im[k][x];
                        }
                    }
                    for(k=0;k<9;k++)
                    {
                        for(x=0;x<9;x++)
                        {
                                if(tmp[k]<tmp[x])
                                {
                                        tmps=tmp[k];
                                        tmp[k]=tmp[x];
                                        tmp[x]=tmps;
                                }
                        }
                    }
                    nw[i][j]=tmp[4];
        }

    }
    for(i=1;i<=r;i++)
    {
                for(j=1;j<=c;j++)
                {
                 printf("%d ",nw[i][j]);
                }
                printf("\n");
    }

        return 0;
}
