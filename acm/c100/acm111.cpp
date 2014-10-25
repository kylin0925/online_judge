/* @JUDGE_ID: 53xxxx 111 C++ */
#include <stdio.h>
int lcs(int n,int s[],int ss[])
{
    int d[30][30],i,j;
    for(i=0;i<=n;i++) d[i][0]=0;
    for(i=0;i<=n;i++) d[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             if(s[i-1]==ss[j-1]) d[i][j]=d[i-1][j-1]+1;
             else if(d[i][j-1]>d[i-1][j]) d[i][j]=d[i][j-1];
             else
                  d[i][j]=d[i-1][j];
        }
    }
    return d[n][n];
}
int main(int argc, char **argv)
{
    int s[30],ss[30],i,j,n,maxl;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
         scanf("%d",&j);
         s[j-1]=i;
    }
    while(scanf("%d",&j)==1)
    {
            ss[j-1]=1;
            for(i=2;i<=n;i++)
            {
             scanf("%d",&j);
             ss[j-1]=i;
            }
            maxl=lcs(n,s,ss);
            printf("%d\n",maxl);
    }

        return 0;
}
