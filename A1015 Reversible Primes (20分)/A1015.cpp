#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
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
int reverse(int a, int r) {
	int _a=0;
	vector<int>v;
	while (a != 0) {
		v.push_back(a % r);
		a /= r;
	}
	for (int i = 0; i < v.size(); i++)
		_a += v[i]*pow(r, v.size() - i - 1);
	return _a;
}
int main() {
	int a;
	while (scanf("%d",&a)!=EOF) {
		int r; cin >> r;
		if (isPrime(reverse(a, r)) && isPrime(a))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}