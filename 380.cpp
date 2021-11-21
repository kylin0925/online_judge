#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

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

struct Forwarding {
	int id;
	int time;
	int duration;
	int forward_id;
};
int forward(vector<Forwarding> forward_system,int time,int id) {
	int tmpid = id;
	while (true) {
		int i = 0;
		for (i = 0; i < forward_system.size(); i++) {
			if (forward_system[i].id == tmpid) {
				if (time >= forward_system[i].time && time <= forward_system[i].time + forward_system[i].duration) {
					tmpid = forward_system[i].forward_id;
					break;
				}
			}
		}
		if (i == forward_system.size())
			break;		
		
		if (tmpid == id) {
			tmpid = 9999;
			break;
		}
	}
	
	return tmpid;
}
void sol(int idx) {
	vector<Forwarding> forward_system;
	cout << "SYSTEM "<<idx << "\n";
	Forwarding f;
	while (true)
	{
		cin >> f.id;
		if (!f.id) break;
		cin >> f.time >> f.duration >> f.forward_id;

		forward_system.push_back(f);
	}
	int time, id;
	while (true) {
		cin >> time;
		if (time==9000) break;
		cin >> id;
		int ring = forward(forward_system, time, id);
		cout << "AT " << setfill('0') << setw(4) << time << " CALL TO " << setfill('0') << setw(4) <<  id << " RINGS " << setfill('0') << setw(4) << ring << "\n";
	}
}

int main(int argc, char** argv) {
	int n;
	int idx = 1;
	

	cin >> n;
	cout << "CALL FORWARDING OUTPUT" << "\n";
	for (int i = 1;i<=n; i++) {
		sol(i);		
	}

	cout << "END OF OUTPUT" << "\n";
	return 0;
}

