/* @JUDGE_ID: 53xxxx 10003 C++ */
/* @BEGIN_OF_SOURCE_CODE */    
#include <stdio.h>
int n;
int l;
int stick[100];
int r[100]={0};
int mint;
int tot;
int findl(int s)
{
        int i;
        for(i=s-1;i>=0;i--){ if(r[i])break;}
        if(i==-1) return 0;
        return stick[i];
}
int findr(int s)
{
        int i;
        for(i=s+1;i<n;i++){if(r[i]) break;}
        if(i==n) return l;
        return stick[i];
}
void sov(int ct,int s,int end,int len)
{
        int i;
        r[ct]=1;
        tot+=end-s;
        for(i=0;i<n;i++)
        {
                if(!r[i])
                {
                        s=findl(i);
                        end=findr(i);
                        //printf("len %d: %d %d %d\n",len+1,stick[i],s,end);
                        sov(i,s,end,len+1);
                        tot-=end-s;
                        r[i]=0;
                }
        }
        if(len==n && tot<mint) mint=tot;
}
int main(int argc, char* argv[])
{
        int i,j;
        while(scanf("%d",&l)==1)
        {
                if(l==0) break;
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                        scanf("%d",&stick[i]);
                }
                tot=0;
                mint=999999;
                for(i=0;i<n;i++)
                {
                 tot=0;
                 //printf("len 1: %d %d %d\n",stick[i],0,l);
                 sov(i,0,l,1);
                  for(j=0;j<n;j++)r[j]=0;
                }
                printf("The minimum cutting is %d\n",mint);
                for(i=0;i<n;i++)
                {
                        r[i]=0;
                }
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */

