#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100002;
int hasht[maxn] = {};
struct node {
	int add, data=0, next;
	int flag = 0;
	int count = 0;
	int times = 0;
}nod[maxn];
int cmp(node a, node b) {
	if (a.flag != b.flag ) {
		return a.flag > b.flag;
	}
	else if (a.times != b.times)
	{
		return a.times < b.times;
	}
	else
		return a.count < b.count;
}
int main() {
	int first, totalNum;
	cin >> first >> totalNum;
	for (int i = 0; i < totalNum; i++) {
		int add, data, next;
		scanf("%d%d%d", &add, &data, &next);
		nod[add].add = add;
		nod[add].next = next;
		nod[add].data = data;
	}
	int p = first,validNum=0,dupNum=0;
	while (p!=-1)
	{
		nod[p].flag = 1;
		hasht[abs(nod[p].data)]++;
		if (hasht[abs(nod[p].data)] > 1) {
			dupNum++;
		}
		validNum++;
		nod[p].count = validNum;
		nod[p].times = hasht[abs(nod[p].data)]>2?2: hasht[abs(nod[p].data)];
		p = nod[p].next;
	}
	sort(nod, nod + maxn, cmp);
		for (int i = 0; i < validNum - dupNum-1 ; i++) {
			printf("%05d %d %05d\n", nod[i].add, nod[i].data, nod[i + 1].add);
		}
		printf("%05d %d -1\n", nod[validNum - dupNum-1].add, nod[validNum - dupNum - 1].data);
		for (int i = validNum - dupNum; i < validNum-1 ; i++) {
			printf("%05d %d %05d\n", nod[i].add, nod[i].data, nod[i + 1].add);
		}
		printf("%05d %d -1\n", nod[validNum  - 1].add, nod[validNum  - 1].data);
	return 0;
}

/*#include<iostream>
using namespace std;
struct lnode
{
	int address, next, data;
}nod1[100009],nod2[100000];
int main()
{
	int start, i, n, add, hasht[10009] = {};
	cin >> start >> n;
	for (i = 0;i < n;i++) {
		cin >> add;
		cin >> nod1[add].data >> nod1[add].next;
		nod1[add].address = add;
	}
	int p=nod1[start].next,ind,pos=0,last=start;
	hasht[abs(nod1[last].data)] = 1;
	while (p != -1) {
		ind = abs(nod1[p].data);
		if (hasht[ind] == 0) {
			hasht[ind] = 1;
			last = p;
			p = nod1[p].next;
		}
		else
		{
			nod2[pos++] = nod1[p];
			nod1[last].next = nod1[p].next;
			p = nod1[p].next;
		}
	}
	p = start;
	while (nod1[p].next != -1) {
		printf("%05d %d %05d\n", nod1[p].address, nod1[p].data, nod1[p].next);
		p = nod1[p].next;
	}
	printf("%05d %d -1\n", nod1[p].address, nod1[p].data);
	if (pos != 0) {
		nod2[--pos].next = -1;
		for (i = 0;i <= pos;i++) {
			if(i!=pos)printf("%05d %d %05d\n", nod2[i].address, nod2[i].data, nod2[i+1].address);
			else
			{
				printf("%05d %d -1\n", nod2[i].address, nod2[i].data);
			}
		}
	}
    return 0;
}*/