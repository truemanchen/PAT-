#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 100001;
vector<int> v;
int n;
double p,r,sales = 0.0;
struct node {
	double weight = 0.0;
	vector<int> child;
}nod[maxn];
void dfs(int root, int height) {
	if (nod[root].child.size() == 0) {
		sales += nod[root].weight * pow((1 + r * 0.01), height)*p;
		return;
	}
	for (int i = 0; i < nod[root].child.size(); i++) {
		dfs(nod[root].child[i], height + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	int m, temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m == 0) {
			scanf("%d", &temp);
			nod[i].weight = temp;
		}
		else {
			for (int j = 0; j < m; j++) {
				scanf("%d", &temp);
				nod[i].child.push_back(temp);
			}
		}
	}
	dfs(0, 0);
	printf("%.1f", sales);
	return 0;
}