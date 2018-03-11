/*@JUDGE_ID:53xxxx  177 C*/
#include <stdio.h>
#define  we   500
#define  he   200
char pic[200][500];
int sx = we / 2, sy = he / 2;
int angl = 0;
int top = -1, bot = -1, le = -1, ri = -1;
int tu = 0;
int ttop, tbot;
void dragon(int v, int d)
{
	if (v == 0)
	{
		if (angl == 0 || angl == 180)
		{
			if (angl == 0) sx++;
			else if (angl == 180) sx--;
			pic[sy][sx] = '_';
			(angl == 0) ? sx++ : sx--;

		}
		else
		{
			if (angl == 90)
			{
				pic[sy][sx] = '|';
				sy++;
			}
			else if (angl == 270)
			{
				sy--;
				pic[sy][sx] = '|';
			}
		}
	}
	else
	{
		dragon(v - 1, 90);
		angl = (angl + d) % 360;
		if (angl<0) angl += 360;
		dragon(v - 1, -90);
	}
}
int main(int argc, char* argv[])
{
	int n;
	int i, j;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i<he; i++) { for (j = 0; j<we; j++) { pic[i][j] = ' '; } }
		dragon(n, 90);
		for (i = he - 1; i >= 0; i--) {
			for (j = 0; j<we; j++) {
				if (pic[i][j] != ' ') { break; }
			}
			if (j<we) { top = i; break; }
		}
		tu = 0;
		for (i = 0; i <= top; i++) {
			for (j = 0; j<we; j++) {
				if (pic[i][j] != ' ')
				{
					if (pic[i][j] != ' ') { break; }
				}
			}
			if (j<we) { bot = i; break; }
		}
		for (i = 0; i<we; i++) {
			for (j = 0; j<he; j++) {
				if (pic[j][i] != ' ') { break; }
			}
			if (j != he) { le = i; break; }
		}
		for (i = we - 1; i >= 0; i--) {
			for (j = 0; j<he; j++) {
				if (pic[j][i] != ' ') { break; }
			}
			if (j != he)
			{
				ri = i; break;
			}
		}
		for (i = top; i >= bot; i--)
		{
			for (j = ri; j >= le; j--) {
				if (pic[i][j] != '|' &&  pic[i][j] != '_')
					pic[i][j] = 0;
				else {
					break;
				}
			}
			for (j = le; j <= ri; j++)
			{
				if(pic[i][j]!=0)
					printf("%c", pic[i][j]);
			}
			printf("\n");
		}
		printf("^\n");
		angl = 0;
		sx = we / 2, sy = he / 2;
		tu = 0;
		top = bot = le = ri = 0;
	}
	return 0;
}