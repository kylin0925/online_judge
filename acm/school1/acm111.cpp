/* @JUDGE_ID: 53xxxx 111 C++ */
#include <stdio.h>
int lcs(int n,int s1[],int s2[])
{
     int d[100][100];
     int i,j;
     for(i=0;i<100;i++)
           d[0][i]=0;
     for(i=0;i<100;i++)
           d[i][0]=0;
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
         {
             if(s1[i-1]==s2[j-1])
                d[i][j]=d[i-1][j-1]+1;
             else if(d[i][j-1]>d[i-1][j])
                d[i][j]=d[i][j-1];
             else
                d[i][j]=d[i-1][j];
         }
     }
     return d[n][n];
}
int main(int argc, char* argv[])
{
     int n,i,len;
     int s1[100],s2[100];
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&s1[i]);
     }
     while(!feof(stdin))
     {
       for(i=0;i<n;i++)
       {
         scanf("%d",&s2[i]);
       }
       len=lcs(n,s1,s2);
       printf("%d\n",len);
     }
        return 0;
}
