#include <stdio.h>
int main()
{
   int n,i,j,x,y,h,w;
   int ma[4][4],sum,max;
   while(scanf("%d",&n)==1)
   {
       max=-1;
       sum=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&ma[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(x=i;x<n;x++)
                {
                    for(y=j;y<n;y++)
                    {
                       for(h=i;h<=x;h++)
                       {
                           for(w=j;w<=y;w++)
                           {
                               sum+=ma[h][w];
                           }
                       }
                       if(max<sum) max=sum;
                       sum=0;
                    }
                }
            }
        }
       printf("%d\n",max);
   }

        return 0;
}
 
