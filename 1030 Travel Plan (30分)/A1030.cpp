#include<iostream>
#include<limits.h>
using namespace std;
const int inf = INT_MAX;
const int maxv = 510;
int d[maxv], g[maxv][maxv], cost[maxv], spend[maxv][maxv], n, m, s, des,pre[maxv];
bool visit[maxv] = { false };
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	fill(cost, cost + maxv, inf);
	d[s] = 0;
	cost[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, mindis = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && d[j] < mindis) {
				u = j;
				mindis = d[j];
			}
		}
		if (u == -1)return;
		visit[u] = true;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && g[u][v] < inf) {
				if (d[v] > d[u] + g[u][v]) {
					d[v] = d[u] + g[u][v];
					cost[v] = cost[u] + spend[u][v];
					pre[v] = u;
				}
				else if (d[v] == d[u] + g[u][v]) {
					if (cost[v] > cost[u] + spend[u][v]) {
						cost[v] = cost[u] + spend[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void print(int s, int v) {
	if (s == v) {
		printf("%d", v);
		return;
	}
	print(s, pre[v]);
	printf(" %d", v);
}
int main() {
	fill(g[0], g[0] + maxv * maxv, inf);
	scanf_s("%d%d%d%d", &n, &m, &s, &des);
	int u, v, w, c;
	for (int i = 0; i < m; i++) {
		scanf_s("%d%d%d%d", &u, &v, &w, &c);
		g[u][v] = w;
		g[v][u] = w;
		spend[u][v] = c;
		spend[v][u] = c;
	}
	dijkstra(s);
	print(s, des);
	cout << " " << d[des] << " " << cost[des];
	return 0;
}