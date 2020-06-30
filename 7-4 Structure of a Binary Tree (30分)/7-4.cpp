#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1002;
int post[maxn] = {}, in[maxn] = {}, n, root, parent[maxn] = {-1},m;
bool full=true;
struct node {
	int lchild=(-1), rchild=(-1);
	int deep;
	int parent;
}nod[maxn];
int create(int inl, int inr, int postl, int postr) {
	if (postl > postr) {
		return -1;
	}
	int k = 0;
	for (int i = inl; i <= inr; i++) {
		if (in[i] == post[postr]) {
			k = i;
			break;
		}
	}
	int len = k - inl;
	int temp = post[postr];
	nod[temp].lchild = create(inl, k - 1, postl, postl + len - 1);
	nod[nod[temp].lchild].parent = temp;
	nod[temp].rchild = create(k + 1, inr, postl + len, postr - 1);
	nod[nod[temp].rchild].parent = temp;
	return temp;
}
void dfs(int root, int deep) {
	if (root == (-1))return;
	nod[root].deep = deep;
	if (nod[root].lchild * nod[root].rchild <0)full = false;
	dfs(nod[root].lchild, deep + 1);
	dfs(nod[root].rchild, deep + 1);
}
bool isRoot(int x) {
	return x == root;
}
bool isSib(int a, int b) {
	return nod[a].parent == nod[b].parent;
}
bool isParent(int a, int b) {
	return nod[a].lchild == b || nod[a].rchild == b;
}
bool isLevel(int a, int b) {
	return nod[a].deep == nod[b].deep;
}
bool isLeftchild(int a, int b) {
	return nod[b].lchild == a;
}
bool isRightchild(int a, int b) {
	return nod[b].rchild == a;
}
bool isFull() {
	return full;
}
void print(bool flag) {
	if (flag)printf("Yes\n");
	else
		printf("No\n");
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	root= create(0, n - 1, 0, n - 1);
	dfs(root, 0);
	cin >> m;
	cin.get();
	for (int i = 0; i < m; i++) {
		string a;
		getline(cin, a);
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'p') {
				string c, d;
				int _c, _d;
				c.push_back(a[0]);
				if (isdigit(a[1]))c.push_back(a[1]);
				if (isdigit(a[2]))c.push_back(a[2]);
				if (isdigit(a[3]))c.push_back(a[3]);
				if (isdigit(a[a.size() - 4]))d.push_back(a[a.size() - 4]);
				if (isdigit(a[a.size() - 3]))d.push_back(a[a.size() - 3]);
				if (isdigit(a[a.size() - 2]))d.push_back(a[a.size() - 2]);
				d.push_back(a[a.size() - 1]);
				_c = stoi(c);
				_d = stoi(d);
					print(isParent(_c, _d));
					break;
			}
			if (i<=a.size()-3) {
				if (a[i] == 'l' && a[i + 1] == 'e'&&a[i+2]=='f') {
					string c, d;
					int _c, _d;
					c.push_back(a[0]);
					if (isdigit(a[1]))c.push_back(a[1]);
					if (isdigit(a[2]))c.push_back(a[2]);
					if (isdigit(a[3]))c.push_back(a[3]);
					if (isdigit(a[a.size() - 4]))d.push_back(a[a.size() - 4]);
					if (isdigit(a[a.size() - 3]))d.push_back(a[a.size() - 3]);
					if (isdigit(a[a.size() - 2]))d.push_back(a[a.size() - 2]);
					d.push_back(a[a.size() - 1]);
					_c = stoi(c);
					_d = stoi(d);
					print(isLeftchild(_c, _d));
					break;
				}
			}
			if (a[i] == 'r' && a[i + 1] == 'i') {
				string c, d;
				int _c, _d;
				c.push_back(a[0]);
				if (isdigit(a[1]))c.push_back(a[1]);
				if (isdigit(a[2]))c.push_back(a[2]);
				if (isdigit(a[3]))c.push_back(a[3]);
				if (isdigit(a[a.size() - 4]))d.push_back(a[a.size() - 4]);
				if (isdigit(a[a.size() - 3]))d.push_back(a[a.size() - 3]);
				if (isdigit(a[a.size() - 2]))d.push_back(a[a.size() - 2]);
				d.push_back(a[a.size() - 1]);
				_c = stoi(c);
				_d = stoi(d);
				print(isRightchild(_c, _d));
				break;
			}
		}
		if (a[a.size() - 1] == 't') {
			string c;
			int _c;
			c.push_back(a[0]);
			if (isdigit(a[1]))c.push_back(a[1]);
			if (isdigit(a[2]))c.push_back(a[2]);
			if (isdigit(a[3]))c.push_back(a[3]);
			_c = stoi(c);
			print(isRoot(_c));
		}
		if (a[a.size() - 1] == 's') {
			string c, d;
			c.push_back(a[0]);
			if (isdigit(a[1]))c.push_back(a[1]);
			if (isdigit(a[2]))c.push_back(a[2]);
			if (isdigit(a[3]))c.push_back(a[3]);
			for (int i = 5; i < 10; i++) {
				if (isdigit(a[i]))d.push_back(a[i]);
			}
			int _c, _d;
			_c = stoi(c);
			_d = stoi(d);
			print(isSib(_c,_d));
		}
		if (a[a.size() - 1] == 'l') {
			string c, d;
			c.push_back(a[0]);
			if (isdigit(a[1]))c.push_back(a[1]);
			if (isdigit(a[2]))c.push_back(a[2]);
			if (isdigit(a[3]))c.push_back(a[3]);
			for (int i = 5; i < 18; i++) {
				if (isdigit(a[i]))d.push_back(a[i]);
			}
			int _c, _d;
			_c = stoi(c);
			_d = stoi(d);
			print(isLevel(_c, _d));
		}
		if (a[a.size() - 1] == 'e') {
			print(isFull());
		}
	}
	return 0;
}