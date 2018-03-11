#include <stdio.h>

int main(int argc, char** argv) {
	unsigned long long int a = 1, b = 1;
	unsigned long long int res;
	int n,i;
	
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		if (n == 1) {
			printf("1\n");
			continue;
		}
		a = 1;
		b = 1;

		for (i = 1; i < n; i++) {
			res = a + b;
			a = b;
			b = res;
		}
		printf("%llu\n",res);
	}
	return 0;
}