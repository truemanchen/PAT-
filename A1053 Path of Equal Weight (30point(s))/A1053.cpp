#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 101;
vector<int> v[maxn],path;
int weight[maxn];
int n, m,givenWeight;
void dfs(int index, int sum) {
	path.push_back(weight[index]);
	if (sum > givenWeight )
		return;
	if (sum == givenWeight ) {
		if (v[index].size() != 0)return;
		for (int i = 0; i < path.size(); i++) {
			if (i != 0)printf(" %d", path[i]);
			else
			{
				printf("%d", path[i]);
			}
		}
		printf("\n");
		return;
	}
	if (sum < givenWeight) {
		for (int i = 0; i < v[index].size(); i++) {
			dfs(v[index][i], sum + weight[v[index][i]]);
			path.pop_back();
		}
	}
}
int cmp(int a, int b) {
	return weight[a] > weight[b];
}
int main() {
	cin >> n >> m >> givenWeight; 
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++) {
		int p, c,num;
		cin >> p;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> c;
			v[p].push_back(c);
		}
	}
	for (int i = 0; i < m; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}
	dfs(0, weight[0]);
	return 0;
}