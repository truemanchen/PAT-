#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
using namespace std;
int findsum(string a, int radix) {
	int sum = 0;
	int len = a.size();
	for (int i = 0; i < len; i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			sum += (a[i] - 'a' + 10) * int(pow(radix, len - i - 1));
		}
		else
		{
			sum += (a[i] - '0') * int(pow(radix, len - i - 1));
		}
	}
	return sum;
}
int main()
{
	int tag, radix, sum = 0, i;
	string n1, n2, temp, temp2;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1) { temp = n1; temp2 = n2; }
	else { temp = n2; temp2 = n1; }
	sum = findsum(temp, radix);
	int len2 = temp2.size(); long long sum2 = 0;
	int max = 0;
	for (i = 0; i < len2; i++) {
		if (temp2[i] > temp2[max])max = i;
	}
	if (temp2[max] >= 'a' && temp2[max] <= 'z')
		radix = temp2[max] + 10 - 'a';
	else
	{
		radix = temp2[max] - '0';
	}
	if (sum >= 0) {
		while (sum2 < sum && sum2 >= 0) {
			radix++;
			sum2 = 0;
			sum2 = findsum(temp2, radix);
		}
		if (sum2 == sum)cout << radix;
		else
		{
			cout << "Impossible";
		}
	}
	else { cout << "Impossible"; }
	return 0;
}


/*
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
long long toDecimal(std::string a, long long radix) {
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		int exponent = a.size() - 1 - i;
		int underExponent =  isdigit(a[i])? (a[i] - '0') : (a[i] - 'a'+10);
		result += underExponent * pow(radix, exponent);
	}
	return result;
}
int main() {
	const int N = 2;
	std::string a[N];
	bool flag = false;
	int tag;
	long long decimal1, decimal2, testradix = 2,low=0,high, radix;
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::cin >> tag >> radix;
	decimal1 = toDecimal(a[tag - 1], radix);
	char it = *max_element(a[tag%N].begin(), a[tag%N].end());
	low= (isdigit(it) ? (it - '0') : (it - 'a' + 10))+1;
	testradix = low;
	high =std::max(testradix, decimal1)+1;
	while (testradix <= high) {
		decimal2 = toDecimal(a[tag%N], testradix);
		if (decimal1 == decimal2) {
			flag = true;
			break;
		}
		testradix++;
	}
	if (flag)std::cout << testradix;
	else
	{
		std::cout << "Impossible";
	}
	return 0;
}
*/





/*

#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
long long toDecimal(std::string a, long long radix) {
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		int exponent = a.size() - 1 - i;
		int underExponent =  48 <= a[i] &&a[i]<= 57? (a[i] - 48) : (a[i] - 87);
		//if (underExponent >= maxradix)maxradix = underExponent;
		result += underExponent * pow(radix, exponent);
	}
	return result;
}
int main() {
	const int N = 2;
	char b = '0';
	std::string a[N];
	bool flag = false;
	int tag;
	char it=0;
	long long decimal1, decimal2, testradix = 2,maxr=0,maxradix, radix;
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::cin >> tag >> radix;
	decimal1 = toDecimal(a[tag - 1], radix);
	decimal2 = toDecimal(a[tag % N], testradix);
	for (int i = 0; i < a[tag % N].size(); i++) {
		if (it < a[tag % N][i])it = a[tag % N][i];
	}
	maxr = (isdigit(it) ? (it - '0') : (it - 'a' + 10)) + 1;
	testradix = maxr;
	maxradix = std::max(testradix, decimal1) + 1;
	while (testradix <= maxradix) {
		decimal2 = toDecimal(a[tag % N], testradix);
		if (decimal1 == decimal2) {
			flag = true;
			break;
		}
		testradix++;
	}
	if (flag)std::cout << testradix;
	else
	{
		std::cout << "Impossible";
	}
	return 0;
}
*/