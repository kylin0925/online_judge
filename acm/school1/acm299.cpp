#include <stdio.h>
int main()
{
       int c,n,i,j,mov;
       int l[100],tmp;
       for(i=0;i<100;i++){ l[i]=0;}

       scanf("%d",&c);
       for(;c>0;c--)
       {
            scanf("%d",&n);
            mov=0;
            for(i=0;i<n;i++){ scanf("%d",&l[i]);}
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(l[i]>l[j])
                    {
                        tmp=l[i];
                        l[i]=l[j];
                        l[j]=tmp;
                        mov++;
                    }
                }
            }
            printf("%d\n",mov);
            for(i=0;i<n;i++) l[i]=0;

       }
        return 0;
}
