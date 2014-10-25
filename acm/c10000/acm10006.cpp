/* @JUDGE_ID: 53xxxx 10006 C++ */
/*@begin_of_source_code*/
#include <stdio.h>
int table[65010]={0};
void build_prime()
{
    int i,j;
    for(i=2;i<65001;i++)
    {
        if(!table[i])
        {
           for(j=2;j<(65001/i);j++)
           {
              table[j*i]=1;
           }
        }
    }
}
int ipow(unsigned long int a,int n,int m)
{
        unsigned long int temp=1;
        while(n>0)
        {
            while(!(n%2))
            {
                n/=2;
                a=(a*a)%m;
            }
                n--;
            temp=(temp*a)%m;
        }
        return temp;
}
int iscam(int n)
{
  int i;
  for(i=2;i<n;i++)
  {
      if(ipow(i,n,n)!=i)
        return 0;
  }
  return 1;
}
int main(int argc, char* argv[])
{
    int i,n,isf;
    build_prime();
    while(scanf("%d",&n)==1)
    {
       if(!n) break;
       if(!table[n])
       {
          printf("%d is normal.\n",n);
       }
       else if(table[n]==1)
       {
         if(iscam(n))
         {
          printf("The number %d is a Carmichael number.\n",n);
          table[n]=2;;
         }
         else
         {                                                         -
           printf("%d is normal.\n",n);
         }
       }
       else if(table[n]==2)
       {
          printf("The number %d is a Carmichael number.\n",n);
       }
    }
        return 0;
}
/*@end_of_source_code*/

