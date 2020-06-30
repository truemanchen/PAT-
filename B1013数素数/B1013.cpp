#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1000;
vector<int>v;
int p[maxn] = {};
bool isPrime(int x) {
	if (x <= 1)return false;
	int s = (int)sqrt(x * 1.0);
	for (int i = 2; i <= s; i++) {
		if (x % i == 0)return false;
	}
	return true;
}
void findPrime(int n) {
	int work = 2, times = 0;
	while (times<=n) {
		if (p[work] == 0) {
			times++;
			v.push_back(work);
			for (int i = work+work; i <maxn; i+=work) {
				p[i] = 1;
			}
		}
		work++;
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	/*int work = 2,times=0;
	while (times <= n) {
		if (isPrime(work)) {
			times++;
			v.push_back(work);
		}
		work++;
	}*/
	findPrime(n);
	for (int i = m - 1; i < n; i++) {
		printf("%d", v[i]);
		if ((i - m + 2) % 10 == 0&&(i-m+1)!=0)printf("\n");
		else
		{
			printf(" ");
		}
	}
	return 0;
}