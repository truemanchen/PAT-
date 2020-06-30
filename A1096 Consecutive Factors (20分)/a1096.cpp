#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int count = 0,max=0,o=n,maxfirst;
	int s = (int)sqrt(n * 1.0);
	for (int i = 2; i <= s; i++) {
		o = n;
		count = 0;
		int x = i;
		while (o % x == 0) {
			o = o / x;
			count++;
			x++;
		}
		if (count > max) {
			max = count;
			maxfirst = i;
		}
	}
	if (max == 0)cout << 1 << endl << n;
	else
	{
		cout << max << endl;
		for (int i = 0; i < max; i++) {
			if (i)cout << "*";
			cout << maxfirst;
			maxfirst++;
		}
	}	
	return 0;
}