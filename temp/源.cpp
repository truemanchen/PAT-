#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 9999;
vector<int> g[maxn], temp;
set<int> s;
queue<int> q;
int hasht[maxn] = {}, maxdeep = -1, layer[maxn] = {};
void dfs(int index, int deep) {
	hasht[index] = 1;
	if (deep == maxdeep) {
		temp.push_back(index);
	}
	if (deep > maxdeep) {
		temp.clear();
		temp.push_back(index);
		maxdeep = deep;
	}
	for (int i = 0; i < g[index].size(); i++) {
		if (hasht[g[index][i]] == 0)
			dfs(g[index][i], deep + 1);
	}
}
void LayerOrder(int root, int deep) {
	layer[root] = 1;
	q.push(root);
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		for (int i = 0; i < g[r].size(); i++) {
			layer[g[r][i]] = layer[r] + 1;
			q.push(g[r][i]);
		}
	}
	return;
}
int main()
{
	int n, i, v1, v2, block = 0;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		scanf("%d%d", &v1, &v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	memset(hasht, 0, sizeof(hasht));
	for (i = 1; i <= n; i++) {
		if (hasht[i] == 0)
		{
			dfs(i, 1);
			block++;
		}
	}
	if (block > 1)
		cout << "Error: " << block << " components";
	else
	{
		//LayerOrder(1, 1);
		for (auto it = temp.begin(); it != temp.end(); it++)
			s.insert(*(it));
		temp.clear();
		memset(hasht, 0, sizeof(hasht));
		dfs(*(s.begin()), 1);
		for (auto it = temp.begin(); it != temp.end(); it++)
			s.insert(*(it));
		for (auto it = s.begin(); it != s.end(); it++)
			printf("%d\n", *(it));
	}
	return 0;
}
