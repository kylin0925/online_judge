#include <stdio.h>
int solve(int n) {
	int i=0;
	int res = 0;
	for (i = 1; i < n; i++) {
		if (n % i == 0) res += i;
	}
	if (res < i) return 0;
	if (res == n) return 1;
	if (res > n) return 2;
}
int main(int argc, char** argv) {
	char *res_map[] = { "deficient","perfect","abundant" };	int t,n;	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		printf("%s\n",res_map[solve(n)]);
	}
	return 0;
}