#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 1001;
int g[maxn][maxn] = {}, visit[maxn] = {}, v[maxn][maxn] = {};
int n, k, m;
set<int> suspects;
set<int>ans;
void searchSuspects(int x) {
	double shortP=0, backP=0,totalP=0;
	for (int i = 1; i <= n; i++) {
		if (g[x][i] != 0) {
			totalP++;
			if (g[x][i] <= 5) {
				shortP++;
				if (g[i][x] != 0) {
					backP++;
				}
			}
		}	
	}
	if (shortP > k && backP <= 0.2 * shortP) {
		suspects.insert(x);
	}
}
void dfs(int x) {
	visit[x] = 1;
	ans.insert(x);
	for (auto it = suspects.begin(); it != suspects.end(); it++) {
		if (g[x][*(it)] !=0&&v[x][*(it)] == 0&&g[*(it)][x]!=0) {
			v[x][*(it)] = 1;
			dfs(*(it));
		}
	}
}
int main() {
	cin >> k >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b,w;
		scanf("%d%d%d", &a, &b,&w);
		g[a][b] += w;
	}
	for (int i = 0; i <= n; i++) {
		searchSuspects(i);
	}
	if (!suspects.empty()) {
		for (auto it = suspects.begin(); it != suspects.end(); it++) {
			ans.clear();
			if (visit[*(it)] == 0)
				dfs(*(it));
			if (!ans.empty()) {
				for (auto item = ans.begin(); item != ans.end(); item++) {
					if (item != ans.begin())
						printf(" %d", *(item));
					else
						printf("%d", *(item));
				}
				cout << endl;
			}
		}
	}
	else
		cout << "None" << endl;
	return 0;
}