#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100001;
struct record{
	int id;
	char name[10];
	int grade;
}r[N];
int recordNum, col;
int cmp(record a, record b) {
	if (col == 1)return a.id < b.id;
	else if (col == 2) {
		int sc = strcmp(a.name, b.name);
		if (sc != 0)
			return sc < 0;
		else
			return a.id < b.id;
	}
	else if (col == 3) {
		if (a.grade != b.grade)
			return a.grade < b.grade;
		else
			return a.id < b.id;
	}
}
int main() {
	cin >> recordNum >> col;
	for (int i = 0; i < recordNum; i++) {
		scanf("%d%s%d", &r[i].id, r[i].name, &r[i].grade);
	}
		sort(r, r + recordNum, cmp);
		for (int i = 0; i < recordNum; i++) {
			printf("%06d %s %d\n", r[i].id, r[i].name, r[i].grade);
		}
	return 0;
}