#include<iostream>
#include<limits.h>
using namespace std;
const int N = 200002;
int a[N], b[N], len1, len2, k = 0;
int main() {
	cin >> len1;
	for (int i = 0; i < len1; i++) {
		scanf("%d", &a[i]);
	}
	cin >> len2;
	for (int i = 0; i < len2; i++) {
		scanf("%d", &b[i]);
	}
	a[len1] = INT_MAX; b[len2] = INT_MAX;
	int i = 0, j = 0, num = (len1 + len2 - 1) / 2;
	while (k != num) {
		if (a[i] < b[j]) {
			i++;
			k++;
		}
		else {
			j++;
			k++;
		}
	}
	if (a[i] < b[j])cout << a[i];
	else cout << b[j];
	return 0;
}