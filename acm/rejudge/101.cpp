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

bool cmp(int a, int b) {
	return a < b;
}
vector<int> stack[30];
int position[30] = { 0 };

bool check_the_same(int a,int b) {
	return position[a] == position[b];
}


void print(int n) {

	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < stack[i].size(); j++) {
			cout << " " << stack[i][j] ;
		}
		cout << "\n";
	}
	/*for (int i = 0; i < n; i++) 
		cout << position[i] << " ";
	cout << "\n";*/
}
int find_pos(int ab) {
	int idx = position[ab];
	for (int i = 0; i < stack[idx].size(); i++) {
		if (stack[idx][i] == ab) {
			return i;
		}
	}
	return -1;
}
void return_blocks(int ab) {
	int idx = find_pos(ab);
	int pos = position[ab];
	for (int i = idx + 1; i < stack[pos].size(); i++) {
		int tmp = stack[pos][i];
		stack[tmp].push_back(tmp);
		position[tmp] = tmp;
	}
	if(idx+1 < stack[pos].size())
		stack[pos].erase(stack[pos].begin() + idx+1, stack[pos].end());
}
void move_to(int a,int b) {
	int pos = position[a];
	int idx = find_pos(a);
	int pos_b = position[b];

	for (int i = idx; i < stack[pos].size(); i++) {
		int tmp = stack[pos][i];
		stack[pos_b].push_back(tmp);
		position[tmp] = pos_b;
	}
	//position[a] = pos_b;
	if(idx < stack[pos].size())
		stack[pos].erase(stack[pos].begin() + idx, stack[pos].end());
}
void move_over(int a, int b) {
	if (check_the_same(a, b)) return;
	return_blocks(a);
	
	int pos_a = position[a];
	int pos_b = position[b];
	stack[pos_a].pop_back();
	stack[pos_b].push_back(a);
	position[a] = pos_b;
}
void move_onto(int a, int b) {
	if (check_the_same(a, b)) return;
	return_blocks(a);
	return_blocks(b);
	int pos_a = position[a];
	int pos_b = position[b];
	stack[pos_a].pop_back();
	stack[pos_b].push_back(a);
	position[a] = pos_b;
}
void pile_over(int a, int b) {
	if (check_the_same(a, b)) return;
	
	move_to(a,b);

}
void pile_onto(int a, int b) {
	if (check_the_same(a, b)) return;
	return_blocks(b);
	move_to(a, b);
}
void init_poistion(int n) {
	for (int i = 0; i < n; i++) {
		position[i] = i;
		stack[i].push_back(i);
	}
}
int main(int argc, char** argv) {
	int n;
	int a, b;
	string op1, op2;


	cin >> n;
	init_poistion(n);
	while (true) {
		//print(n);
		cin >> op1;
		if (op1.compare("quit")==0) {
			print(n);
			break;
		}
		cin >> a >> op2 >> b;
		if (op1.compare("move")==0) {
			if (op2.compare("over")==0) {
				move_over(a, b);
			}
			else {
				move_onto(a, b);
			}
		}
		else {
			if (op2.compare("over")==0) {
				pile_over(a,b);
			}
			else {
				pile_onto(a,b);
			}
		}
	}


	return 0;
}

