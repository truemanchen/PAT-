#include<iostream>
#include<string>
using namespace std;
struct bign {
	int d[1000] = {};
	int len=0;
};
bign change(string x) {
	bign a;
	int l = x.size();
	a.len = l;
	for (int i = l-1; i >= 0; i--) {
		a.d[l-1-i] = x[i] - '0';
	}
	return a;
}
bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len||i<b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}
bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b+carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
bign divide(bign a, int y,int &r) {
	bign c;
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		if (r < y) {
			c.d[i] = 0;
		}
		else
		{
			c.d[i] = r / y;
			r = r % y;
		}
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}
int main() {
	//string x,y;
	//cin >> x; cin >> y;
	string x;
	int y,r=0;
	cin >>x ;
	cin >> y;
	bign b = change(x);
	bign c=divide(b, y,r);
	for (int i = 0; i < c.len; i++) {
		cout << c.d[c.len - i - 1];
	}
	cout << " " << r;
	return 0;
}