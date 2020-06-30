//注意点：从低位到高位每三位输出一个逗号
#include<iostream>
#include<string>
int main() {
	int a, b, result;
	std::cin >> a >> b;
	std::string r = std::to_string(a + b);
	int k = r.size();
	for (int i = 0; i < k; i++) {
		std::cout << r[i];
		if (r[i] == '-')continue;
		if ((k-i-1) % 3 == 0 && i < r.size()-1)std::cout << ",";
	}
	return 0;
}





/*

#include<iostream>
#include<string>
const int N= 100;
int r[N];
int main() {
	int a, b,result,len=0;
	std::cin >> a >> b;
	result = a + b;
	if (result < 0) {
		std::cout << "-";
		result = -result;
	}
	if (result == 0)r[len++] = 0;
	while (result) {
		int c = result % 10;
		result = result / 10;
		r[len++] = c;
	}
	int k=0;
	for (int i = len-1; i >= 0; i--) {
		std::cout << r[i];
		if (i% 3 == 0 && i > 0)
			std::cout << ",";
		k++;
	}
	return 0;
}
*/

/*
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int prin(int a) {
	int c = a;
	a = a / 1000;
	if (a  == 0) {
		cout << c;
		return 0;
	}
	prin(a);
	cout << "," <<setfill('0')<<setw(3)<< abs(c % 1000);

}
int main() {
	int a, b;
	cin >> a >> b;
	prin(a + b);
	return 0;
}

*/