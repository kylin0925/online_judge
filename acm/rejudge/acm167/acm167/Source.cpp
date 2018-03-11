/* @JUDGE_ID: 53xxxx 167 C++ */
#include <stdio.h>
#define  N 8
int colmun[N + 1], rup[2 * N + 1], lup[2 * N + 1], queen[N + 1];
int qu[92][N + 1][N + 1];
void backtrack(int i)
{
	int j, x, y;
	static int num = 0;

	if (i>N)
	{
		for (y = 1; y <= N; y++)
		{
			for (x = 1; x <= N; x++)
			{
				if (queen[y] == x) qu[num][y][x] = 1;
				else
					qu[num][y][x] = 0;
			}
		}
		num++;
	}
	else
	{
		for (j = 1; j <= N; j++)
		{
			if (colmun[j] == 1 && rup[i + j] == 1 && lup[i - j + N] == 1)
			{
				queen[i] = j;
				colmun[j] = rup[i + j] = lup[i - j + N] = 0;
				backtrack(i + 1);
				colmun[j] = rup[i + j] = lup[i - j + N] = 1;
			}
		}
	}

}
int main()
{
	int i, n, a, b;
	int bo[8][8], k;
	long con, max;
	for (i = 1; i <= N; i++)
		colmun[i] = 1;
	for (i = 1; i <= 2 * N; i++)
		rup[i] = lup[i] = 1;
	backtrack(1);
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		con = 0, max = -1;
		for (a = 0; a<8; a++)
		{
			for (b = 0; b<8; b++)
			{
				scanf("%d", &bo[a][b]);
			}
		}
		for (k = 0; k<92; k++)
		{
			for (a = 0; a<8; a++)
			{
				for (b = 0; b<8; b++)
				{
					if (qu[k][a + 1][b + 1]) con += bo[a][b];
				}
			}
			if (con>max) max = con;
			con = 0;
		}
		printf("%5d\n", max);
	}
	return 0;
}