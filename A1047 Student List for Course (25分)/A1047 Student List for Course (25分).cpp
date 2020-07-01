#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 40000;
vector<string> v[maxn];
int cmp(string a, string b) {
	return a < b;
}
int main() {
	int stuNum, courseNum;
	scanf("%d%d", &stuNum, &courseNum);
	for (int i = 0; i < stuNum; i++) {
		string name;
		int x,course;
		cin >> name >> x;
		for (int j = 0; j < x; j++) {
			scanf("%d", &course);
			v[course].push_back(name);
		}
	}
	for (int i = 1; i <= courseNum; i++) {
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++) {
			cout<<v[i][j]<<endl;
		}
	}
	return 0;
}