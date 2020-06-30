#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n) {
	if (n <= 1)return false;
	int s = (int)sqrt(1.0 * n);
	for (int i = 2; i <= s; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int isSex(int n) {
	bool a = isPrime(n - 6);
	bool b = isPrime(n + 6);
	if (isPrime(n) && (a || b)) {
		if (a)return n-6;
		else
		{
			return n + 6;
		}
	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	int ans = isSex(n);
	if (ans > 0) {
		cout << "Yes" << endl;
		cout << ans;
	}
	else
	{
		cout << "No" << endl;
		while (ans < 0) {
			n++;
			ans = isSex(n);
		}
		cout << n;
	}
}