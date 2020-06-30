#include<iostream>
#include<iomanip>
const int N = 1002;
struct node {
	int expo;
	float coefficient;
}nod[N];
int main() {
	using namespace std;
	float result[N] = {};
	 int totalCue=0;
	for (int i = 0; i < 2; i++) {
		int cueNum, exponent,lastexpo=-1;
		float coefficient;
		cin >> cueNum;
		totalCue += cueNum;
		for (int j = 0; j < cueNum; j++)
		{
			cin >> exponent >> coefficient;
			result[exponent] += coefficient;
			
		}
	}
	int num = 0;
	for (int i = N-1; i >= 0; i--) {
		if (result[i] != 0) {
			++totalCue;
			nod[num].expo = i;
			nod[num].coefficient = result[i];
			++num;
		}
	}
	cout << num;
	for (int i = 0; i < num; i++) {
		cout << " "<<nod[i].expo;
		cout <<" "<<fixed<<setprecision(1)<< nod[i].coefficient;
	}
	return 0;

}