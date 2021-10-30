#include <iostream>
#include <string>
unsigned long long gcd(unsigned long long m, unsigned long long n) {
	return n == 0 ? m : gcd(n, m % n);
}
unsigned long long int lcm(unsigned long long a, unsigned long long b) {
	return (a / gcd(a, b)) * b;
}
using namespace std;

#define MAX_LEN 501

unsigned long long int memo[MAX_LEN] = { 0 };
unsigned long long int MAX_INT = 2147483647;
bool check(string s) {
	if (s[0] == '0' && s.length()>1) return false;
	long long int n = stoll(s);
	if (n > MAX_INT) return false;
	return true;
}
 
long long int dfs(int i, string s) {
	if (i == s.length()) return 0;
	if (memo[i] > 0) return memo[i];
	long long int maxacc = 0;
	for (int j = 1; i+j<=s.length() && j <= s.length() && j<=10; j++) {
		string tmp = s.substr(i, j);
		
		if (check(tmp)) {
			
			long long num = stoll(tmp);
			long long int max_j = dfs(i + j, s);
			//cout << "tmp " << tmp << " num " << num << " max_j " << max_j <<  "\n";
			if (num + max_j > maxacc) {
				maxacc = num + max_j;
			}
		}
		
	}
	//cout << "debug " << i << " " << maxacc << "\n";
	memo[i] = maxacc;
	return maxacc;
}
void sol() {
	string s;
	cin >> s;
	unsigned long long int ans = dfs(0,s);
	cout << ans << "\n";
}

int main(int argc, char** argv) {
	int n;

	cin >> n;
	{
		for (; n > 0; n--) {
			sol();
			fill_n(memo, MAX_LEN, 0);
		}
	}
	return 0;
}

//5432112345
//543211239
//5110200435663427073083413970925437567511177429227535976274376920686337554296229982470108636329387921676105