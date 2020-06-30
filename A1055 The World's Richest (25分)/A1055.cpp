#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100002;
struct rich {
	char name[10];
	int age;
	int worth;
}r[N];
int cmp(rich a, rich b) {
	int nameCmp = strcmp(a.name, b.name);
	if (a.worth != b.worth)return a.worth > b.worth;
	else if (a.age != b.age)return a.age < b.age;
	else if (nameCmp)return nameCmp < 0;
}
int main() {
	int sampleNum, queNum;
	cin >> sampleNum >> queNum;
	for (int i = 0; i < sampleNum; i++) {
		scanf("%s", r[i].name);
		scanf("%d %d", &r[i].age,&r[i].worth);
	}
	sort(r, r + sampleNum, cmp);
	for (int i = 0; i < queNum; i++) {
		int coutNum, age1, age2,count=0;
		cin >> coutNum >> age1 >> age2;
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < sampleNum; j++) {
			if (r[j].age >= age1 && r[j].age <= age2 && count <coutNum) {
				printf("%s %d %d\n", r[j].name, r[j].age, r[j].worth);
				count++;
			}
		}
		if (count == 0)cout << "None" << endl;
	}
	return 0;
}