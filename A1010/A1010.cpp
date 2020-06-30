#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
long long toDecimal(std::string a, int radix,long long &maxradix) {
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		int exponent = a.size() - 1 - i;
		long long underExponent =  std::isdigit(a[i])? (a[i] - 48) : (a[i] - 87);
		if (underExponent >= maxradix)maxradix = underExponent;
		result += underExponent * pow(radix, exponent);
	}
	return result;
}
int main() {
	const int N = 2;
	std::string a[N];
	bool flag = false;
	int tag, radix;
	long long decimal1, decimal2, testradix = 0,maxr=0,maxradix;
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::cin >> tag >> radix;
	decimal1 = toDecimal(a[tag - 1], radix, maxr);
	maxr = 0;
	decimal2 = toDecimal(a[tag % N], testradix, maxr);
	maxr = maxr + 1;
	testradix = maxr ;
	maxradix = std::max(testradix, decimal1);
	while (testradix <= maxradix) {
		long long mid = (maxradix + testradix) / 2;
		decimal2 = toDecimal(a[tag%N], mid,maxr);
		if (decimal1 == decimal2) {
			testradix = mid;
			flag = true;
			break;
		}
		else if (decimal2 > decimal1 || decimal2 < 0)maxradix = mid - 1;
		else if (decimal2 < decimal1)testradix = mid + 1;
	}
	if (flag)std::cout << testradix;
	else
	{
		std::cout << "Impossible";
	}
	return 0;
}