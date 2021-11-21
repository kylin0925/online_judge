#include <iostream>
using namespace std;
long coin[] = { 5,10,20,50,100,200,500,1000,2000,5000,10000 };
long long ans[11][30001] = {0};
void build() {
	int i,j;
	for (i = 0; i < 30001; i++) {
		ans[0][i] = 1;
	}
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 30001; j++) {
			if ((j - coin[i]) == 0)
			{
				ans[i][j] = ans[i - 1][j] + 1;
			}
			else if ((j - coin[i]) > 0)
			{
				ans[i][j] = ans[i - 1][j] + ans[i][j - coin[i]];
			}
			else
				ans[i][j] = ans[i - 1][j];
		}
	}
}
int main(int argc, char** argv) {
	double n;
	build();
	while (cin >> n) {
		if (n == 0) break;
		long idx = (long)((n+0.00001) * 100);
 		printf("%6.2f%17lld\n", n, ans[10][idx]);
	}
	return 0;
}