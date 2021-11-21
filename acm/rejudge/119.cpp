#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct person {
	string name;
	int money;
};
vector<person> p;
void minus_money(string name, int money, int cnt) {
	if (cnt == 0)
		return;
	int r = money % cnt;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].name.compare(name) == 0) {
			p[i].money = p[i].money - money + r;
			break;
		}
	}
}
void give_to(string name, int money) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i].name.compare(name) == 0) {
			p[i].money += money;
			break;
		}
	}
}
int main(int argc, char** argv) {
	
	int n;
	bool f = false;
	while (cin >> n) {
		person tmp;
		if (f)
			cout << "\n";
		for (int i = 0; i < n; i++) {
			cin >> tmp.name;
			tmp.money = 0;
			p.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			string name;
			int money;
			int cnt;
			cin >> name>>money>>cnt;
			if (cnt == 0)
				continue;
			minus_money(name, money, cnt);

			int n = (int)(money / cnt);

			for (int j = 0; j < cnt; j++) {
				string name;
				cin >> name;
				give_to(name, n);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << p[i].name << " " << p[i].money<<"\n";
		}
		p.erase(p.begin(), p.end());
		f = true;
	}
	return 0;
}
