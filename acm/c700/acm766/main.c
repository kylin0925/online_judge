#include <stdio.h>
#include <stdlib.h>
/*
  n           p               n
   Sigma x^p = Sigma S(p,k)*k!*Sigma C(x,k)
    x=1         k=1             x=1

                 p
             = Sigma S(p,k)*k!*C(n+1,k+1)
                k=1
                 p
             = Sigma S(p,k)* [(n+1) n ...... (n - k +1) / (k+1)]
                k=1
*/
unsigned long Snum[30][30] = {0};
void print(int s[30][30])
{
	int i ,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			printf("%u ",s[i][j]);
		}	
		printf("\n");
	}
}
int S(int p,int k)
{
	if(k == 1 || p == k)
		return 1;
	return Snum[p-1][k-1] + k * Snum[p-1][k];
}
void makeSnum()
{
	int p, k;
	for( p=1;p<=21;p++)
	{
		for(k=1;k<=p;k++)	
		{
			Snum[p][k] = S(p,k);
		}
	}
}
int main(int argc, char *argv[])
{
  makeSnum();
  print(Snum);
  system("PAUSE");	
  return 0;
}
