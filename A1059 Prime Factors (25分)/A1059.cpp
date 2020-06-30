#include<iostream>
#include<map>
#include<math.h>
typedef long long ll;
using namespace std;
const int maxn = 10001;
int p[maxn], num=0;
bool isPrime(ll n) {
	if (n <= 1)return false;
	ll s = (ll)sqrt(1.0 * n);
	for (ll i = 2; i <= s; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
void findPrime(ll n ) {
	ll s = (int)sqrt(n * 1.0)+1;
		ll work = 2;
		while (num<maxn) {
			if (isPrime(work)) {
				p[num] = work;
				num++;
			}
			work++;
		}
}
int main() {
	ll n;
	cin >> n;
	findPrime(n);
	int x = n,first=1;
	cout << n<<"=";
	for (int i = 0; i < num; i++) {
		int exponent = 0;
		while (x % p[i] == 0) {
			
			x = x / p[i];
			exponent++;
		}
		if (exponent > 0) {
			if (first == 1) {
				first = 0;
			}
			else
			{
				cout << "*";
			}cout << p[i]; }
		
		if (exponent > 1)cout << "^" << exponent;
	}
	if (isPrime(x))cout << x;
	if (n == 1)cout << n;
	return 0;
}