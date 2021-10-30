#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	
	return true;
}

long long int dfs(int i, string s) {
	return 0;
}
struct block {
	int x;
	int y;
	int h;
};
bool cmp(block a, block b) {
	return a.x < b.x;
}
bool check(block base, block b) {
	if (base.x < b.x && base.y < b.y) return true;
	if (base.x < b.y && base.y < b.x) return true;
	return false;

}
void sol(int idx,int n) {
	vector<block> blocks;
	int hlist[200] = { 0 };
	int x, y, z;
	for (int i = 0,idx=0; i < n ; i++) {
		cin >> x >> y >> z;
		block b;
		
		b.x = x; b.y = y; b.h = z;
		blocks.push_back(b);
		b.x = y; b.y = x; b.h = z;
		blocks.push_back(b);

		b.x = x; b.y = z; b.h = y;
		blocks.push_back(b);
		b.x = z; b.y = x; b.h = y;
		blocks.push_back(b);

		b.x = z; b.y = y; b.h = x;
		blocks.push_back(b);
		b.x = y; b.y = z; b.h = x;
		blocks.push_back(b);
	}
	sort(blocks.begin(), blocks.end(),cmp);
	int i = 0;
	for (vector<block>::iterator it = blocks.begin(); it!=blocks.end(); it++,i++) {
		hlist[i] = it->h;
		//cout << it->h << endl;
	}

	//lis
	int highest = 0;
	for (int i = 0; i < blocks.size(); i++) {
		for (int j = i; j < blocks.size(); j++) {
			if (check(blocks[i], blocks[j])) {
				hlist[j] = max(hlist[j], hlist[i] + blocks[j].h);
				if (highest < hlist[j])
					highest = hlist[j];
			}
		}
	}
	cout <<"Case " << idx << ": maximum height = " << highest << "\n";
}

int main(int argc, char** argv) {
	int n;
	int idx = 1;
	while (true) {
		cin >> n;
		if (!n) break;
				
		sol(idx,n);
		idx++;
	}

		
	return 0;
}

