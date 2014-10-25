/* @JUDGE_ID: 53xxxx 488 C++ */
#include <stdio.h>
int main()
{
    int w;
    int am,i,j,k,n,h;
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
          scanf("%d %d",&w,&am);
          for(k=0;k<am;k++)
          {
              for(i=1;i<=w;i++)
              {
                 for(j=i;j>0;j--){printf("%d",i);}
                 printf("\n");
              }
              for(i=w-1;i>0;i--)
              {
                 for(j=i;j>0;j--){printf("%d",i);}
                 printf("\n");
               }
              printf("\n");
           }
           
     }
        return 0;
}

