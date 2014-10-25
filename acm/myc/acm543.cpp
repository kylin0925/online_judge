/* @JUDGE_ID: 53xxxx 543 C++ */
#include <stdio.h>
int isprime(long n)
{
    int i;

    if(n==2)
     return 1;
    if (n % 2 == 0) return (0);
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return (0);
    }
    return (1);
}
int main()
{
    int p,i;
    long n;
    while(1)
    {
         scanf("%d",&p);
         if(p==0) break;
         for(i=3;i<p;i++)
         {
           if(isprime(i))
           {
             n=p-i;
             if(isprime(n))
             {
                printf("%d = %d + %d\n",p,i,n);
                break;
             }
           }
         }
    }
        return 0;
}
 
