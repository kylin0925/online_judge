/* @JUDGE_ID: 53xxxx 299 C++ */
#include <stdio.h>
int main(int argc, char **argv)
{
    int a[100],n,s,i,j,max,tmp;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        scanf("%d",&s);
        max=0;
        for(i=0;i<s;i++)
        {
             scanf("%d",&a[i]);
        }
        for(i=0;i<s;i++)
        {
            for(j=s-1;j>i;j--)
            {
                if(a[j]<a[j-1])
                {
                 tmp=a[j];
                 a[j]=a[j-1];
                 a[j-1]=tmp;
                 max++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",max);
    }
        return 0;
}
