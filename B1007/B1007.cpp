#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int x) {
	if (x <= 1)return false;
	int sqr = (int)sqrt(1.0 * x);
	for (int i = 2; i <= sqr; i++) {
		if (x % i == 0)return false;
	}
	return true;
}
int main() {
	int ans = 0;
	int n = 2,N;
	cin >> N;
	while (n <= N) {
		if (isPrime(n) && isPrime(n + 2))
			ans++;
		n++;
	}
	cout << ans;
	return 0;
}