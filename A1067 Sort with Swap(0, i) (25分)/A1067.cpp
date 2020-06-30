#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100002;
int temp,hasht[N];
int main() {
	int count = 0,start=0,n=0,m=0,k=1;
	cin >> count;
	for (int i = 0; i < count; i++) {
		scanf("%d", &temp);
		hasht[temp] = i;
		if (temp != i)m++;
	}
	while (m!=0) {
		if (hasht[0] == 0) {
			while (k < count) {
				if (hasht[k] != k) {
					swap(hasht[0], hasht[k]);
					break;
				}
				k++;
			}
			m++;
			n++;
		}
		while(hasht[0] != 0) {
			start = hasht[0];
			if (hasht[start] == 0)m -= 2;
			else m--;
			swap(hasht[0], hasht[start]);
			n++;
		}
	}
	printf("%d", n);
	return 0;
}