#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100009;
struct node {
	int data, next=-1,add;
	int flag=0;
}nod[maxn];
int cmp(node a, node b) {
	if (a.flag != b.flag)return a.flag > b.flag;
	else if (a.data != b.data)return a.data < b.data;
}
int main() {
	int first, totalNum;
	cin >> totalNum >> first;
	for (int i = 0; i < totalNum; i++) {
		int add, d, n;
		scanf("%d%d%d", &add, &d, &n);
		nod[add].add = add;
		nod[add].data = d;
		nod[add].next = n;
	}
	int p = first ,count=0;
	while (p != -1) {
		count++;
		nod[p].flag = 1;
		p = nod[p].next;
	}
	sort(nod, nod + maxn, cmp);
	if (count != 0) {
		sort(nod, nod + maxn, cmp);

		printf("%d %05d\n", count, nod[0].add);
		for (int i = 0; i < count - 1; i++) {
			printf("%05d %d %05d\n", nod[i].add, nod[i].data, nod[i + 1].add);
		}
		printf("%05d %d -1\n", nod[count - 1].add, nod[count - 1].data);
	}
	else
		printf("0 -1");
	return 0;
}