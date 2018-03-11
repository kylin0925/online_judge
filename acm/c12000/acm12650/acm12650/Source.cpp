#include <stdio.h>
void solve(int n, int r) {
	int map[10001] = { 0 };
	int tmp = 0;
	int i = 0;

	for (i = 0; i < r; i++) {
		scanf("%d", &tmp);
		map[tmp] = 1;
	}
	if (n == r) {
		printf("*\n");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (map[i] == 0) {
			printf("%d ",i);
		}
	}
	printf("\n");
}
int main(int argc, char** argv) {
	int n, r;
	while (scanf("%d %d", &n, &r) == 2) {
		solve(n,r);
	}
	return 0;
}