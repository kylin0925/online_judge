/* @JUDGE_ID: 53xxxx 10000 C++ */
#include <stdio.h>
int mat[150][150];
int maxlen=-9999,len,finish;
void init()
{
   int i,j;
   maxlen=-9999;
   for(i=0;i<150;i++)
   {
    for(j=0;j<150;j++)
    {
       mat[i][j]=0;
    }
   }
}
/*void pmat(int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
       printf("%d",mat[i][j]);
    }
    printf("\n");
   }

} */
void dfs(int v,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(mat[v][i])
    {
      len++;
      /*printf("%d --> %d\n",v,i);*/
      dfs(i,n);
      len--;
    }
  }
    if(len>maxlen){ maxlen=len;finish=v;}
    /*printf("------------------\n"); */
}
int main(int argc, char* argv[])
{
    int n,start,i,cc=1;
    int a,b;
    while(1)
    {
       init();
       scanf("%d",&n);
       if(!n) break;
       scanf("%d",&start);
       while(1)
       {
          scanf("%d %d",&a,&b);
          if(!a && !b) break;
          mat[a-1][b-1]=1;
       }
       /*pmat(n);*/
       len=0;
       finish=0;
       dfs(start-1,n);
       printf("Case %d:",cc++);
       printf("The longest path from %d has ",start);
       printf("length %d, finishing at %d.\n",maxlen,finish+1);
    }
        return 0;
}
