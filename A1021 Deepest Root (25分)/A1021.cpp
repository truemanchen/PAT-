#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 9999;
vector<int> g[maxn],temp;
set<int> s;
int hasht[maxn] = {}, maxdeep = -1;
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
