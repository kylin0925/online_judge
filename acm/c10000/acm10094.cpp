/* @JUDGE_ID: 53xxxx 10094 C++ */
/*@BEGIN_OF_SOURCE_CODE*/
#include <stdio.h>
int n;
void c1()
{
        int i;
        for(i=0;i<n/2;i++)
        {
                printf("%d ",i*2+1);
        }
        for(i=n/2;i<n;i++)
        {
                printf("%d ",(i*2)%n);
        }
}
void c2()
{
        int i;
        for(i=0;i<n/2;i++)
        {
                printf("%d ",(n/2+2*i-1)%n);
        }
        for(i=n/2;i<n;i++)
        {
                printf("%d ",(n/2+i*2+2)%n);
        }
}
int main(int argc, char* argv[])
{
        while(scanf("%d",&n)==1)
        {
           if(n<4)
           {
                printf("Impossible\n");
           }
           else if((n%2)==0)
           {
                if((n%6)!=2)
                {
                        c1();
                        printf("\n");
                }
                else if(n%6)
                {
                        c2();
                        printf("\n");
                }
           }
           else if(n&1)
           {
              n--;
              if((n%6)!=2)
              {
                c1();
                printf("%d\n",n);
              }
              else if(n%6)
              {
                c2();
                printf("%d\n",n);
              }
           }
        }
        return 0;
}
/*@END_OF_SOURCE_CODE*/
