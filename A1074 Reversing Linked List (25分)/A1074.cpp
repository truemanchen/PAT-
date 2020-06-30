#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100002;
const int maxn = 100009;
int nex[N], da[N], list[N], result[N];
int main() {
	int k, p, ne, curr,first,n,add,temp,effictiveNum=0;
	cin >> first >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &add);
		scanf("%d%d", &da[add], &nex[add]);
	}
	p = first;
	while (p != (-1)) {
		list[effictiveNum++] = p;
		p = nex[p];
	}
	for (int i = 0; i < effictiveNum; i++)result[i] = list[i];
	for (int i = 0; i < (effictiveNum - effictiveNum % k); i++) {
		result[i] = list[i / k * k + k - 1 - i % k];
	}
	for (int i = 0; i < (effictiveNum - 1); i++)
		printf("%05d %d %05d\n", result[i], da[result[i]],result[i+1] );
	printf("%05d %d -1", result[effictiveNum - 1], da[result[effictiveNum-1]]);
	return 0;
}