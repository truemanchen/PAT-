#include<iostream>
using namespace std;
int movep[55], start[55], endp[55];

int main()
{
	char card[5] = { 'S','H','C','D','J' };
	int times;
	cin >> times;
	for (int i = 1; i <= 54; i++) {
		start[i] = i;
	}
	for (int i = 1; i <= 54; i++) {
		cin >> movep[i];
	}
	for (int i = 0; i < times; i++) {
		for (int j = 1; j <= 54; j++) {
			start[j] = movep[start[j]];
		}
	}
	for (int i = 1; i <= 54; i++) {
		endp[start[i]] = i;
	}
	cout << card[endp[1] / 13] << endp[1] % 13;
	for (int i = 2; i <= 54; i++) {
		cout << " " << card[endp[i] / 13] << (endp[i] - 1 % 13) % 13 + 1;
	}
	return 0;
}