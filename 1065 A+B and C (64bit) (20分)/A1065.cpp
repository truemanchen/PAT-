#include<iostream>
int main() {
	using namespace std;

	long long d,e,result;
	d = (2 << 30)-1;


	for (int i = 0; i < d; i++) {
		result = d + i;
		if (result != d + i)cout << "false"<<endl;
	}

	int cueNuM;
	cin >> cueNuM;
	long long a, b, c;
	for (int i = 1; i <= cueNuM; i++) {
		cin >> a >> b >> c;
		if(a>0&&b>0&&a+b<0)printf("Case #%d: true\n", i);
		else if(a < 0 && b < 0 && a + b > 0)printf("Case #%d: false\n", i);
		else if (a+b>c)printf("Case #%d: true\n",i);
		else printf("Case #%d: false\n", i);
		
	}
	return 0;
}