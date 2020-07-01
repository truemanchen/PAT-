#include<set>
#include<iostream>
using namespace std;
const int maxn = 52;
set<int> s[maxn];
double simi(set<int> a, set<int> b) {
	int total = a.size() + b.size();
	int s = 0;
	for (auto it = a.begin(); it != a.end(); it++) {
		auto t = b.find(*(it));
		if (t != b.end()) {
			s++;
		}
	}
	total -= s;
	return (s * 1.0) / total*100;
}
int main() {
	int sNum;
	cin >> sNum;
	for (int i = 1; i <= sNum; i++) {
		int cNum;
		cin >> cNum;
		for (int j = 0; j < cNum; j++) {
			int x;
			cin >> x;
			s[i].insert(x);
		}
	}
	int qNum;
	cin >> qNum;
	for (int i = 0; i < qNum; i++) {
		int x, y;
		cin >> x >> y;
		printf("%.1f%%\n",simi(s[x], s[y]));
	}
	return 0;
}