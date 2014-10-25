/* @JUDGE_ID: 53xxxx 103 C++ */
#include <stdio.h>
int box[50][50];
int tmp[50];
int ans[50];
int count;
void init()
{
   int i,j;
   for(i=0;i<50;i++)
   {
     tmp[i]=ans[i]=0;
     for(j=0;j<50;j++)
     {
        box[i][j]=0;
     }
   }
}
void sort(int i,int n)
{
   int x,y,tmp;
   for(x=0;x<n;x++)
   {
      for(y=0;y<n;y++)
      {
         if(box[i][x]<box[i][y])
         {
            tmp=box[i][x];
            box[i][x]=box[i][y];
            box[i][y]=tmp;
         }
      }
   }
}
int connect(int i,int j,int d)
{
    int x;
    for(x=0;x<d;x++)
    {
       if(box[i][x]>=box[j][x])return 0;
    }
    return 1;
}
void dfs(int i,int n,int d)
{
   int j;
   for(j=0;j<n;j++)
   {
       if(connect(i,j,d))
       {
         tmp[count++]=j;
         tmp[0]++;
         dfs(j,n,d);
       }
   }
   if(j==n && tmp[0]>ans[0])
   {
      for(j=0;j<count;j++)
      {
        ans[j]=tmp[j];
      }
   }
   count--; tmp[0]--;
}
int main(int argc, char* argv[])
{
    int n,d,i,j,k,x;
    while(scanf("%d %d",&n,&d)==2)
    {
         init();
         for(i=0;i<n;i++)
         {
            for(j=0;j<d;j++)
            {
                scanf("%d",&box[i][j]);
            }
            sort(i,d);
         }
        for(i=0;i<n;i++)
        {
           for(j=0;j<50;j++)
             tmp[j]=0;
           count=0;
           tmp[count]=count+1;
           tmp[count+1]=i;
           count+=2;
           dfs(i,n,d);
        }
        printf("%d\n",ans[0]);
        for(i=1;i<=ans[0];i++)
        {
          printf("%d ",ans[i]+1);
        }
        printf("\n");
    }
        return 0;
}
