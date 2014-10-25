/* @JUDGE_ID: 53xxxx 10003 C++ */
/* @BEGIN_OF_SOURCE_CODE */    
#include <stdio.h>
int n;
int l;
int stick[100];
int m[60][60];

void sov()
{
        int len,i,j;
        int tmp;
        for(len=2;len<=n;len++)
        {
                for(i=0;i<=n-len;i++)
                {
                        m[i][i+len]=999999;
                        for(j=i+1;j<i+len;j++)
                        {
                               tmp=m[i][j]+m[j][len+i]+(stick[i+len]-stick[i]);
                               if(tmp<m[i][i+len]) m[i][i+len]=tmp;
                       }
                }
        }
}
int main(int argc, char* argv[])
{
        int i,j;
        while(scanf("%d",&l)==1)
        {
                if(l==0) break;
                scanf("%d",&n);
                stick[0]=0;
                for(i=1;i<=n;i++)
                {
                        scanf("%d",&stick[i]);
                }
                n++;
                stick[n]=l;
                sov();
                printf("The minimum cutting is %d.\n",m[0][n]);
                for(i=0;i<n;i++){ stick[i]=0;}
                for(i=0;i<n;i++)for(j=0;j<n;m[i][j],j++);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */

