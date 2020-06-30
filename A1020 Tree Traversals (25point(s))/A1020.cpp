#include<iostream>
#include<queue>
using namespace std;
const int maxn = 40;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
queue<node*>q;
int n, in[maxn], post[maxn];
node* create(int inl, int inr, int postl, int postr) {
	if (postl > postr)
		return NULL;
	int k = inl;
	for ( k = inl; k <= inr; k++) {
		if (in[k] == post[postr])
			break;
	}
	int leftLen = k - inl;
	node* temp = new node;
	temp->data = post[postr];
	temp->lchild = create(inl, k - 1, postl, postl + leftLen - 1);
	temp->rchild = create(k + 1, inr, postl + leftLen, postr - 1);
	return temp;
} 
void bfs(node* root) {
	int first = 1;
	q.push(root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (first == 1) {
			printf("%d", temp->data);
			first = 0;
		}
		else
			printf(" %d", temp->data);
		if (temp->lchild != NULL)q.push(temp->lchild);
		if (temp->rchild != NULL)q.push(temp->rchild);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	node* root=create(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}