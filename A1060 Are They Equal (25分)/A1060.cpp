#include<iostream>
#include<string>
using namespace std;
int s;
string find(string a, int& e) {
	while (a.size() > 0 && a[0] == '0') {
		a.erase(a.begin());
	}
	if (a[0] == '.') {
		a.erase(a.begin());
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != '0') {
				e = 0-i;
				break;
			}
		}
		for (int i = 0; i < -e; i++) {
			a.erase(a.begin());
		}
	}
	else
	{
		int len = a.size(),count=0;
		for (auto it = a.begin(); it != a.end();it++) {
			count++;
			if (*(it) == '.') {
				e = count-1;
				a.erase(it);
				break;
			}
		}
		if (a.size() == len)e = a.size();
	}
	if (a.size() == 0)a = "0";
	while (a.size() < s) {
		a += "0";
	}
	if (a.size() > s) {
		a = a.substr(0, s);
	}
	return a;
}
int main() {
	cin >> s;
	string s1, s2, s3, s4;
	cin >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = find(s1, e1);
	s4 = find(s2, e2);
	if (s3 == s4 && e1 == e2) {
		cout << "YES" << " 0." << s3 << "x10^" << e1;
	}
	else
	{
		cout << "NO" << " 0." << s3 << "x10^" << e1 << " 0." << s4 << "x10^" << e2;
	}
	return 0;
}
/*#include<string>
#include<iostream>
using namespace std;
string equal(string a, int yx,int &expo) {
	int  len, pos;
	string intp, otherp, result;
	len = a.size();
	pos = a.find('.');
	if (a.find('.') == len) {
		intp = a;
	}
	else
	{
		intp = a.substr(0, pos );
		otherp = a.substr(pos + 1, len - pos);
	}
	while (intp.size() > 1 && intp[0] == '0') {
		intp.erase(intp.begin());
	}//整数部分有多余的0把他去除
	if (intp[0] != '0') {
		if (intp.size() >= yx)
		{
			result = intp.substr(0, yx);
		}
		else if (intp.size() + otherp.size() >= yx) {
			result = intp + otherp.substr(0, yx - intp.size());
		}
		else
		{
			int num = yx - otherp.size() - intp.size();
			result = intp + otherp;
			while (num) {
				result += '0';
				num--;
			}
		}
		expo = intp.size();
	}
	else {
		int count = 0;
		while (otherp[0] == '0') {
			otherp.erase(otherp.begin());
			count++;
		}
		if (otherp.size() >= yx) {
			result = otherp.substr(0, yx);
			expo = -count;
		}
		else 
		{
			result = otherp;
			int num = yx - otherp.size();
			while (num) {
				result += '0';
				num--;
			}
			if(otherp.size()!=0)
			expo = -count;
			else
			{
				expo = 0;
			}
		}
	}
	return result;
}
int main()
{
	int dignum,expo1=0,expo2=0;
	string a, b;
	cin >> dignum >> a >> b;
	a = equal(a, dignum, expo1);
	b= equal(b, dignum, expo2);
	if (a == b) {
		cout << "YES 0." << a << "*10^" << expo1;
	}
	else {
		cout << "NO 0." << a << "*10^" << expo1<<" 0."<<b<<"*10^"<<expo2;
	}
    return 0;
}*/