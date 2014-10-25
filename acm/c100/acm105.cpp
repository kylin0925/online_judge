/* @JUDGE_ID: 53xxxx 105 C++ */
#include <stdio.h>
int main(int argc, char **argv)
{
    int  s[20000]={0};
    int  l,r,h,i,max=0,min=9999;
    while(scanf("%d %d %d",&l,&h,&r)==3)
    {
         for(i=l+10000-1;i<r+10000-1;i++)
         {
             if(s[i]<h) s[i]=h;
         }
         if(r>max) max=r;
         if(l<min) min=l;
    }
   printf("%d %d",min,s[min+10000-1]);
    for(i=min+10000;i<=max+10000;i++)
    {
        if(s[i]!=s[i-1])
        {
            printf(" %d %d",i-10000+1,s[i]);
        }
    }
    printf("\n");
        return 0;
}
