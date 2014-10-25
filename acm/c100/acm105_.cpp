#include <stdio.h>
int main()
{
        int  sky[20000];

        int  r,h,l,i;
        for(i=0;i<20000;i++) sky[i]=-1;
        while(scanf("%d %d %d",&l,&h,&r)==3)
        {
             if(h>sky[l+10000]) sky[l+10000]=h;
             if(h<sky[r+10000]) sky[r+10000]=h;
             else
                 sky[r+10000]=0;
        }
        for(i=0;i<20000;i++)
        {
             if(sky[i]!=-1) printf("%d %d ",i-10000,sky[i]);
        }
        return 0;
}
