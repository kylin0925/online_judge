/* @JUDGE_ID: 53xxxx 108 C++ */
#include <stdio.h>
int main(int argc, char* argv[])
{
    int in[110][110]={0};
    int n,i,j,l,r,pmax=0,max=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           scanf("%d",&in[i][j]);
            if(j>1)
            {
             in[i][j]+=in[i][j-1];
            }
       }
    }
    
    for(l=1;l<=n;l++)
    {
      for(r=l;r<=n;r++)
      {
        pmax=0;
        for(i=1;i<=n;i++)
        {
          pmax+=in[i][r]-in[i][l-1];
          if(pmax<0) pmax=0;
          if(max<pmax) max=pmax;
        }
      }
    }
    printf("%d\n",max);
    return 0;
}

