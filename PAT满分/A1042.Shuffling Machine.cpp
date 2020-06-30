#include<iostream>
int main() {
	int start[55] = {}, end[55] = {}, times = 0,shuffle[55];
	char result[5] = { 'S','H','C','D','J' };
	for (int i = 0; i < 55; i++) {
		start[i] = i;
		end[i] = i;
	}
	std::cin >> times;
	for (int i = 1; i < 55; i++) {
		std::cin >> shuffle[i];
	}
	for (int i = 0; i < times; i++) {
		for (int j = 1; j <= 54; j++) {
			end[shuffle[j]] = start[j];
		}
		for (int j = 1; j <= 54; j++) {
			start[j] = end[j];
		}
	}
	for (int i = 1; i < 54; i++) {
		if (i != 1)std::cout << " ";
		std::cout << result[(end[i] - 1) / 13] << (end[i]-1)%13+1 << " ";
	}
	return 0;
}