//#define _CRT_SECURE_NO_WARNINGS
//#include<unordered_map>
//#include<iostream>
//#include<set>
//using namespace std;
//unordered_map<string, set<int>>mp;
//int main() {
//	int qNum, coureseNum;
//	cin >> qNum >> coureseNum;
//	for (int i = 0; i < coureseNum; i++) {
//		int courese, stuNum;
//		cin >> courese >> stuNum;
//		for (int j = 0; j < stuNum; j++) {
//			string s;
//			cin >> s;
//			mp[s].insert(courese);
//		}
//	}
//	for (int i = 0; i < qNum; i++) {
//		string s;
//		cin >> s;
//		cout << s<<" "<<mp[s].size();
//		for (auto it = mp[s].begin(); it != mp[s].end();it++) {
//			cout << " " << *(it);
//		}
//		cout << endl;
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 1;
set<int> v[maxn];
int getId(char name[]) {
	int id=0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
int main() {
	int qNum, coureNum;
	scanf("%d%d", &qNum, &coureNum);
	for (int i = 0; i < coureNum; i++) {
		int courese, stuNum;
		scanf("%d %d", &courese, &stuNum);
		for (int j = 0; j < stuNum; j++) {
			char name[5];
			scanf("%s", name);
			int id = getId(name);
			v[id].insert(courese);
		}
	}
	for (int i = 0; i < qNum; i++) {
		char name[5];
		scanf("%s", name);
		int id = getId(name);
		printf("%s %d", name, v[id].size());
		for (auto it=v[id].begin(); it != v[id].end(); it++) {
			printf(" %d", *(it));
		}
		printf("\n");
	}
	return 0;
}