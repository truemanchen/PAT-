#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100002;
int ans[N];
int main() {
	int x, count = 0,times=0,flag=0,start=-1,end=-1,n=0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> ans[i];
		if (ans[i] == 0)start = i;
	}
	while (flag == 0) {
		for (int i = 0; i < count; i++) {
			if (ans[i] == start) { 
				end = i; 
				break;
			}
		}
		if (ans[0] != 0) {
			swap(ans[start], ans[end]);
			start = end;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (ans[i] != i) {
					end = i;
					break;
				}
			}
			swap(ans[start], ans[end]);
			start = end;
		}

		for (int i = 0; i < count;i++) {
			if (ans[i] != i) {
				flag =0; 
				break;
			}
			flag = 1;
		}
		n++;
	}
	cout << n;
	return 0;
}