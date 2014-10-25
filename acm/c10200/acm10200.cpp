/* @JUDGE_ID: 53xxxx 10200 C++ */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
int table[10010]={0};
int isprime(int n)
{
        int i;
        if(n%2==0) return 0;
        for(i=3;i*i<=n;i+=2)
        {
                if(n%i==0)
                        return 0;
        }
        return 1;
}
int main(int argc, char* argv[])
{
        int a,b,i,c;
        for(i=0;i<=10000;i++)
                if(isprime(i*i+i+41)) table[i]=1;
        while(scanf("%d %d",&a,&b)==2)
        {
                c=0;
                for(i=a;i<=b;i++)
                {
                        if(table[i]) c++;
                }
                printf("%.2f\n",(float)c/(float)(b-a+1)*100.0);
        }
        return 0;
}
/* @END_OF_SOURCE_CODE */
