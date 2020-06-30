#include<iostream>
#include<string>
using namespace std;
struct bign {
	int d[1000] = {};
	int len=0;
};
bool isP(bign a) {
	for (int i = 0; i < a.len/2; i++) {
		if (a.d[i] != a.d[a.len - i - 1]) {
			return false;
		}
	}
	return true;
}
bign change(string a) {
	bign c;
	c.len = a.size();
	for (int i = 0; i < a.size(); i++) {
		c.d[i] = a[c.len - i - 1] - '0';
	}
	return c;
}
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
int main() {
	string a;
	int b,count=0;
	cin >> a>>b;
	bign x = change(a);
	for (int i = 0; i < b; i++) {
		if (isP(x)) {
			break;
		}
		count++;
		bign y;
		y.len = x.len;
		for (int i = 0; i < y.len; i++) {
			y.d[i] = x.d[x.len - 1 - i];
		}
		x = add(x, y);
	}
	for (int i = 0; i < x.len; i++) {
		cout << x.d[x.len - i - 1];
	}
	cout << endl;
	cout << count;
	return 0;
}