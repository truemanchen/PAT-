
#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;
const int maxn = 100002;
vector<int> v[maxn];
int n,maxdeep=-1,maxsale=0,maxDeepNum=0,root;
double p, r;
void dfs(int root, int deep) {
	if (v[root].size() == 0) {
		if (maxdeep < deep) {
			maxdeep = deep;
			maxDeepNum = 1;
		}
		else if(maxdeep==deep)
		{
			maxDeepNum++;
		}
		return;
	}
	for (int i = 0; i < v[root].size(); i++) {
		dfs(v[root][i], deep + 1);
	}
}
int main() {
	scanf("%d %lf %lf", &n,&p,&r);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == (-1))root = i;
		else
		{
			v[temp].push_back(i);
		}
	}
	dfs(root, 0);
	printf("%.2f %d", p * pow((1 + r * 0.01), maxdeep), maxDeepNum);
	return 0;
}