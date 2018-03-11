#include <stdio.h>
void solve(char str[]) {
	int first =0 ;
	int last = 0;
	int r;
	first = (str[0] - 'A') * 26 * 26;
	first += (str[1] - 'A') * 26 ;
	first += (str[2] - 'A') ;

	last = (str[4] - '0') * 10 * 10 * 10;
	last += (str[5] - '0') * 10 * 10 ;
	last += (str[6] - '0') * 10 ;
	last += (str[7] - '0') ;
	r = first - last;
	if (r < 0) 
		r=-r;

	if (r <= 100) printf("nice\n");
	else
		printf("not nice\n");

}
int main(int argc, char** argv) {
	char buff[1000] = { 0 };
	int n = 0;
	scanf("%d",&n);
	while (n--) {
		scanf("%s", buff);
		solve(buff);
	}
	return 0;
}