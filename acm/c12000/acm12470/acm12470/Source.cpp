#include <stdio.h>
#define MOD 1000000009
void copyMat(unsigned long long int src[3][3], unsigned long long int det[3][3], int n) {
	int x, y;
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			det[y][x] = src[y][x];
		}
	}
}
void mulMat(unsigned long long int A[3][3], unsigned long long int B[3][3],int n) {
	int x, y, k;
	unsigned long long int tmp[3][3] = {0};
	for (y = 0; y < n; y++) {
		for (k = 0; k < n; k++) {
			for (x = 0; x < n; x++) {
				tmp[y][k] = (tmp[y][k] + (A[y][x] * B[x][k]) % MOD) % MOD;
			}
		}
	}
	copyMat(tmp,A,n);
}


void trifib(unsigned long long int n) {
	unsigned long long int ans[3][3] = { 0 };
	unsigned long long int a[3][3] = { { 1,1,1 },{ 1,0,0 },{ 0,1,0 } };
	//long long int b[3][3] = { { 1,2 },{ 3,4 } };
	int x, y;
	unsigned long long int ansmat[3] = { 0 };
	unsigned long long int f0[3] = { 2,1,0 };
	while (n > 0) {
		if (n & 1) {
			for (y = 0; y < 3; y++) {
				for (x = 0; x < 3; x++) {
					ansmat[y] = (ansmat[y]+ (a[y][x] * f0[x])%MOD) % MOD;
				}
			}
			for (y = 0; y < 3; y++) {
				f0[y] = ansmat[y];
				ansmat[y]=0;
			}


		}
		mulMat(a, a, 3);		
		n = n >> 1;
	}
	
	printf("%lld\n",f0[0]);
}
int main(int argc,char **argv) {

	unsigned long long int n;
	//trifib(2); // 4

	while (scanf("%lld",&n) == 1) {
		if (n == 0) break;
		else if (n == 1) printf("0\n");
		else if (n == 2) printf("1\n");
		else if (n == 3) printf("2\n");
		else
			trifib(n-3);
	}
	return 0;
}