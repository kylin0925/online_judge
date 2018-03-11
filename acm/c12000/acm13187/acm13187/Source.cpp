#include <stdio.h>
int main(int argc, char** argv) {
	int n;
	unsigned long long int m = 0;
	scanf("%d",&n);
	while (n--) {
		scanf("%d", &m);
		printf("%llu\n",(m+1)*(m + 1)-1);
	}
	return 0;
}