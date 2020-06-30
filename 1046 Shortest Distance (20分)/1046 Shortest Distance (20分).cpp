#include<iostream>
int main() {
	const int N = 100001;
	int exitNum=0,cueNum=0,allDis=0;
	int distances[N] = {};
	std::cin >> exitNum;
	for (int i = 2; i <= exitNum+1; i++) {
		std::cin >> distances[i];
		distances[i] += distances[i - 1];
	}
	std::cin >> cueNum;
	for (int i = 0; i < cueNum; i++) {
		int start, end,out=0;
		std::cin >> start >> end;
		out = abs(distances[start] - distances[end]);
		if (out < 0.5 * distances[exitNum+1])std::cout << out << std::endl;
		else
		{
			std::cout << distances[exitNum+1] - out << std::endl;
		}
	}
	return 0;
}