#include<iostream>
#include<queue>
#include <string>
using namespace std;
const int maxn = 12;
struct node {
	int lchild, rchild;
}nod[maxn];
int n, hasht[maxn] = {},root,inOrderFirst=1;
int conversion(string a) {
	if (a != "-") {
		hasht[stoi(a)] = 1;
		return stoi(a);
	}
	return -1;
}
void inOrder(int root) {
	if (root == (-1))return;
	inOrder(nod[root].lchild);
	if (inOrderFirst == 1) {
		cout << root;
		inOrderFirst = 0;
	}
	else
	{
		cout << " " << root;
	}
	inOrder(nod[root].rchild);
}
void bfs(int root) {
	int first = 1;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (first == 1) {
			cout << temp;
			first = 0;
		}
		else
		{
			cout << " " << temp;
		}
		if (nod[temp].lchild != (-1))q.push(nod[temp].lchild);
		if (nod[temp].rchild != (-1))q.push(nod[temp].rchild);

	}
	cout << endl;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		int _a, _b;
		_a = conversion(b);
		_b = conversion(a);
		nod[i].lchild = _a;
		nod[i].rchild = _b;
	}
	for (int i = 0; i < n; i++) {
		if (hasht[i] == 0)root = i;
	}
	bfs(root);
	inOrder(root);
	return 0;
}
/*#include<queue>
#include<iostream>
using namespace std;
const int maxn = 100;
int n, in[maxn], pos = 0, rot[maxn];
struct node {
	int data;
	int lchild, rchild;
}nod[maxn];
void bfs(int root) {
	queue<node> q;
	q.push(nod[root]);
	while (!q.empty()) {
		node topn = q.front();
		q.pop();
		if (topn.lchild != nod[root].lchild)cout << " ";
		cout << topn.data;
		if (topn.rchild != -1) {
			q.push(nod[topn.rchild]);
		}
		if (topn.lchild != -1) {
			q.push(nod[topn.lchild]);
		}
	}
}
void inorder(int root) {
	if (root == -1)return;
	inorder(nod[root].rchild);
	in[pos++] = nod[root].data;
	inorder(nod[root].lchild);
}
int change(char a) {
	if (a == '-')return -1;
	else
	{
		return a - '0';
	}
}
int findroot(int n) {
	for (int i = 0; i < n; i++) {
		if (rot[i] == 0)return i;
	}
}
int main() {
	cin >> n; char l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r; int v1 = change(l), v2 = change(r);
		nod[i].lchild = v1;
		nod[i].rchild = v2;
		nod[i].data = i;
		if (l != -1)rot[v1] = 1;
		if (r != -1)rot[v2] = 1;
	}
	int root = findroot(n);
	bfs(root);
	inorder(root);
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << in[i];
	}
	return 0;
}*/