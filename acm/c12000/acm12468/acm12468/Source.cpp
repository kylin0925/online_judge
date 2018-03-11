#include <stdio.h>
int main(int argc, char** argv) {
	int a, b;
	int fw, bw;
	while (scanf("%d %d", &a, &b) == 2) {
		if (a == -1 && b == -1) break;
		//forward
		if (a > b) {
			fw = a - b;
			bw = 100 - a + b;
		}
		else {
			bw = b - a;
			fw = 100 - b + a;
		}
		if (bw < fw) printf("%d\n",bw);
		else
			printf("%d\n", fw);
		
	}
	return 0;
}