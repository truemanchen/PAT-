#include<iostream>
#include<math.h>
using namespace std;
const int maxn = 10001;
int hasht[maxn] = {};
int m, n;
bool isPrime(int n) {
	if (n <= 1)return false;
	int s = (int)sqrt(1.0 * n);
	for (int i = 2; i <= s; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int quadratic(int n) {
	int step = 1,pos=-1;
	while (step < m ) {
		 pos = (n + step * step) % m;
		 if (hasht[pos] == 0) {
			 hasht[pos] = 1;
			 return pos;
		 }
		 step++;
	}
	return -1;
}
int main() {
	int a;
	cin >> m >> n;
	while(!isPrime(m)) {
		m++;
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		int pos;
		pos = a % m;
		if (hasht[pos] == 0) {
			hasht[pos] = 1;
			printf("%d", pos); 
		}
		else
		{
			pos = quadratic(a);
			if (pos>=0) {
				printf("%d", pos);
			}
			else
			{
				printf("-");
			}
		}
		if (i != n - 1)printf(" ");
	}
	return 0;
}