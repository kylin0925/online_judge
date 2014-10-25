/* @JUDGE_ID: 53xxxx 787 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <stdlib.h>
int in[150];
void mul(int a[150],int tb)
{
        int i,j,x,c=0,sum,b[2]={0};
        int ans[150]={0};
        b[0]=tb%10000;
        b[1]=tb/10000;
        /*for(i=10;i>=0;i--) printf("%04d",a[i]);*/
        /*printf("\n");*/
        for(i=0;i<2;i++)
        {
                for(j=0;j<150;j++)
                {
                        sum=a[j]*b[i]+ans[i+j]+c;
                        ans[i+j]=sum%10000;
                        c=sum/10000;
                }
                /*for(x=10;x>=0;x--) printf("%04d",ans[x]);
                printf("\n");*/
        }
        /*for(i=10;i>=0;i--) printf("%04d",ans[i]);
        printf("\n");*/
        for(i=149;i>=0;i--) a[i]=ans[i];

}
int check(int fa,int a[150],int fb,int b[150])
{
        int ai,bi,i;
        if(fa>fb) return 1;
        else if(fa<fb) return 0;
        for(ai=149;ai>=0;ai--)
        {
                if(a[ai]!=0)break;
        }
        for(bi=149;bi>=0;bi--)
        {
                if(b[bi]!=0)break;
        }
        if(ai>bi) return 1;
        else if(ai<bi) return 0;
        else if(ai==bi)
        {
                for(i=ai;i>=0;i--)
                {
                        if(a[i]>b[i]) return 1;
                        else
                                return 0;
                }
        }

}
void set(int a[150],int b[150])
{
        int i;
        for(i=0;i<150;i++)
        {
                b[i]=a[i];
        }
}
void sov(int n)
{
        int i,j,k,x;
        int max[150]={0};
        int sum[150]={0};
        int fsum=1,fmax,tmp;
        max[0]=in[0]%10000;
        max[1]=in[0]/10000;
        if(in[0]>=0) fmax=1;
        else
                fmax=-1;
        for(i=0;i<n;i++)
        {
                for(j=1;j<=n-i;j++)
                {
                        sum[0]=1;
                        fsum=1;
                        for(x=1;x<150;sum[x]=0,x++);
                        for(k=0;k<j;k++)
                        {
                                if(in[i+k]<0){ fsum*=-1; tmp=abs(in[i+k]);}
                                else{
                                        fsum*=1;tmp=in[i+k];}
                                mul(sum,tmp);
                        }
                        if(check(fsum,sum,fmax,max)){
                                fmax=fsum;
                                set(sum,max);}
                }
        }
        for(i=149;i>=0;i--)
        {
                if(max[i]!=0){ printf("%d",fmax*max[i]); break;}
                if(i==0 && max[i]==0) printf("%d",max[i]);
        }
        i--;
        for(;i>=0;i--)
        {
                printf("%04d",max[i]);
        }
        printf("\n");
}
int main(int argc, char* argv[])
{
        long i=0,n,tmp;
        while(scanf("%d",&tmp)==1)
        {
                if(tmp==-999999)
                {
                        n=i;
                        sov(n);
                        for(i=0;i<n;i++)
                        {
                                in[i]=0;
                        }
                        i=0;
                }else{
                        in[i++]=tmp;
                }
        }
        /*int a[150]={0},b=99999;
        a[0]=9999;
        a[1]=9;
        mul(a,b);*/
        return 0;
}
/* @END_OF_SOURCE_CODE */

 
