#include<iostream>
#include<string>
using namespace std;
int hasht[10] = {};
struct bign {
	int d[1000] = {};
	int len=0;
};
bign change(string a) {
	bign c;
	c.len = a.size();
	for (int i = 0; i < a.size(); i++) {
		c.d[c.len - i - 1] = a[i] - '0';
		hasht[c.d[c.len - i - 1]]++;
	}
	return c;
}
bign multi(bign a, int b) {
	bign ans;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		ans.d[ans.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		ans.d[ans.len++] = carry % 10;
		carry /= 10;
	}
	return ans;
}
int main() {
	string a;
	int flag=1;
	cin >> a;
	bign c = change(a);
	bign d = multi(c, 2);
	for (int i = 0; i < d.len; i++) {
		hasht[d.d[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (hasht[i] == 1) {
			flag = 0;
			break;
		}
	}
	if (flag == 1)cout << "Yes" << endl;
	else
	{
		cout << "No" << endl;
	}
	for (int i = 0; i < d.len; i++) {
		cout << d.d[d.len - i - 1];
	}
	return 0;
}