/* @JUDGE_ID: 53xxxx 10004 C++ */
#include <stdio.h>
int grap[300][300];
int v[300],color[300];
int len;
void sov(int n,int i,int c)
{
   int j,f;
   v[i]=1;
   color[i]=c;
   for(j=0;j<n;j++)
   {
       if(grap[i][j] && !v[j])
       {
         len++;
         sov(n,j,!c);
       }
       else if(grap[i][j] && v[j] && color[j]==c)
       {
          len--;
       }
   }
}
int main(int argc, char* argv[])
{
    int n,l,i,j,k,f;

    while(1)
    {
       for(i=0;i<300;v[i]=color[i]=0,i++);
       for(i=0;i<300;i++){for(j=0;j<300;grap[i][j]=0,j++);}
       scanf("%d",&n);
       if(n==0) break;
       scanf("%d",&l);
       len=0;
       for(i=0;i<l;i++)
       {
           scanf("%d %d",&j,&k);
           grap[j][k]=1;
           grap[k][j]=1;
       }
      sov(n,0,0);
        if(len==n-1)
         printf("BICOLORABLE.\n");
        else
         printf("NOT BICOLORABLE.\n");
    }
        return 0;
}
