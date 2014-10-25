/* @JUDGE_ID: 53xxxx 686 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>
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
     long m;
     long i,t;
     int con;
     while(1)
     {
       con=0;
       scanf(" %ld",&m);
       if(m==0) break;
       for(i=2;i*2<=m;i++)
       {
          if(isprime(i))
          {
             t=m-i;
             if(isprime(t))
             {
               con++;
             }
          }
       }
       printf("%d\n",con);
     }
        return 0;
}
/* END_OF_SOURCE_CODE */
