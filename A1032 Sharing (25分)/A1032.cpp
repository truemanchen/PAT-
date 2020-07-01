#include<iostream>
using namespace std;
const int maxn = 100001;
struct node {
	int  times=0, next=-1;
	char data;
}nod[maxn];
int main() {
	int add1, add2, totalNum;
	cin >> add1 >> add2 >> totalNum;
	int n1, n2;
	char a;
	for (int i = 0; i < totalNum; i++) {
		cin >> n1 >> a >> n2;
		nod[n1].data = a;
		nod[n1].next = n2;
	}
	int p = add1;
	while (p != -1) {
		nod[p].times++;
		p = nod[p].next;
	}
	p = add2;
	while (p != -1) {
		nod[p].times++;
		p = nod[p].next;
	}
	p = add2;
	while (p != -1) {
		if (nod[p].times == 2) {
			break;
		}
		p = nod[p].next;
	}
	printf("%05d\n", p);
	return 0;
}