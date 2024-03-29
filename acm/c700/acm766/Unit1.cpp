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
unsigned int Snum[30][30] = {0};
int C[30][30] = {0};
void print(unsigned int s[30][30])
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
void printI( int s[30][30])
{
	int i ,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			printf("%d ",s[i][j]);
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
void countC(int k)
{
	int b[30]={0};
	int r[30] = {0};
	b[0] = -(k-2);
	b[1] = 1;
	int crr = 0;

	for(int i =0; i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			r[i+j] = (r[i+j] + C[k-1][i] *  b[j]);
			//crr    = (r[i+j] + C[k-1][i] *  b[j];
		}
	}
	for(int i=0;i<30;i++)
	{
      	C[k][i] = r[i];
    }
}
void makeC()
{
	C[1][0] = 1;
	C[1][1] = 1;
	int k = 1;
	for(k =2 ; k<=21; k++)
	{
		countC(k);
	}
}
int main(int argc, char *argv[])
{
  makeSnum();
  print(Snum);
  makeC();
  printI(C);
  system("PAUSE");
  return 0;
}

