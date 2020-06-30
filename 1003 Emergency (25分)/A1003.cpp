#include<iostream>
using namespace std;
const int maxv = 510;
const int inf = INT_MAX;
int d[maxv], g[maxv][maxv], n, m, s, des, hands[maxv] = {}, num[maxv] = {}, weight[maxv];
bool visit[maxv] = { false };
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	num[s] = 1;
	hands[s] = weight[s];
	for (int i = 0; i < n; i++) {
		int u = -1,mindis=inf;
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
					num[v] = num[u];
					d[v] = d[u] + g[u][v];
					hands[v] = hands[u] + weight[v];
				}
				else if (d[v] == d[u] + g[u][v]) {
					if(hands[v] < hands[u] + weight[v])
					num[v] += num[u];
					hands[v] = hands[u] + weight[v];
				}
			}
		}
	}
}
int main() {
	fill(g[0], g[0] + maxv * maxv, inf);
	scanf_s("%d%d%d%d", &n, &m, &s, &des);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++) {
		int u, v,w;
		scanf_s("%d%d%d", &u, &v, &w);
		g[u][v] = w;
		g[v][u] = w;
	}
	dijkstra(s);
	cout << num[des] << " " << hands[des];
	return 0;
}



