/* @JUDGE_ID:53xxxx 264 C++ */
#include <stdio.h>
int main(int argc, char* argv[])
{
     long n,i,j,m,s,sub;
     unsigned long sum;
     while(scanf("%d",&n)!=EOF)
     {
        if(n==1){ printf("TERM 1 IS 1/1\n");}
        else
        {
         for(i=1;i<n;i++)
         {
            sum=(1+i)*i/2;
            if(sum>=n) break;
         }
         i--;
         sum=(1+i)*i/2;
         sub=n-sum;
         i++;
         if(i%2==0)
         {
            m=1,s=i;
            for(;sub>1;sub--)
            {
               m++,s--;
            }
            printf("TERM %d IS %d/%d\n",n,m,s);
         }
         else
         {
            s=1,m=i;
            for(;sub>1;sub--)
            {
               m--,s++;
            }
             printf("TERM %d IS %d/%d\n",n,m,s);
         }
        }
     }
        return 0;
}
