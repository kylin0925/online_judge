#include <stdio.h>
#include <string.h>
#define MAXLEN 1024
char ch[256] = {0};
void init_ch() {
	int i = 1;
	int a;
	for (a = 'a'; a <= 'z'; a++, i += 2)
		ch[a] = i;
	i = 0;
	for (a = 'A'; a <= 'Z'; a++, i += 2)
		ch[a] = i;
}
void swap(char str[], int a, int b) {
	char tmp;
	tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;

}
void sort(char str[],int n) {
	int i, j;
	int tmpa, tmpb;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			tmpa = ch[str[i]];
			tmpb = ch[str[j]];
			if (tmpa<tmpb) {
				swap(str, i, j);
			}
		}
	}
}
char visit[MAXLEN] = { 0 };
char result[MAXLEN] = { 0 };
void init_visit() {
	int i;
	for (i = 0; i < MAXLEN; i++) {
		visit[i] = 0;
		result[i] = 0;
	}

}
void gen(char str[], int idx, int n) {
	int i = 0;
	int num[256] = { 0 };
	char c = 0;
	if (idx == n) {
		//dump
		printf("%s\n",result);
	}
	else {
		for ( i = 0; i < n; i++) {
			c = str[i];
			if (num[c] ==0 && visit[i] == 0) {
				visit[i] = 1;
				num[c] = 1;
				result[idx] = str[i];
				gen(str, idx + 1, n);
				visit[i] = 0;
			}
		}
	}
}
int main(int argc, char** argv) {
	char test[1024] = { 0 };
	int n = 0;
	init_ch();

	scanf("%d", &n);

	while ((n--) > 0) {
		init_visit();
		scanf("%s", test);

		sort(test, strlen(test));
		//printf("%s\n", test);
		gen(test, 0, strlen(test));
	}
	return 0;
}