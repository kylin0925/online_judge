/* @JUDGE_ID: 53xxxx 766 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int n;
int bno[50]={1,1,-1,2,1,6,0,0,-1,30,0,0,1,42,0,0,-1,30,0,0,
             5,66,0,0,-691,2730,0,0,7,6,0,0,-3617,510,0,0,
             43867,798,0,0,-174611,330};
int gcd(int m,int n){return ((n==0)?m:gcd(n,m%n));}
int f(int m){ return ((m==0)?1:(m*f(m-1)));}
int c(int n,int r)
{
        int i,j;
        int res=1;

        for(i=n;i>r;i--)
        {
                res*=i;
        }
        return res;
}
void count(int n)
{
        int res[50]={0};
        int i,j,bk,pk,p=n,sc,sm,t1,t2,mgcd,lcm;
        for(i=0;i<=n+1;i++)
        {
                bk=i,pk=p+1-i;
                if(i>2 && (i-1)%2==0) continue;
                if(p==(pk-1))
                {
                        res[2*(p+1)]=bno[0];
                        res[2*(p+1)+1]=bno[1]*(p+1);
                }
                else if(p==pk)
                {
                        res[2*(p)]=bno[2];
                        res[2*(p)+1]=bno[3];
                }
                else if(pk==0)
                {
                        res[0]=bno[2*(p+1)];
                        res[1]=bno[2*(p+1)+1]*bk;
                }
                else
                {
                        if(bk<=pk && p>pk)
                        {
                                t1=c(p,pk);
                                t2=f(bk);
                        }
                        else if(bk>pk && p>pk)
                        {
                                t1=c(p,bk);
                                t2=f(pk);
                        }
                        mgcd=gcd(t1,t2);
                        t1/=mgcd;
                        t2/=mgcd;
                        sc=t1*bno[i*2];
                        sm=t2*bno[i*2+1];
                        mgcd=gcd(sc,sm);
                        res[2*(p+1-i)]=sc/mgcd;
                        res[2*(p+1-i)+1]=sm/mgcd;
                }
        }
        mgcd=1;
        lcm=1;
        for(i=0,j=0;i<=n+1;i++,j+=2)
        {
                if(res[j]!=0)
                {
                   mgcd=gcd(lcm,res[j+1]);
                   lcm=lcm*res[j+1]/mgcd;
                }
        }
        printf("%d",lcm);
        res[2*p]+=res[2*p+1];
        for(i=2*(n+1);i>=0;i-=2)
        {
                printf(" %d",(res[i]!=0)?res[i]*lcm/res[i+1]:0);
        }
        printf("\n");

}
int main(int argc, char* argv[])
{
        int k;
        scanf("%d",&n);
        for(;n>0;n--)
        {
                scanf("%d",&k);
                count(k);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
